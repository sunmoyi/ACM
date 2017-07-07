//
// Created by 孙启龙 on 2017/2/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define  maxn 4010

using namespace std;

int n, c, A[maxn], B[maxn], C[maxn], D[maxn], sums[maxn * maxn];

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
        c = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                sums[c++] = A[i] + B[j];
        sort(sums, sums + c);
        long long cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cnt += upper_bound(sums, sums + c, -C[i] - D[j]) -
                       lower_bound(sums, sums + c, -C[i] - D[j]);
        printf("%lld\n", cnt);
        if(T)
            printf("\n");
    }
    return 0;
}