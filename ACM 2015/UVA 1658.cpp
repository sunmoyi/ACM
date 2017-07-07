#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 1010
#define maxm 10010
#define INF 0x3f3f3f3

using namespace std;


struct node {
	int to, next, cap, flow, cost;
}edge[maxm << 2];
int head[maxn * 2], tol;
int pre[maxn * 2], dis[maxn * 2];
bool vis[maxn * 2];
int N;
int n, m;

void init()
{
	for (int i = 0; i < maxn * 2; i++)
		head[i] = -1;
	tol = 0;
}

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
		//printf("1\n");
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
		//printf("1\n");
	}
	return flow;
}

int main(void)
{
	int a, b, c;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		init();
		for (int i = 2; i < n; i++)
			addedge(i, i + n, 1, 0);
		addedge(1, n + 1, 2, 0);
		addedge(n, n << 1, 2, 0);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			addedge(a + n, b, 1, c);
		}
		N = n * 2 + 1;
		int ans;
		mincostmaxflow(1, n << 1, ans);
		printf("%d\n", ans);
	}
}