#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct l{
	int x, y, f;
	int step;
};
int n, m, t;
char map[2][1][11];
int vis[2][11][11];
int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int flag;

void bfs()
{
	l now, next;
	queue<l>q;
	now.x = now.y = now.f = now.step = 0;
	q.push(now);
	vis[0][0][0] = 1;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if (map[now.f][now.x][now.y] == 'P' && now.step <= t)
		{
			flag = 1;
			return;
		}
		if (map[now.f][now.x][now.y] == 'P')
		{
			return;
		}
		for (int i = 0; i < 3; i++)
		{
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			next.f = now.f;
			int xx = next.x;
			int yy = next.y;
			int ff = next.f;
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (map[ff][xx][yy] == '*')
				continue;
			if (map[ff][xx][yy] == '#' && map[ff ^ 1][xx][yy] == '#')
				continue;
			if (map[ff][xx][yy] == '#' && map[ff ^ 1][xx][yy] == '*')
				continue;
			if (!vis[ff][xx][yy] && map[ff][xx][yy] == '#' && !vis[ff ^ 1][xx][yy])
			{
				vis[ff][xx][yy] == 1;
				next.f ^= 1;
				vis[next.f][next.x][next.y] = 1;
				next.step = now.step + 1;
				q.push(next);
			}
			if (!vis[ff][xx][yy] && map[ff][xx][yy] != '#')
			{
				vis[ff][xx][yy] = 1;
				next.step = now.step + 1;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	int c;
	scanf("%d", &c);
	while (c--)
	{
		memset(vis, 0, sizeof(vis));
		flag = 0;
		scanf("%d%d%*c", &n, &m, &t);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
				scanf("%s", map[i][j]);
			getchar();
		}
		bfs();
		if (flag)
			printf("YES\n");
		else
			printf("NO]n");
	}
	return 0;
}