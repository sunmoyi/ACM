//
// Created by 孙启龙 on 2017/4/29.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 3000010

using namespace std;

int N, K, Q;
int ans[maxn];
int turn[maxn];
int dp[maxn];
int a[maxn];

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &N, &K, &Q);
        int tt = N;
        int tot = 0;
        turn[0] = 0;
        while(tt)
        {
            ++tot;
            turn[tot] = turn[tot - 1] + (tt - 1) / K + 1;
            tt = tt - 1 - (tt - 1) / K;
        }

        for(int i = 0; i < N; i++)
        {
            dp[i] = i % K? dp[i - i/K - 1] + 1: 0;
            a[i] = i % K? a[i - i/K - 1]: i/K + 1;
        }
        for(int i = 0; i < N; i++)
        {
            int temp = turn[dp[i]] + a[i];
            ans[temp] = i + 1;
        }

        for(int i = 0; i < Q; i++)
        {
            int a;
            scanf("%d", &a);
            printf("%d\n", ans[a]);
        }
    }
    return 0;
}