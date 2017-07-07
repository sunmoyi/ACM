/*DFS版*/
#include<stdio.h>  
#include<string.h>  
#define max 205  
char map[max][max];
long a[100000], step, sum, n, m, visited[max][max];
long directions[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
// 此函数基本思想：
// 1.让天使上下左右随便走但是墙和重复的道路排除
// 2.dierctions纪录方向 有for循环代表所有方向
// 3.visited数组来标记走过的路
// 4.在dfs全部循环完毕之后 一步步返回的时候必须清空 2， 3 两步的所有标记


void DFS(int x, int y)
{
	int i, mx, my;
	if (map[x][y] == 'r')
		a[sum++] = step;
	else if (map[x][y] != '#')
	{
		for (i = 0; i < 4; i++)
		{
			mx = x + directions[i][0];
			my = y + directions[i][1];
			if (map[mx][my] != '#'&&mx >= 1 && mx <= n&&my >= 1 && my <= m&&!visited[mx][my])
			{
				if (map[x][y] == 'x')
					step++;
				step++;
				visited[mx][my] = 1;

				DFS(mx, my);

				visited[mx][my] = 0;
				step--;
				if (map[x][y] == 'x')
					step--;
			}
		}
	}
}

int main()
{
	long i, j, x, y, min;
	while (scanf_s("%ld%ld", &n, &m) > 0)
	{
		memset(visited, 0, sizeof(visited));
		sum = 0;
		step = 0;
		min = max;
		for (i = 1; i <= n; i++)
		{
			getchar();
			for (j = 1; j <= m; j++)
			{
				scanf_s("%c", &map[i][j]);
				if (map[i][j] == 'a')
				{
					x = i;
					y = j;
				}
			}
		}
		visited[x][y] = 1;
		DFS(x, y);
		if (sum == 0)
			printf("Poor ANGEL has to stay in the prison all his life.\n");
		else
		{
			for (i = 0; i < sum; i++)
				if (a[i] < min)
					min = a[i];
			printf("%ld\n", min);
		}
	}
	return 0;
}

/*bfs版*//*
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
char map[205][205];
int vis[205][205];
int n, m, flag, sum, ex, ey, ez, minn;

struct node{
	int x;
	int y;
	int count;
};

node q;

void bfs(node p)
{
	node s, t;
	queue<node>a;
	a.push(p);
	while (!a.empty())
	{
		s = a.front();
		a.pop;
		if (s.x < 1 || s.x > n || s.y < 1 || s.y  > m)
			continue;
		if (map[s.x][s.y] == '#')
			continue;
		if (map[s.x][s.y] == 'r')
		{
			minn = s.count;
			flag = 1;
			return;
		}
		if (vis[s.x][s.y] == 1)
			continue;
		vis[s.x][s.y] = 1;
		for (int i = 0; i < 4; i++)
		{
			t.x = s.x + dir[i][0];
			t.y = s.y + dir[i][1];
			if (map[t.x][t.y] == 'x')
				t.count = s.count + 2;
			else
				t.count = s.count + 1;
			bfs(t);
		}
	}
}
int main(void)
{
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		getchar();
		flag = 0;
		minn = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf_s("%c", &map[i][j]);
				if (map[i][j] == 'a')
				{
					q.x = i;
					q.y = j;
				}
				if (map[i][j] == 'r')
				{
					ex = i;
					ey = j;
				}
			}
			getchar();
		}
		vis[q.x][q.y] = 1;
		q.count = 0;
		bfs(q);
		if (flag == 0)
			printf("Poor ANGEL has to stay in the prison all his life.\n");
		else
			printf("%d", minn);
	}
	return 0;
}*/