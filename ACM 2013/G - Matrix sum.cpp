#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <queue>  
using namespace std;

const int E = 50010;
const int oo = 0x7fffffff;
const int N = 210;

struct edge
{
	int next, v, flow, cost;
}e[E];

int head[N], cnt;
queue<int> q;

void addedge(int u, int v, int flow, int cost)
{
	e[cnt].v = v;
	e[cnt].flow = flow;
	e[cnt].cost = cost;
	e[cnt].next = head[u];
	head[u] = cnt++;
}

void addEdge(int u, int v, int flow, int cost)
{
	addedge(u, v, flow, cost);
	addedge(v, u, 0, -cost);
}

int S, T;
int ans;
int a[N][N];

void init()
{
	int n, m;
	scanf("%d%d", &n, &m);
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			ans += a[i][j];
		}
	}
	int R[N], C[N];
	for (int i = 1; i <= n; i++) scanf("%d", &R[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &C[i]);
	S = 0, T = n + m + 1;
	cnt = 0;
	memset(head, -1, sizeof(head));
	for (int i = 1; i <= n; i++)
	{
		addEdge(S, i, m - R[i], 0);
	}
	for (int i = 1; i <= m; i++)
		addEdge(i + n, T, n - C[i], 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			addEdge(i, j + n, 1, a[i][j]);
		}
	}
}

int dis[N], cc[N], visit[N], pre[N], dd[N];

int spfa()
{
	fill(dis, dis + T + 1, -oo);
	dis[S] = 0;
	pre[S] = -1;
	while (!q.empty()) q.pop();
	q.push(S);
	while (!q.empty()) 
	{
		int u = q.front();
		q.pop();
		visit[u] = 0;
		for (int i = head[u]; i != -1; i = e[i].next) 
		{
			if (e[i].flow > 0 && dis[e[i].v] < dis[u] + e[i].cost) 
			{
				dis[e[i].v] = dis[u] + e[i].cost;
				pre[e[i].v] = u;
				cc[e[i].v] = i;
				dd[e[i].v] = e[i].cost;
				if (!visit[e[i].v])
				{
					q.push(e[i].v);
					visit[e[i].v] = 1;
				}
			}
		}
	}
	return dis[T] >= 0;
}

int argument()
{
	int aug = oo;
	int u, v;
	int ans = 0;
	for (u = pre[v = T]; v != S; v = u, u = pre[v])
		if (e[cc[v]].flow < aug) aug = e[cc[v]].flow;
	for (u = pre[v = T]; v != S; v = u, u = pre[v]) 
	{
		e[cc[v]].flow -= aug;
		e[cc[v] ^ 1].flow += aug;
		ans += dd[v] * aug;
	}
	return ans;
}

void mcmf()
{
	memset(visit, 0, sizeof(visit));
	while (spfa())
	{
		int cost = argument();
		if (ans < 0) break;
		ans -= cost;
	}
	printf("%d\n", ans);
}

int main()
{ 
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) 
	{
		init();
		mcmf();
	}
	return 0;
}