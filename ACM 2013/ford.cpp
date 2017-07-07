#include<cstdio>

using namespace std;

const int INF = 0xfffffff;

struct edge{
	int from;
	int cost;
	int to;
};
edge es[1000];
int d[1000];
int V, E;

bool shorttest_path(int s)
{
	for (int i = 0; i < V; i++)
	{
		d[i] = INF;
	}
	d[s] = 0;
	for (int j = 0; j < V; j++)
	{
		for (int i = 0; i < E; i++)
		{
			edge e = es[i];
			if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				if (j == V - 1)
					return true;//在第V - 1次依旧更新了d的数值   说明存在负环
			}
		}
	}
	return true;
}