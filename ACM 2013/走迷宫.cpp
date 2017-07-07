#include<iostream>  
using namespace std;
int dir[8][2] = { -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1 };
int maze[100][100];
typedef struct pp
{
	int x, y, pre;
}pzjj;
pzjj mouse[100];
void display(int tail)
{
	int i = tail;
	do
	{
		printf("%d %d \n", mouse[i].x, mouse[i].y);
		i = mouse[i].pre;
	} while (i != 0 );
}
void bfs(int line, int col)
{
	int i, lx, ly;
	bool find = false;
	int front = 1, rear = 1;
	mouse[1].x = 1, mouse[1].y = 1, mouse[1].pre = 0;//初始化，从1，1开走  
	while (front <= rear && !find)
	{
		for (i = 0; i < 8; i++)//开始搜  
		{
			lx = mouse[front].x + dir[i][0];
			ly = mouse[front].y + dir[i][1];
			if (maze[lx][ly] == 1)
			{
				rear++;
				mouse[rear].x = lx;
				mouse[rear].y = ly;
				mouse[rear].pre = front;
				maze[lx][ly] = 0;//标记走过  
			}
			if (lx == line && ly == col)
			{
				display(rear);
				find = true;
			}
		}
		front++;
	}
	if (!find)
		printf("死路/n");
}
int main()
{
	int i, j;
	int col, line;
	scanf_s("%d%d", &line, &col);
	memset(maze, 0, sizeof(maze));
	for (i = 1; i <= line; i++)
		for (j = 1; j <= col; j++)
			scanf_s("%d", &maze[i][j]);//1表示通过，0表示障碍  
	bfs(line, col);
	return false;
}
