#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10

using namespace std;

int map[maxn][maxn];
struct node {
	int x, y, k;
	char cmd;
	node(int x = 0, int y = 0, int k = 0, char cmd = 0) :x(x), y(y), k(k), cmd(cmd) {}
}num[1010];
int sum;

bool move(node a)
{
	map[a.x][a.y] = a.k;
	if (a.cmd == 'L')
	{
		for (int i = 1; i <= 4; i++)
		{
			int temp = 1, now = 1;
			while (temp <= 4 && now <= 4)
			{
				while (map[i][now] == 0 && now <= 4)
					now++;
				map[i][temp] = map[i][now];
				if (temp != now)
					map[i][now] = 0;
				temp++, now ++;
			}
			if (map[i][1] == map[i][2])//(1 2) (3 4)xiangtong huozhe 1 2 (3 4)
			{
				map[i][1] = 2 * map[i][1];
				map[i][2] = map[i][3];
				map[i][3] = map[i][4];
				map[i][4] = 0;
				if (map[i][2] == map[i][3])
				{
					map[i][2] *= 2;
					map[i][3] = map[i][4] = 0;
				}
			}
			else if (map[i][2] == map[i][3])
			{
				map[i][2] *= 2;
				map[i][3] = map[i][4];
				map[i][4] = 0;
			}
			else if (map[i][3] == map[i][4])
			{
				map[i][3] *= 2;
				map[i][4] = 0;
			}
			
		}
	}
	else if (a.cmd == 'R')
	{
		for (int i = 1; i <= 4; i++)
		{	
			int temp = 4, now = 4;
			while (temp >= 1 && now >= 1 )
			{
				while (map[i][now] == 0 && now >= 1)
					now--;
				map[i][temp] = map[i][now];
				if (temp != now)
					map[i][now] = 0;
				temp--, now--;
			}
			if (map[i][4] == map[i][3])
			{
				map[i][4] *= 2;
				map[i][3] = map[i][2];
				map[i][2] = map[i][1];
				map[i][1] = 0;
				if (map[i][2] == map[i][3])
				{
					map[i][3] *= 2;
					map[i][1] = map[i][2] = 0;
				}
			}
			else if (map[i][2] == map[i][3])
			{
				map[i][3] *= 2;
				map[i][2] = map[i][1];
				map[i][1] = 0;
			}
			else if (map[i][1] == map[i][2])
			{
				map[i][2] *= 2;
				map[i][1] = 0;
			}
			
		}
	}
	else if (a.cmd == 'D')
	{
		for (int i = 1; i <= 4; i++)
		{
			int temp = 4, now = 4;
			while (temp >= 1 && now >= 1)
			{
				while (map[now][i] == 0 && now >= 1)
					now--;
				map[temp][i] = map[now][i];
				if (temp != now)
					map[now][i] = 0;
				temp--, now--;
			}
			if (map[4][i] == map[3][i])
			{
				map[4][i] *= 2;
				map[3][i] = map[2][i];
				map[2][i] = map[1][i];
				map[1][i] = 0;
				if (map[3][i] == map[2][i])
				{
					map[3][i] *= 2;
					map[1][i] = map[2][i] = 0;
				}
			}
			else if (map[3][i] == map[2][i])
			{
				map[3][i] *= 2;
				map[2][i] = map[1][i];
				map[1][i] = 0;
			}
			else if (map[2][i] == map[1][i])
			{
				map[2][i] *= 2;
				map[1][i] = 0;
			}
		}
	}
	else
	{
		for (int i = 1; i <= 4; i++)
		{
			int temp = 1, now = 1;
			while (temp <= 4 && now <= 4)
			{
				while (map[now][i] == 0 && now <= 4)
					now++;
				map[temp][i] = map[now][i];
				if (temp != now)
					map[now][i] = 0;
				temp++, now++;
			}
			if (map[1][i] == map[2][i])
			{
				map[1][i] *= 2;
				map[2][i] = map[3][i];
				map[3][i] = map[4][i];
				map[4][i] = 0;
				if (map[2][i] == map[3][i])
				{
					map[2][i] *= 2;
					map[4][i] = map[3][i] = 0;
				}
			}
			else if (map[3][i] == map[2][i])
			{
				map[2][i] *= 2;
				map[3][i] = map[4][i];
				map[4][i] = 0;
			}
			else if (map[3][i] == map[4][i])
			{
				map[3][i] *= 2;
				map[4][i] = 0;
			}
		}
	}
	bool flag = false;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			if (map[i][j] == 0)
				flag = true;
	return flag;
}

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		getchar();
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= sum; i++)
		{
			scanf("%d %d %d %c", &num[i].x, &num[i].y, &num[i].k, &num[i].cmd);
			getchar();
		}
		bool flag = true;
		for (int i = 1; i <= sum; i++)
		{
			if (!move(num[i]) && i != sum)
			{
			//move(num[i]);
			//for (int i = 1; i <= 4; i++)
			//{
			//	for (int j = 1; j < 4; j++)
			//		printf("%d ", map[i][j]);
			//	printf("%d\n", map[i][4]);
			//}
			//printf("\n\n\n\n\n\n\n");
				flag = false;
				break;
			}
		}
		if (flag)
		{
			for (int i = 1; i <= 4; i++)
			{
				for (int j = 1; j < 4; j++)
					printf("%d ", map[i][j]);
				printf("%d\n", map[i][4]);
			}
		}
		else
			printf("Game over!\n");
	}
	return 0;
}