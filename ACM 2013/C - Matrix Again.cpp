#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <map>
#include<algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
int head[800000], source, sink, cost, flow, cnt, mp[700][700];
int cur[800000], d[800000], pre[800000], vis[800000];
struct node
{
	int u, v, cap, next, cost;
}edge[10000000];
void add(int u, int v, int cap, int cost)
{
	edge[cnt].v = v;
	edge[cnt].cap = cap;
	edge[cnt].cost = cost;
	edge[cnt].next = head[u];
	head[u] = cnt++;

	edge[cnt].v = u;
	edge[cnt].cap = 0;
	edge[cnt].cost = -cost;
	edge[cnt].next = head[v];
	head[v] = cnt++;
}
int spfa()
{
	memset(d, INF, sizeof(d));
	memset(vis, 0, sizeof(vis));
	queue<int>q;
	q.push(source);
	cur[source] = -1;
	d[source] = 0;
	int minflow = INF, i;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			if (d[v]>d[u] + edge[i].cost&&edge[i].cap)
			{
				d[v] = d[u] + edge[i].cost;
				minflow = min(minflow, edge[i].cap);
				cur[v] = i;
				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	if (d[sink] == INF) return 0;
	flow += minflow;
	cost -= minflow*d[sink];
	for (i = cur[sink]; i != -1; i = cur[edge[i ^ 1].v])
	{
		edge[i].cap -= minflow;
		edge[i ^ 1].cap += minflow;
	}
}
void mcmf(int n)
{
	cost = 0;
	flow = 0;
	while (spfa());
	printf("%d\n", cost - mp[0][0] - mp[n - 1][n - 1]);
}
int main()
{
	int n, i, j, k;
	while (scanf("%d", &n) != EOF)
	{
		memset(head, -1, sizeof(head));
		cnt = 0;
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				scanf("%d", &mp[i][j]);
			}
		}
		source = 2 * n*n;
		sink = 2 * n*n + 1;
		add(source, 0, 2, 0);
		add(2 * n*n - 1, sink, 2, 0);
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				if ((i == 0 && j == 0) || (i == n - 1 && j == n - 1))
				{
					add(i*n + j, i*n + j + n*n, 2, -mp[i][j]);
				}
				else
					add(i*n + j, i*n + j + n*n, 1, -mp[i][j]);
				if (i<n - 1)
					add(i*n + j + n*n, (i + 1)*n + j, 1, 0);
				if (j<n - 1)
					add(i*n + j + n*n, i*n + j + 1, 1, 0);
			}
		}
		mcmf(n);
	}
	return 0;
}