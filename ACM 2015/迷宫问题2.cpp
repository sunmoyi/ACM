#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int map[10][10];
int dir[4][2] = { {1, 0}, {-1,0}, {0,1}, {0,-1} };
int vis[10][10];
int front = 0, nextt = 1;

struct node {
	int x, y, front;
}queue[100];

void print(int x)
{
	if (queue[x].front != -1)
	{
		print(queue[x].front);
		printf("(%d, %d)\n", queue[x].x, queue[x].y);
	}
}

void bfs(int x, int y)
{
	bool flag = false;
	queue[front].x = x;
	queue[front].y = y;
	queue[front].front = -1;
	while (front < nextt && !flag)
	{
		for (int i = 0; i < 4; i++)
		{
			int xx = queue[front].x + dir[i][0];
			int yy = queue[front].y + dir[i][1];
			if (xx < 0 || xx >= 5 || yy < 0 || yy >= 5 || vis[xx][yy] || map[xx][yy] == 1)
				continue;
			else
			{
				vis[xx][yy] = true;
				queue[nextt].x = xx;
				queue[nextt].y = yy;
				queue[nextt].front = front;
				nextt++;
			}
			if (xx == 4 && yy == 4)
			{
				flag = true;
				print(front);
			}
		}
		front++;
	}
	return;
}

int main(void)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	printf("(0, 0)\n");
	bfs(0, 0);
	printf("(4, 4)\n");
	return 0;
}