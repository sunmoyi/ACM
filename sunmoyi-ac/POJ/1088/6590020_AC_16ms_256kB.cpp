#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int vis[105][105];
int n, m;
int map[105][105];
int f[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int dfs(int x, int y)
{
	if (vis[x][y] != -1)
	{
		return vis[x][y];
	}
	int i;
	int sum = 1;
	for (int i = 0; i < 4; i++)
	{
		int s = x + f[i][0];
		int t = y + f[i][1];
		if (s < 0 || t < 0 || s >= m || t >= n)
			continue;
		if (map[s][t] >= map[x][y])
			continue;
		sum = max(sum, dfs(s, t) + 1);
	}
	return vis[x][y] = sum;
}

int main(void)
{
	while (scanf("%d %d", &m, &n) != EOF)
	{
		int summ = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		memset(vis, -1, sizeof(vis));

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				summ = max(summ, dfs(i, j));
			}
		}
		printf("%d\n", summ);
	}
	return 0;
}