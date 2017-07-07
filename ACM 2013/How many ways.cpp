#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, n, m;
int map[105][105];
int dp[105][105];

int dfs(int x, int y)
{
	if (dp[x][y] >= 0)
		return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i <= map[x][y]; i++)
	{
		for (int j = 0; j <= map[x][y] - i; j++)
		{
			if (x == 0 && y == 0)
				continue;
			if (i + x <= n && i + x >= 1 && j + y <= m && j + y >= 1)
				dp[x][y] = (dp[x][y] + dfs(i + x, j + y)) % 10000;
		}
	}
	return dp[x][y];
}

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d", &n, &m);
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					scanf_s("%d", &map[i][j]);
			memset(dp, -1, sizeof(dp));
			dp[n][m] = 1;

			printf("%d\n", dfs(1, 1));
		}
	}
	return 0;
}