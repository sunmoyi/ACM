#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF (long long)1 << 62

using namespace std;

int cost[maxn][maxn];
int color[maxn];
long long dp[maxn][maxn][maxn];
int n, m, k;

int main(void)
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", color + i);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &cost[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= n; k++)
				dp[i][j][k] = INF;

	for (int i = 1; i <= n; i++)
	{
		if(color[i] == 0)
		{
			for (int give = 1; give <= m; give++)
			{
				for (int k = 1; k <= i; k++)
				{
					for (int from = 1; from <= m; from++)
					{
						dp[i][give][k] = min(dp[i][give][k], dp[i - 1][from][k - (from != give)] + cost[i][give]);
					}
				}
			}
		}
		else
		{
			for (int k = 1; k <= i; k++)
			{
				for (int from = 1; from <= m; from++)
				{
					dp[i][color[i]][k] = min(dp[i][color[i]][k], dp[i - 1][from][k - (color[i] != from)]);
				}
			}
		}
	}

	long long ans = INF;
	for (int i = 1; i <= m; i++)
		ans = min(ans, dp[n][i][k]);
	if (ans == INF)
		printf("-1\n");
	else
		printf("%lld\n", ans);
}