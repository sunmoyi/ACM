#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
bool vis[25][25];
char map[25][25];
int n, m, a, b;
int ans;

void dfs(int x, int y)
{
	ans++;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (xx < 1 || xx > m || yy < 1 || yy > n)
			continue;
		if (vis[xx][yy])
			continue;
		if (map[xx][yy] != '.')
			continue;
		vis[xx][yy] = true;
		dfs(xx, yy);
	}
	return;
}

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		memset(vis, 0, sizeof(vis));
		ans = 0;
		getchar();
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%c", &map[i][j]);
				if (map[i][j] == '@')
				{
					a = i;
					b = j;
				}
			}
			getchar();
		}
		vis[a][b] = true;
		dfs(a, b);
		printf("%d\n", ans);
	}
	return 0;
}