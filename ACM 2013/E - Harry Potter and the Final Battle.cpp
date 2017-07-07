#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
using namespace std;
const int N = 1005;
const int M = 100005;
const int INF = 999999999;
struct Edge
{
	int u, v, w, next;
} edge[M];
int head[N];
int pre[N];
int n, m;
bool vis[N];
int low[N];
int _edge[M]; 

void addEdge(int u, int v, int w, int &k)
{
	edge[k].v = v, edge[k].w = w;
	edge[k].next = head[u], head[u] = k++;
}

int spfa(int s, int flag)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (flag)
		{
			pre[i] = s;
		}
		low[i] = INF;
		vis[i] = false;
	}
	low[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int k = head[u]; k != -1; k = edge[k].next)
		{
			int v = edge[k].v, w = edge[k].w;
			if (low[v]>low[u] + w)
			{
				low[v] = low[u] + w;
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
				if (flag)
				{
					pre[v] = u;
					_edge[v] = k; 
				}
			}
		}
	}
	if (low[n] >= INF) return -1;
	return low[n];
}

int main()
{
	int tcase;
	scanf("%d", &tcase);
	while (tcase--)
	{
		memset(head, -1, sizeof(head));
		scanf("%d%d", &n, &m);
		int tot = 0;
		for (int i = 0; i<m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addEdge(u, v, w, tot);
			addEdge(v, u, w, tot);
		}
		int res = spfa(1, 1);
		if (res == -1)
		{
			printf("-1\n");
			continue;
		}
		int temp = n;
		int Max = -1;
		while (temp != 1)
		{
			int e = _edge[temp];
			int k = edge[e].w;
			edge[e].w = INF;
			int res = spfa(1, 0);
			if (res == -1)
			{
				Max = -1;
				break;
			}
			Max = max(Max, res);
			edge[e].w = k;
			temp = pre[temp];
		}
		printf("%d\n", Max);
	}
}