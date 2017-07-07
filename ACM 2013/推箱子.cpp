#include<stdio.h> 
#include<queue> 
#include<algorithm> 

using namespace std;

struct Node
{
	int x, y;
	int bx, by;
	int num;
	bool friend operator < (const Node &a, const Node &b)
	{
		return a.num > b.num;
	}//优先队列 
} star;

int map[9][9];
bool mark[9][9][9][9];//用人跟箱子的位置标记状态 
int dis[4][2] = { 1, 0, 0, -1, -1, 0, 0, 1 };
int n, m, ans;


void input()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 4)
			{
				star.x = i;
				star.y = j;
				map[i][j] = 0;
			}
			if (map[i][j] == 2)
			{
				star.bx = i;
				star.by = j;
				map[i][j] = 0;
			}
		}
	}
}
//输入地图，找到人跟位置的点。 

int BFS()
{
	int i, x, y, num, xx, yy;
	Node now, next;
	priority_queue<Node> Q;

	Q.push(star);

	mark[star.x][star.y][star.bx][star.by] = true;

	while (!Q.empty())
	{
		now = Q.top();
		Q.pop();

		if (map[now.bx][now.by] == 3)
			return now.num;//如果箱子到终点退出搜索 

		for (i = 0; i < 4; i++)
		{
			x = now.x + dis[i][0];
			y = now.y + dis[i][1];


			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;

			if (map[x][y] == 1)
				continue;

			next.bx = now.bx;
			next.by = now.by;
			next.num = now.num;
			next.x = x;
			next.y = y;


			if (x == now.bx && y == now.by)//如果下个点是箱子的位置 
			{
				xx = x + dis[i][0];
				yy = y + dis[i][1];

				if (xx < 0 || xx >= n || yy < 0 || yy >= m)
					continue;

				if (map[xx][yy] == 1)
					continue;

				next.bx = xx;
				next.by = yy;
				next.num++;
			}


			if (mark[x][y][next.bx][next.by])//如果推完后的状态已经经历过就不推了 
				continue;

			mark[x][y][next.bx][next.by] = true;
			Q.push(next);
		}
	}
	return -1;
}


int main()
{
	int T, ans;
	scanf("%d", &T);
	while (T--)
	{
		memset(mark, 0, sizeof(mark));//最重要的初始话忘记了，wa了几次 
		scanf("%d%d", &n, &m);

		input();

		star.num = 0;

		ans = BFS();
		printf("%d\n", ans);
	}
	return 0;
}