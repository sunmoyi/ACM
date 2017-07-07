#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, n, v;
int N[1005], V[1005];
int dp[1005][1005];

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans --)
		{
			scanf_s("%d %d", &n, &v);
			for (int i = 1; i <= n; i++)
			{
				scanf_s("%d", &N[i]);
			}
			for (int i = 1; i <= n; i++)
			{
				scanf_s("%d", &V[i]);
			}
			memset(dp, 0, sizeof(dp));

			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j <= v; j++)
				{
					if (j >= V[i])
						dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - V[i]] + N[i]);
					else
						dp[i][j] = dp[i - 1][j];
				}
			}
			printf("%d\n", dp[n][v]);
		}
	}
	return 0;
}