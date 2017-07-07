#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<queue>

#define ESP 1e-4
using namespace std;

struct node {
	int x;
	int y;
	node(int xx = 0, int yy = 0) :x(xx), y(yy) {}
};
long double map[30][30];
long double flow[30][30];
bool maxx[30][30];
bool clock[15][15];

int t, tt, n;


void print(void)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d %d", i, j);
			printf("     %lf", flow[i][j]);
			printf("     %lf\n", map[i][j]);
		}
	}
}
int main(void)
{
	while (scanf_s("%d %d", &n, &t) != EOF)
	{
		memset(map, 0, sizeof(map));
		memset(flow, 0, sizeof(flow));
		memset(maxx, false, sizeof(maxx));
		//memset(clock, false, sizeof(clock));
		flow[1][1] = 1;
		tt = 1;
		int sum = 0;
		int x = 1, y = 1;
		queue<node>Q;

		while (tt <= t)
		{
			//memset(clock, false, sizeof(clock));
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= i; j++)
				{
					//if (clock[i][j])
					//	continue;
					if (flow[i][j] == 0)
						continue;
					if (map[i][j] - 1> ESP)
					{
						map[i + 1][j] += (map[i][j] - 1) / 2;
						map[i + 1][j + 1] += (map[i][j] - 1) / 2;
						//map[i][j] = 1;
					}
					if (maxx[i][j])
						continue;
					else if(map[i][j] + flow[i][j] >= 1 - ESP)
					{
						double kk = flow[i][j] - (1.0 - map[i][j]);
						map[i][j] = 1;
						maxx[i][j] = true;
						map[i + 1][j] += kk / 2;
						map[i + 1][j + 1] += kk / 2;
						Q.push(node(i, j));
						sum++;
						//printf("%d %d\n", i, j);
					}
					else 
					{
						map[i][j] += flow[i][j];
						//if (i == 7 && j == 3)
						//	printf("%lf\n", map[7][3]);
					}
				}
			}
			while (!Q.empty())
			{
				node now = Q.front();
				Q.pop();
				flow[now.x + 1][now.y] += flow[now.x][now.y] / 2;
				flow[now.x + 1][now.y + 1] += flow[now.x][now.y] / 2;
			}
			printf("%d s\n", tt);
			print();
			printf("\n\n\n\n\n");
			tt++;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (map[i][j] - 1 > ESP)
				{
					map[i + 1][j] += (map[i][j] - 1) / 2;
					map[i + 1][j + 1] += (map[i][j] - 1) / 2;
					map[i][j] = 1;
				}
			}
		}
		/*for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (map[i][j] - 1 <= ESP)
				{
					sum++;
				}
			}
		}*/
		printf("%d\n", sum);
	}
	return 0;
}