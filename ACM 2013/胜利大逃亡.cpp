#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;

#define N 55

int map[N][N][N];
int vis[N][N][N];
int tx[] = { 1, -1, 0, 0, 0, 0 };
int ty[] = { 0, 0, 1, -1, 0, 0 };
int tz[] = { 0, 0, 0, 0, 1, -1 };
int a, b, c, t, ans;

struct node{
	int x;
	int y;
	int z;
	int step;
};


int check(int i, int j, int k)//ÅÐ¶ÏÊÇ·ñ¿ÉÐÐ
{
	if (i<0 || j<0 || k<0 || i >= a || j >= b || k >= c || map[i][j][k])
		return 0;
	return 1;
}

int bfs(int x, int y, int z)
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
		if (p.x == a - 1 && p.y == b - 1 && p.z == c - 1 && p.step <= t)
			return p.step;
		for (i = 0; i < 6; i++)
		{
			q = p;
			q.x += tx[i];
			q.y += ty[i];
			q.z += tz[i];
			if (!vis[q.x][q.y][q.z] && check(q.x, q.y, q.z))
			{
				q.step++;
				vis[q.x][q.y][q.z] = 1;
				if (abs(q.x - a + 1) + abs(q.y - b + 1) + abs(q.z - c + 1) + q.step > t)
					continue;
				Q.push(q);
			}
		}
	}
	return -1;
}

int main()
{
	int cas;
	scanf_s("%d", &cas);
	while (cas--)
	{
		int i, j, k;
		scanf_s("%d%d%d%d", &a, &b, &c, &t);
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		for (i = 0; i<a; i++)
			for (j = 0; j<b; j++)
				for (k = 0; k<c; k++)
					scanf_s("%d", &map[i][j][k]);
		ans = bfs(0, 0, 0);
		printf("%d\n", ans);
	}

	return 0;
}
