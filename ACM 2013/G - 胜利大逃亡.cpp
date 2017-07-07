#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

#define N 55

int map[N][N][N];
int vis[N][N][N];
int dir[6][3] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 },
					{ 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 } };
int a, b, c, t, ans;
struct node{
	int x;
	int y;
	int z;
	int step;
};

bool check(node d)
{
	if (d.x < 0 || d.y < 0 || d.z < 0 ||
		d.x >= a || d.y >= b || d.z >= c ||
		map[d.x][d.y][d.z] || vis[d.x][d.y][d.z])
		return false;
	return true;
}

int BFS(int x, int y, int z)
{
	int i;
	queue<node> Q;
	node q, p;
	p.x = x;
	p.y = y;
	p.z = z;
	p.step = 0;
	vis[x][y][z] = 1;
	Q.push(p);
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if (p.x == a - 1 && p.y == b - 1 && p.z == c - 1
			&& p.step <= t)
			return p.step;
		for (i = 0; i < 6; i++)
		{
			q = p;
			q.x += dir[i][0];
			q.y += dir[i][1];
			q.z += dir[i][2];
			if (check(q))
			{
				q.step++;
				vis[q.x][q.y][q.z] = 1;
				if (abs(q.x - a + 1) + abs(q.y - b + 1) +
					abs(q.z - c + 1) + q.step > t)
					continue;
				Q.push(q);
			}
		}
	}
	return -1;
}

int main(void)
{
	int cnt;
	while (scanf("%d", &cnt) != EOF)
	{
		while (cnt--)
		{
			memset(map, 0, sizeof(map));
			memset(vis, 0, sizeof(vis));
			scanf("%d %d %d %d", &a, &b, &c, &t);
			for (int i = 0; i < a; i++)
				for (int j = 0; j < b; j++)
					for (int k = 0; k < c; k++)
						scanf("%d", &map[i][j][k]);
			ans = BFS(0, 0, 0);
			printf("%d\n", ans);
		}
	}
	return 0;
}
