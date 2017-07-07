#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int map[10][10];
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int vis[10][10];
int front = 0, nextt = 1;

struct node{
	int x;
	int y;
	int front;
}a[100];

void print(int x)
{
	if (a[x].front != -1)
	{
		print(a[x].front);
		printf("(%d, %d)\n", a[x].x, a[x].y);
	}
}

void bfs(int x, int y)
{
	bool flag = false;
	a[front].x = x;
	a[front].y = y;
	a[front].front = -1;
	while (front < nextt && !flag)
	{
		for (int i = 0; i < 4; i++)
		{
			int b = a[front].x + dir[i][0];
			int c = a[front].y + dir[i][1];
			if (b < 0 || b >= 5 || c < 0 || c >= 5 || vis[b][c] || map[b][c] == 1)
				continue;
			else
			{
				vis[b][c] = true;
				a[nextt].x = b;
				a[nextt].y = c;
				a[nextt].front = front;
				nextt++;
			}
			if (b == 4 && c == 4)
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
			scanf("%d", &map[i][j]);
	}
	printf("(0, 0)\n");
	bfs(0, 0);
	printf("(4, 4)\n");
	return 0;
}