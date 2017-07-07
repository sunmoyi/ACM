#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct node{
	int x;
	int y;
	int z;
	int step;
}start, endd;
int dir[6][3] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 } };
char map[35][35][35];
bool vis[35][35][35];
int n, m, t;

int bfs(node a)
{
	queue<node>Q;
	Q.push(a);
	while (!Q.empty())
	{
		node s = Q.front();
		Q.pop();
		if (s.x == endd.x && s.y == endd.y && s.z == endd.z)
			return s.step;
		for (int i = 0; i < 6; i++)
		{
			node ss;
			ss.x = s.x + dir[i][0];
			ss.y = s.y + dir[i][1];
			ss.z = s.z + dir[i][2];
			ss.step = s.step + 1;
			if (ss.x < 1 || ss.y < 1 || ss.z < 1)
				continue;
			if (ss.x > t || ss.y > n || ss.z > m)
				continue;
			if (vis[ss.x][ss.y][ss.z])
				continue;
			if (map[ss.x][ss.y][ss.z] == '#')
				continue;
			vis[ss.x][ss.y][ss.z] = true;
			Q.push(ss);
		}
	}
	return -1;
}

int main(void)
{
	while (scanf("%d %d %d", &t, &n, &m) != EOF && (t + n + m))
	{
		getchar();
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= t; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= m; k++)
				{
					scanf("%c", &map[i][j][k]);
					if (map[i][j][k] == 'S')
					{
						start.x = i;
						start.y = j;
						start.z = k;
						start.step = 0;
					}
					else if (map[i][j][k] == 'E')
					{
						endd.x = i;
						endd.y = j;
						endd.z = k;
						endd.step = 0;
					}
				}
				getchar();
			}
			if (i != t)
			getchar();
		}
		int ans = bfs(start);
		if (ans == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", ans);
	}
	return 0;
}