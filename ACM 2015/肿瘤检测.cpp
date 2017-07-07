#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int map[110][110];
int area, len;
int xx, yy;
int dir[4][2] = { {-1, 0}, {1, 0},  {0, 1}, {0, -1} };
bool vis[110][110];

void dfs(int x, int y)
{
	bool flag = true;
	area++;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (vis[xx][yy])
			continue;
		if (xx <= 0 || xx > n || yy <= 0 || yy > n)
		{
			flag = false;
			continue;
		}
		if (map[xx][yy] <= 50)
			dfs(xx, yy);
		else
			flag = false;
	}
	if (!flag)
		len++;
}

int main(void)
{
	memset(vis, false, sizeof(vis));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] <= 50)
			{
				xx = i;
				yy = j;
			}
		}
	}
	area = len = 0;
	dfs(xx, yy);
	printf("%d %d\n", area, len);
	return 0;
}