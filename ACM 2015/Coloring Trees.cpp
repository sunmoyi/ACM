#include <cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int nmax = 110;

int cost[nmax][nmax];
int color[nmax];
long long dp[nmax][nmax][nmax];

int main()
{

	int n, m, K;
	scanf("%d %d %d", &n, &m, &K);

	for (int i = 1; i <= n; i++) 
		scanf("%d", color + i);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &cost[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= n; k++)
				dp[i][j][k] = (1LL << 62);

	for (int i = 1; i <= n; i++)
	{
		if (color[i] == 0)
		{
			for (int give = 1; give <= m; give++)
				for (int k = 1; k <= i; k++)
				{
					for (int from = 1; from <= m; from++)
						dp[i][give][k] = min(dp[i][give][k], dp[i - 1][from][k - (from != give)] + cost[i][give]);
				}
		}
		else
		{
			for (int k = 1; k <= i; k++)
			{
				for (int from = 1; from <= m; from++)
					dp[i][color[i]][k] = min(dp[i][color[i]][k], dp[i - 1][from][k - (from != color[i])]);
			}
		}
	}

	long long answer = (1LL << 62);
	for (int lastcolor = 1; lastcolor <= m; lastcolor++)
		answer = min(answer, dp[n][lastcolor][K]);

	if (answer == (1LL << 62))
	{
		puts("-1");
		return 0;
	}

	printf("%I64d\n", answer);

	return 0;
}