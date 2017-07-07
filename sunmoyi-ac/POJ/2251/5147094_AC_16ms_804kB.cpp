#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

char map[35][35][35];
int vis[35][35][35];
int  mf, mx, my;
struct node{
	int f;
	int x;
	int y;
	int step;
};
node start, endd;
int dir[6][3] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 } };

void biaoji(node a)
{
	vis[a.f][a.y][a.x] = 1;
	return;
}

bool cheak(node a)
{
	if (a.f < 1 || a.x < 1 || a.y < 1 || a.f > mf || a.x > mx || a.y > my)
		return false;
	if (vis[a.f][a.y][a.x])
		return false;
	if (map[a.f][a.y][a.x] == '#')
		return false;
	return true;
}

int BFS(node start)
{
	queue<node>q;
	q.push(start);
	node now, next;
	biaoji(start);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if (now.f == endd.f && now.x == endd.x && now.y == endd.y)
			return now.step;
		for (int i = 0; i < 6; i++)
		{
			next.f = now.f + dir[i][0];
			next.x = now.x + dir[i][1];
			next.y = now.y + dir[i][2];
			next.step = now.step + 1;
			if (cheak(next))
			{
				biaoji(next);
				q.push(next);
			}
		}
	}
	return -1;
}

int main(void)
{
	while (scanf("%d %d %d", &mf, &my, &mx) != EOF && (my + mf + mx))
	{
		getchar();
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= mf; i++)
		{
			for (int j = 1; j <= my; j++)
			{
				for (int k = 1; k <= mx; k++)
				{
					scanf("%c", &map[i][j][k]);
					if (map[i][j][k] == 'S')
					{
						start.f = i;
						start.y = j;
						start.x = k;
						start.step = 0;
					}
					if (map[i][j][k] == 'E')
					{
						endd.f = i;
						endd.y = j;
						endd.x = k;
					}
				}
				getchar();
			}
			getchar();
		}
		int ans = BFS(start);
		if (ans > 0)
			printf("Escaped in %d minute(s).\n", ans);
		else
			printf("Trapped!\n");
	}
	return 0;
}