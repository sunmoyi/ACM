//
// Created by 孙启龙 on 2017/4/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10505
#define maxm 505

using namespace std;

long long dp[maxn][maxm];
int n, m;
int num[maxn];

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &num[i]);

        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n + 1; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(j == 0)
                {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + num[i]);
                    dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
                }
                else
                {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + num[i]);
                    dp[i + j][0] = max(dp[i + j][0], dp[i][j]);
                }
                //printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
            }
        }
        printf("%lld\n", dp[n + 1][0]);
    }
    return 0;
}