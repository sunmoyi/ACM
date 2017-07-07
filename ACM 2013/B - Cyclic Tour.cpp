#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1010
#define INF 0xfffffff

using namespace std;

struct node {
	int to, next, cap, flow, cost;
}edge[maxn * maxn];
int head[maxn], tol;
int pre[maxn], dis[maxn];
bool vis[maxn];
int N;
int n, m;

void addedge(int u, int v, int cap, int cost)
{
	edge[tol].to = v;
	edge[tol].cap = cap;
	edge[tol].cost = cost;
	edge[tol].flow = 0;
	edge[tol].next = head[u];
	head[u] = tol++;

	edge[tol].to = u; 
	edge[tol].cap = 0;
	edge[tol].cost = -cost;
	edge[tol].flow = 0;
	edge[tol].next = head[v];
	head[v] = tol++;
}

bool spfa(int s, int t)
{
	queue<int>Q;
	for (int i = 0; i <= N; i++)
	{
		dis[i] = INF;
		vis[i] = false;
		pre[i] = -1;
	}
	dis[s] = 0;
	vis[s] = true;
	Q.push(s);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		vis[u] = false;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost)
			{
				dis[v] = dis[u] + edge[i].cost;
				pre[v] = i;
				if (!vis[v])
				{
					vis[v] = true;
					Q.push(v);
				}
			}
		}
	}
	if (pre[t] == -1)
		return false;
	else
		return true;
}

int mincostmaxflow(int s, int t, int &cost)
{
	int flow = 0;
	cost = 0;
	while (spfa(s, t))
	{
		int Min = INF;
		for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to])
		{
			if (Min > edge[i].cap - edge[i].flow)
				Min = edge[i].cap - edge[i].flow;
		}
		for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to])
		{
			edge[i].flow += Min;
			edge[i ^ 1].flow -= Min;
			cost += edge[i].cost * Min;
		}
		flow += Min;
	}
	return flow;
}

int main(void)
{
	int a, b, c;
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		memset(head, -1, sizeof(head));
		tol = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf_s("%d %d %d", &a, &b, &c);
			addedge(a, a + n, 1, c);
		}
		for (int i = 1; i <= n; i++)
			addedge(0, i, 1, 0);
		for (int i = n + 1; i <= n + n; i++)
			addedge(i, n + n + 1, 1, 0);
		N = n + n + 2;
		int cost = 0;
		int maxx = mincostmaxflow(0, n + n + 1, cost);
		if (maxx == n)
			printf("%d\n", cost);
		else
			printf("-1\n");
	}
	return 0;
}