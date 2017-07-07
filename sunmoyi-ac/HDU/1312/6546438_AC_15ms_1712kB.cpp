#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char map[25][25];
int sx, sy;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int summ;
int n, m;
bool vis[25][25];

void dfs(int x, int y)
{
	summ++;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (vis[xx][yy])
			continue;
		if (xx <= 0 || xx > n || y <= 0 || y > m)
			continue;
		if(map[xx][yy] == '.')
			dfs(xx, yy);
	}
}

int main(void)
{
	while (scanf("%d %d", &m, &n) != EOF && (n + m))
	{
		memset(map, 0, sizeof(map));
		memset(vis, false, sizeof(vis));
		sx = sy = summ = 0;
		for (int i = 1; i <= n; i++)
		{
			getchar();
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &map[i][j]);
				if (map[i][j] == '@')
				{
					sx = i;
					sy = j;
				}
			}
		}

		
		summ = 0;
		dfs(sx, sy);
		printf("%d\n", summ);
	}
	return 0;
}