#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int vis[210][210];
int x, y;
char map[210][210];
int n, m, t;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

struct node {
	int x, y, t, time;
	node(int xx = 0, int yy = 0, int tt = 0, int timee = 0) :x(xx), y(yy), t(tt), time(timee) {}
};

int bfs(int tt)
{
	queue<node>Q;
	Q.push(node(x, y, tt, 0));
	vis[x][y] = tt;
	while (!Q.empty())
	{
		node now = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = now.x + dir[i][0];
			int yy = now.y + dir[i][1];
			if (xx <= 0 || xx > n || yy <= 0 || yy > m)
				continue;
			if (now.t <= vis[xx][yy])
				continue;
			if (map[xx][yy] == '#' && now.t > 0)
			{
				Q.push(node(xx, yy, now.t - 1, now.time + 1));
				vis[xx][yy] = now.t - 1;
			}
			if (map[xx][yy] == '*')
			{
				Q.push(node(xx, yy, now.t, now.time + 1));
				vis[xx][yy] = now.t;
			}
			if (map[xx][yy] == '+')
				return now.time + 1;
		}
	}
	return -1;
}

int main(void)
{
	while (scanf("%d %d %d", &n, &m, &t) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			getchar();
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &map[i][j]);
				vis[i][j] = -1;
				if (map[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		int ans = bfs(t);
		printf("%d\n", ans);
	}
	return 0;
}