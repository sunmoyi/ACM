#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int map[10][10];
bool vis[10][10];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int front = 0, nextt = 1;

struct node {
	int x;
	int y;
	int front;
}queue[100];

void print(int x)
{
	if (queue[x].front != -1)
	{
		print(queue[x].front);
		printf("(%d, %d)\n", queue[x].x, queue[x].y);
	}
}

void bfs()
{
	queue[front].x = 0;
	queue[front].y = 0;
	queue[front].front = -1;
	vis[0][0] = true;
	bool flag = false;
	while (front < nextt && !flag)
	{
		for (int i = 0; i < 4; i++)
		{
			int xx = queue[front].x + dir[i][0];
			int yy = queue[front].y + dir[i][1];
			if (xx < 0 || xx >= 5 || yy < 0 || yy >= 5)
				continue;
			if (vis[xx][yy])
				continue;
			if (map[xx][yy] == 1)
				continue;
			if (xx == 4 && yy == 4)
			{
				print(front);
				flag = true;
			}
			vis[xx][yy] = true;
			queue[nextt].x = xx;
			queue[nextt].y = yy;
			queue[nextt].front = front;
			nextt++;
		}
		front++;
	}
}

int main(void)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &map[i][j]);

	memset(vis, 0, sizeof(vis));
	printf("(0, 0)\n");
	bfs();
	printf("(4, 4)\n");
	return 0;
}