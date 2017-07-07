#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int c, g, C[25], G[25];
int dp[25][20010];

int main(void)
{
	while (scanf("%d %d", &c, &g) != EOF)
	{
		for (int i = 1; i <= c; i++)
			scanf("%d", &C[i]);
		for (int i = 1; i <= g; i++)
			scanf("%d", &G[i]);

		memset(dp, 0, sizeof(dp));
		dp[0][10000] = 1;

		for (int i = 1; i <= g; i++)
		{
			for (int j = 0; j <= 20000; j++)
			{
				for (int k = 1; k <= c; k++)
				{
					if (j >= C[k] * G[i])
						dp[i][j] += dp[i - 1][j - C[k] * G[i]];
				}
			}
		}
		printf("%d\n", dp[g][10000]);
	}
	return 0;
}