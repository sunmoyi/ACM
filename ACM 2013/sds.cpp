#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0xfffffff

using namespace std;

struct Node {
	double x, y;
}node[maxn];

double cost[maxn][maxn];
int vis[maxn];
double lowc[maxn];

double distance(Node a, Node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double prim(int n)
{
	int  p;
	double minc, res = 0;
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	for (int i = 1; i < n; i++)
		lowc[i] = cost[0][i];
	for (int i = 1; i < n; i++)
	{
		minc = INF;
		p = -1;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == 0 && minc > lowc[j])
			{
				minc = lowc[j];
				p = j;
			}
		}
		if (minc == INF)
			return -1;
		res += minc;
		vis[p] = 1;
		for (int j = 0; j < n; j++)
			if (vis[j] == 0 && lowc[j] > cost[p][j])
				lowc[j] = cost[p][j];
	}
	return res;
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int k = 0; k < n; k++)
			scanf("%lf %lf", &node[k].x, &node[k].y);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					cost[i][j] = 0;
				else
					cost[i][j] = distance(node[i], node[j]);
			}
		}
		printf("%.2lf\n", prim(n));
	}
	return 0;
}