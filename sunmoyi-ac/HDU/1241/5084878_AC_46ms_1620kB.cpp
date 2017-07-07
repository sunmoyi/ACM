#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char map[105][105];
int vis[105][105];
int n, m, cnt;

void dfs(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > m)
		return;
	if (map[x][y] == '*')
		return;
	if (vis[x][y] == 1)
		return;
	vis[x][y] = 1;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (j == 0 && i == 0)
				continue;
			int dx = x + i;
			int dy = y + j;
			dfs(dx, dy);
		}
	}
}

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		getchar();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &map[i][j]);
			}
			getchar();
		}
		cnt = 0; 
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (vis[i][j] == 0 && map[i][j] == '@')
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}