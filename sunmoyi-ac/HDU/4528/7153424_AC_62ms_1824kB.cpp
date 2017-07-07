
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 110

using namespace std;
int n, m, t;
char graph[maxn][maxn];
bool vis[maxn][maxn][2][2];
bool look[2][maxn][maxn];
int dir[4][2] = { {1, 0},  {-1, 0},  {0, 1}, {0, -1} };

struct node {
	int x, y;
	int step;
	bool flag1, flag2;
}s, d, e;

bool check(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > m) 
		return false;
	return true;
}

int bfs()
{
	memset(vis, false, sizeof(vis));
	s.flag1 = s.flag2 = false;
	if (look[0][s.x][s.y]) 
		s.flag1 = true;
	if (look[1][s.x][s.y])
		s.flag2 = true;
	queue<node>q;
	vis[s.x][s.y][s.flag1][s.flag2] = true;
	q.push(s);
	while (!q.empty())
	{
		node now = q.front();
		q.pop();
		if (now.flag1&&now.flag2) 
			return now.step;
		if (now.step>t) 
			return -1;
		for (int i = 0; i<4; i++)
		{
			node next = now;
			next.x += dir[i][0];
			next.y += dir[i][1];
			next.step += 1;
			if (!check(next.x, next.y) || graph[next.x][next.y] != '.') 
				continue;
			if (look[0][next.x][next.y])
				next.flag1 = true;
			if (look[1][next.x][next.y])
				next.flag2 = true;
			if (vis[next.x][next.y][next.flag1][next.flag2]) 
				continue; 
			vis[next.x][next.y][next.flag1][next.flag2] = true;
			q.push(next);
		}
	}
	return -1;
}

void deal(int x, int y, bool flag)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x, ny = y;
		while (true)
		{
			nx += dir[i][0], ny += dir[i][1];
			if (!check(nx, ny) || graph[nx][ny] == 'X') break;
			if (graph[nx][ny] == 'E'&&flag == 0) break;
			if (graph[nx][ny] == 'D'&&flag == 1) break;
			look[flag][nx][ny] = true;
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	int time = 1;
	while (T--)
	{
		scanf("%d %d %d", &n, &m, &t);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", graph[i] + 1);
			for (int j = 1; j <= m; j++)
			{
				if (graph[i][j] == 'S')
				{
					s.x = i; s.y = j;
					graph[i][j] = '.'
;
				}
				if (graph[i][j] == 'D')
				{
					d.x = i, d.y = j;
				}
				if (graph[i][j] == 'E')
				{
					e.x = i, e.y = j;
				}
			}
		}
		memset(look, false, sizeof(look));
		deal(d.x, d.y, 0);
		deal(e.x, e.y, 1);
		printf("Case %d:\n%d\n", time++, bfs());
	}
	return 0;
}