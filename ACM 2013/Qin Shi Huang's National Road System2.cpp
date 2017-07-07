#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define N 1010
#define INF 0xfffffff

using namespace std;

struct Point {
	int x;
	int y;
	int z;
}point[N];

int n;
double edge[N][N];
int front[N];
double mindist[N];
double sum;

int used[N][N];
int visited[N];
double Max[N][N];

void prim(int v0)
{
	sum = 0;
	memset(used, 0, sizeof(used));
	memset(visited, 0, sizeof(visited));
	memset(Max, 0, sizeof(Max));
	for (int i = 1; i <= n; i++)
	{
		mindist[i] = edge[v0][i];
		front[i] = v0;
	}
	visited[v0] = 1;
	for (int i = 1; i < n; i++)
	{
		double min = INF;
		int v = -1;
		for (int j = 1; j <= n; j++)
		{
			if(!visited[j] &&  mindist[j] < min)
			{ 
				v = j;
				min = mindist[j];
			}
		}
		if (v != -1)
		{
			sum += mindist[v];
			used[v][front[v]] = used[front[v]][v] = 1;
			visited[v] = 1;
			for (int k = 1; k <= n; k++)
			{
				if (visited[k] && k != v)
					Max[v][k] = Max[k][v] = max(Max[k][front[v]], mindist[v]);
				if (!visited[k] && edge[v][k] < mindist[k])
				{
					mindist[k] = edge[v][k];
					front[k] = v;
				}
			}
		}
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d %d %d", &point[i].x, &point[i].y, &point[i].z);
		for (int i = 1; i <= n; i++)
		{
			edge[i][i] = 0;
			for (int j = i + 1; j <= n; j++)
			{
				double dis = sqrt(pow((point[i].x - point[j].x), 2) + pow((point[i].y - point[j].y), 2));
				edge[i][j] = edge[j][i] = dis;
			}
		}
		prim(1);
		double r = -1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i != j)
					r = max(r, (point[i].z + point[j].z) * 1.0 / (sum - edge[i][j]));
				else
					r = max(r, (point[i].z + point[j].z) * 1.0 / (sum - Max[i][j]));
			}
		}
		printf("%,2lf\n", r);
	}
	return 0;
}