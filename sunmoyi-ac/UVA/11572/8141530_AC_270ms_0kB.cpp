//
// Created by 孙启龙 on 2017/2/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define maxn 1000010

using namespace std;

int A[maxn];

int main (void)
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        set<int>s;
        int L = 0, R = 0, ans = 0;
        while(R < n)
        {
            while(R < n && !s.count(A[R]))
                s.insert(A[R++]);
            ans = max(ans, R - L);
            s.erase(A[L++]);
        }
        printf("%d\n", ans);
    }
    return 0;
}