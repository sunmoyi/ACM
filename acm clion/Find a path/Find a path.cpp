//
// Created by 孙启龙 on 2017/7/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 35
#define maxm 1801
#define INF 0x3f3f3f3f

using namespace std;

int t, n, m;
int dp[maxn][maxn][maxm], map[maxn][maxn];
int ans;

void DP()
{
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][map[0][0]] = map[0][0] * map[0][0];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i >= 1)
                for(int k = map[i][j]; k < maxm; k++)
                    if(dp[i - 1][j][k - map[i][j]] != INF)
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - map[i][j]] + map[i][j] * map[i][j]);
            if(j >= 1)
                for(int k = map[i][j]; k < maxm; k++)
                    if(dp[i][j - 1][k - map[i][j]] != INF)
                        dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k - map[i][j]] + map[i][j] * map[i][j]);
        }
    }
}

int main (void)
{
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &map[i][j]);
        DP();

        ans = INF;
        for(int i = 0; i < maxm; i++)
            if(dp[n - 1][m - 1][i] != INF)
                ans = min(ans, (n + m - 1) * dp[n - 1][m - 1][i] - i * i);
        printf("Case #%d: %d\n", Case, ans);
    }
}