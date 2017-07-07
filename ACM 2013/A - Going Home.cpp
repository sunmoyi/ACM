#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 2100
#define INF 0xfffffff

using namespace std;

struct node {
	int to, next, cap, flow, cost;
}edge[maxn * maxn];

struct point {
	int x, y;
}house[110], man[110];
int numhouse, nummam;
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
	for (int i = 0; i < N; i++)
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
	char c;
	while (scanf_s("%d %d", &n, &m) != EOF &&(n + m))
	{
		numhouse = nummam = 1;
		memset(head, -1, sizeof(head));
		tol = 0;
		for (int i = 1; i <= n; i++)
		{
			getchar();
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &c);
				if (c == 'm')
				{
					man[nummam].x = i;
					man[nummam].y = j;
					nummam++;
				}
				else if (c == 'H')
				{
					house[numhouse].x = i;
					house[numhouse].y = j;
					numhouse++;
				}
			}
		}
		for (int i = 1; i < nummam; i++)
		{
			for (int j = 1; j < numhouse; j++)
			{
				int dis = abs(man[i].x - house[j].x) + abs(man[i].y - house[j].y);
				addedge(i, j + nummam - 1, 1, dis);
			}
		}
		for (int i = 1; i < nummam; i++)
			addedge(0, i, 1, 0);
		for (int i = nummam; i < nummam + numhouse - 1; i++)
			addedge(i, nummam + numhouse - 1, 1, 0);
		N = nummam + numhouse;
		int cost = 0;
		mincostmaxflow(0, N - 1, cost);
		printf("%d\n", cost);
	}
	return 0;
}