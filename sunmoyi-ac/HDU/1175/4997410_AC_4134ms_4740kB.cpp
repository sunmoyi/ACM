#include<iostream>
using namespace std;
int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
int map[1005][1005];
bool vis[1005][1005];
int sx, sy, ex, ey, n, m;
bool flag;
void dfs(int i, int j, int d, int ans)
{
	if (flag) 
		return;
	if (i == ex && j == ey && ans <= 2) 
	{ 
		flag = 1; 
		return; 
	}
	if (ans>2) 
		return;
	for (int k = 0; k<4; k++)
	{
		int x = i + dir[k][0];
		int y = j + dir[k][1];
		if (!vis[x][y] && x > 0 && x <= n && y > 0 && y <= m)
		{
			if (map[x][y] == 0)
			{
				vis[x][y] = 1;
				if (d == k) 
					dfs(x, y, k, ans);
				else  
					dfs(x, y, k, ans + 1);
				vis[x][y] = 0;
			}
			else if (x == ex&&y == ey)
			{
				if (d == k) 
					dfs(x, y, k, ans);
				else 
					dfs(x, y, k, ans + 1);
			}
		}
	}
	return;
}
int main(void)
{
	int N, d, h;
	int w = 1;
	while (scanf_s("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0) 
			break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf_s("%d", &map[i][j]);
		memset(vis, 0, sizeof(vis));
		scanf_s("%d", &N);
		while (N--)
		{
			scanf_s("%d%d%d%d", &sx, &sy, &ex, &ey);
			h = 0; flag = 0;
			if (map[sx][sy] != map[ex][ey]) 
			{ 
				printf("NO\n"); 
				continue; 
			}
			else if (map[sx][sy] == 0 || map[ex][ey] == 0) 
			{ 
				printf("NO\n"); 
				continue; 
			}
			else
			{
				for (d = 0; d<4; d++)
				{
					int x = sx + dir[d][0];
					int y = sy + dir[d][1];
					if (x == ex&&y == ey)  
					{ 
						h = 1; 
						printf("YES\n"); 
						break; 
					}
					if (map[x][y] == 0 && x >= 1 && x <= n&&y >= 1 && y <= m)
					{
						dfs(x, y, d, 0);
						if (flag)
						{
							h = 1;
							printf("YES\n");
							break;
						}
					}
				}
				if (!h) printf("NO\n");
			}
		}
	}
	return 0;
}
