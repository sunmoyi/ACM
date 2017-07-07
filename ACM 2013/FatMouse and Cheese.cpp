#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, map[105][105];
int dp[105][105];
int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };

int dfs(int x, int y)
{
	int maxx = 0, xx, yy, ans = 0;

	if (!dp[x][y])
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				xx = x + dir[j][0] * i;
				yy = y + dir[j][1] * i;
				if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && map[xx][yy] > map[x][y])
				{
					ans = dfs(xx, yy);
					if (ans > maxx)
						maxx = ans;
				}
			}
		}
		dp[x][y] = maxx + map[x][y];
	}
	return dp[x][y];
}

int main(void)
{
	while (scanf_s("%d %d", &n, &m) != EOF && (n + m) != -2)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf_s("%d", &map[i][j]);
			}
		}
		memset(dp, 0, sizeof(dp));

		int t = dfs(1, 1);

		printf("%d\n", t);
	}
}
