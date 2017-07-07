#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int vis[210][210];//0 ---power  1-----time
int x, y;
char map[210][210];
int n, m, t;
int dir[4][2] = { {-1, 0}, {1,0},{0, 1 }, {0, -1} };

struct node {
	int x, y, t, time;
	node(int xx = 0, int yy = 0, int tt = 0, int timee = 0) :x(xx), y(yy), t(tt), time(timee){}
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
		if (map[now.x][now.y] == '+')
			return now.time;
		for (int i = 0; i < 4; i++)
		{
			int nx = now.x + dir[i][0];
			int ny = now.y + dir[i][1];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m && now.t > vis[nx][ny])
			{
				if (map[nx][ny] == '#' && now.t > 0)
				{
					Q.push(node(nx, ny, now.t - 1, now.time + 1));
					vis[nx][ny] = now.t - 1;
				}
				else if (map[nx][ny] == '*'|| map[nx][ny] == '+')
				{
					Q.push(node(nx, ny, now.t, now.time + 1));
					vis[nx][ny] = now.t;
				}
			}
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