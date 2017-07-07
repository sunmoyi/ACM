#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int INF = 0xfffffff;

int cost[1000][1000];//cost数组表示的是边<u，v>的权值 INF表示不存在这条边
int d[1000];//finall aim
bool used[1000];
int V;

void dijkstra(int s)
{
	memset(d, INF, sizeof(d));
	memset(used, 0, sizeof(used));
	d[s] = 0;

	while (true)
	{
		int v = -1;
		for (int u = 0; u < V; u++)
		{
			if (!used[u] && (v == -1 || d[u] < d[v]))
				v = u;
		}

		if (v == -1)
			break;

		for (int u = 0; u < V; u++)
		{
			if (d[u] > d[v] + cost[v][u])
				d[u] = d[v] + cost[v][u];
		}
	}
}