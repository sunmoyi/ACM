#include<cstdio>
#include<stack>

int dir[4][2] = { { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, 0 } };
int vis[21][21];
char map[21][21];
int n, m;
int sx, sy, count;


void dfs(int x, int y)
{
	if(x  < 1 || x > m || y < 1 || y > n)
		return;
	if (map[x][y] == '#')
		return;
	if (vis[x][y] == 1)
		return;
	vis[x][y] = 1;
	count++;
	for (int j = 0; j < 4; j++)
	{
		int dx = x + dir[j][0];
		int dy = y + dir[j][1];
		dfs(dx, dy);
	}
}

/*void dfs(int x, int y)
{
	if (x < 1 || x > m || y < 1 || y > n)
		return;
	if (map[x][y] == '#')
		return;
	if (vis[x][y] == 1)
		return;
	vis[x][y] = 1;
	count++;
	for (int i = 0; i < 4; i++)
	{
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		dfs(dx, dy);
	}
}*/
int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && m != 0 || n != 0)
	{
		count = 0; 
		memset(vis, 0, sizeof(vis));
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
		dfs(sx, sy);
		printf("%d\n", count);
	}
	return 0;
}

/*int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && n != 0 || m != 0)
	{
		count = 0;
		memset(vis, 0, sizeof(vis));
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
		dfs(sx, sy);
		printf("%d\n", count);
	}
	return 0;
}*/