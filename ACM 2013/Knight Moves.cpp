#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int dir[8][2] = { { -2, -1 }, { -2, 1 }, { -1, -2 },
	{ -1, 2 }, { 1, -2 }, { 1, 2 }, { 2, -1 }, { 2, 1 } };
int vis[10][10];
int ey, sy, cnt;
char sx, ex;

struct point{
	int x;
	int y;
	int step;
}start, endd;

void bfs(point start)
{
	queue<point>q;
	q.push(start);
	point now, next;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if (now.x == endd.x && now.y == endd.y)
		{
			cnt = now.step;
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			next.step = now.step + 1;
			if (next.x < 1 || next.y < 1 || next.x > 8 || next.y > 8)
				continue;
			if (vis[next.x][next.y] == 1)
				continue;
			if (next.x == endd.x && next.y == endd.y)
			{
				cnt = next.step;
				return;
			}
			vis[next.x][next.y] = 1;
			q.push(next);
		}
	}
}

int main(void)
{
	while (scanf("%c%d %c%d%*c", &sx, &sy, &ex, &ey) != EOF)
	{
		cnt = 0;
		memset(vis, 0, sizeof(vis));

		start.x = sx - 'a' + 1;
		start.y = sy;
		endd.x = ex - 'a' + 1;
		endd.y = ey;
		start.step = 0;
		bfs(start);
		printf("To get from %c%d to %c%d takes %d knight moves.\n", sx, sy, ex, ey, cnt);
	}
}
