#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int map[10][10], time[10][10], step[10][10];

int n, m, sx, sy, dx, dy, minx;

void dfs(int x, int y, int len, int cnt)
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return;
	if (len <= 0 || cnt >= minx)
		return;
	if (map[x][y] == 0)
		return;
	if (map[x][y] == 3)
	{
		if (cnt < minx)
			minx = cnt;
		return;
	}	
	if (map[x][y] == 4)
		len = 6;
	if (cnt >= step[x][y] && time[x][y] >= len)
		return;
	step[x][y] = cnt;
	time[x][y] = len;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		dfs(tx, ty, len - 1, cnt + 1);
	}
}


int main(void)
{
	int i, j, l, len, cnt, t;
	while (scanf_s("%d", &t) != EOF)
	{
		for (l = 1; l <= t; l++)
		{
			scanf_s("%d %d", &n, &m);
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					scanf_s("%d", &map[i][j]);
					time[i][j] = 0;
					step[i][j] = INT_MAX - 1;
					if (map[i][j] == 2)
					{
						sx = i;
						sy = j;
					}
					if (map[i][j] == 3)
					{
						dx = i;
						dy = j;
					}
				}
			}
			len = 6;
			cnt = 0;
			minx = INT_MAX;
			dfs(sx, sy, len, cnt);
			if (minx == INT_MAX)
				printf("-1\n");
			else
				printf("%d\n", minx);
		}
	}
	return 0;
}