#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char map[25][25];
int vis[25][25];
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int n, m, cnt, sx, sy;

void dfs(int x, int y)
{
	if (x < 1 || x > m || y < 1 || y > n)
		return;
	if (map[x][y] == '#')
		return;
	if (vis[x][y] == 1)
		return;
	vis[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		dfs(dx, dy);
	}
}

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		getchar();
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%c", &map[i][j]);
				if (map[i][j] == '@')
				{
					sx = i;
					sy = j;
				}
			}
			getchar();
		}
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		dfs(sx, sy);
		printf("%d\n", cnt);
	}
	return 0;
}