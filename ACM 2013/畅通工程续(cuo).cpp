#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define INF  100000000
int map[205][205];
bool intree[205];
int mindist[205];
int v, e;

void dijkstra(void)
{
	int addnode, tempmin;
	for (int nodenum = 0; nodenum < v - 1; nodenum++)
	{
		tempmin = INF;
		for (int i = 0; i < v; i++)
		{
			if (intree[i] == false && mindist[i] < tempmin)
			{
				tempmin = mindist[i];
				addnode = i;
			}
		}
		intree[addnode] = true;
		for (int i = 0; i < v; i++)
		{
			if (intree[i] == false && mindist[i] > mindist[addnode] + map[i][addnode])
				mindist[i] = mindist[addnode] + map[i][addnode];
		}
	}
	return;
}

int main(void)
{
	int a, b, c;
	while (scanf("%d %d", &v, &e) != EOF)
	{
		for (int i = 0; i < 205; i++)
		{
			for (int j = 0; j < 205; j++)
			{
				map[i][j] = INF;
			}
			intree[i] = false;
			mindist[i] = INF;
		}

		for (int i = 1; i <= e; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			map[a][b] = map[b][a] = min(c, map[a][b]);
		}
		scanf("%d %d", &a, &b);
		mindist[a] = 0;
		dijkstra();
		if (mindist[b] == INF)
			printf("-1\n");
		else
			printf("%d\n", mindist[b]);
	}
	return 0;
}