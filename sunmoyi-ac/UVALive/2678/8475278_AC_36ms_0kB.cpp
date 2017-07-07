//
// Created by 孙启龙 on 2017/3/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int A[maxn], B[maxn];

int main (void)
{
    int n, S;
    while(scanf("%d %d", &n, &S) == 2 && n)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        B[0] = 0;
        for(int i = 1; i <= n; i++)
            B[i] = B[i - 1] + A[i];

        int ans = n + 1;
        int i = 1;
        for(int j = 1; j <= n; j++)
        {
            if(B[i - 1] > B[j] - S)
                continue;
            while(B[i] < B[j] - S)
                i++;
            ans = min(ans, j - i + 1);
        }
        printf("%d\n", ans == n + 1? 0: ans);
    }
    return 0;
}