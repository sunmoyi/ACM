#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char map[12][12];
int vis[12][12];
int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int n, m, sx, sy, cnt, flag;

void dfs(int x, int y, int dis)
{
	int haha = 0;
	if (flag == 1)
		return;
	if (vis[x][y] == 100)
	{
		flag = 1;
		return;
	}
	if (!vis[x][y])
		cnt++;
	vis[x][y]++;
	int dx, dy, ddis;
	while (1)
	{
		dx = x + dir[dis][0];
		dy = y + dir[dis][1];
		ddis = dis;
		if (dx < 1 || dy < 1 || dx > n || dy > m || map[dx][dy] == '*')
		{
			if (haha > 8)
			{
				flag = 1;
				break;
			}
			dis = (dis + 1) % 4;
			haha++;
		}
		else
			break;
	}
	dfs(dx, dy, ddis);
}

int main(void)
{
	char s;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		cnt = 0; 
		flag = 0;
		getchar();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &map[i][j]);
				if (map[i][j] != '.' && map[i][j] != '*')
				{
					s = map[i][j];
					sx = i;
					sy = j;
				}
			}
			getchar();
		}
		if (n == 1 && m == 1)
		{
			printf("1\n");
			continue;
		}
		if (s == 'D')
			dfs(sx, sy, 1);
		else if (s == 'U')
			dfs(sx, sy, 3);
		else if (s == 'L')
			dfs(sx, sy, 2);
		else
			dfs(sx, sy, 0);
		printf("%d\n", cnt);
	}
	return 0;
}