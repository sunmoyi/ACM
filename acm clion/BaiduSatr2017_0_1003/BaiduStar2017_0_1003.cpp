//
// Created by 孙启龙 on 2017/8/5.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define maxm 3010
#define maxx 11

using namespace std;

long long dp[maxm][maxx];
int n, m, x;
int a[maxn], b[maxn], k[maxm], p[maxm];
int maxdefence;
int maxpower;

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        maxdefence = 0, maxpower = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &a[i], &b[i]), maxdefence < b[i] ? maxdefence = b[i]: maxdefence;
        for(int i = 1; i <= m; i++)
            scanf("%d %d", &k[i], &p[i]), maxpower < p[i] ? maxpower = p[i]: maxpower;


        if(maxpower <= maxdefence)
        {
            printf("-1\n");
            continue;
        }

        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i <= maxdefence; i++)
            dp[0][i] = 0;
        for (int defence = 0; defence <= maxdefence; defence++)
        {
            for (int i = 1; i <= m; i++)
            {
                x = p[i] - defence;
                if(x <= 0)
                    continue;
                for (int j = x; j < maxm; j++)
                    dp[j][defence] = min(dp[j - x][defence] + k[i], dp[j][defence]);
            }
        }

        for(int defence = 0; defence <= maxdefence; defence++)
            for(int j = maxm - 2; j >= 0; j--)
                dp[j][defence] = min(dp[j][defence], dp[j + 1][defence]);

        long long ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans += dp[a[i]][b[i]];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}