#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;
const int MAXN = 1010;
const int MAXM = 10010;
const int INF = 0x3f3f3f3f;
struct Edge
{
	int to, next, cap, flow, cost;
}edge[MAXM];
int head[MAXN], tol;
int pre[MAXN], dis[MAXN];
bool vis[MAXN];
int N;
void init(int n)
{
	N = n;
	tol = 0;
	memset(head, -1, sizeof(head));
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
	queue<int>q;
	for (int i = 0; i < N; i++)
	{
		dis[i] = INF;
		vis[i] = false;
		pre[i] = -1;
	}
	dis[s] = 0;
	vis[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (edge[i].cap > edge[i].flow &&
				dis[v] > dis[u] + edge[i].cost)
			{
				dis[v] = dis[u] + edge[i].cost;
				pre[v] = i;
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	if (pre[t] == -1)return false;
	else return true;
}
int minCostMaxflow(int s, int t, int &cost)
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
			cost += edge[i].cost*Min;
		}
		flow += Min;
	}
	return flow;
}
int n, m, k;
char str[12][12];
void solve()
{
	init(2 * n*m + 3);
	int start = 2 * n*m;
	int end = 2 * n*m + 2;
	addedge(start, start + 1, k, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			addedge(start, 2 * (i*m + j), 1, 0);
			addedge(2 * (i*m + j) + 1, end, 1, 0);
			addedge(start + 1, 2 * (i*m + j) + 1, 1, 0);
			for (int y = j + 1; y < m; y++)
			{
				if (str[i][y] == str[i][j])
					addedge(2 * (i*m + j), 2 * (i*m + y) + 1, 1, -(str[i][j] - '0') + y - j - 1);
				else addedge(2 * (i*m + j), 2 * (i*m + y) + 1, 1, y - j - 1);
			}
			for (int x = i + 1; x < n; x++)
			{
				if (str[x][j] == str[i][j])
					addedge(2 * (i*m + j), 2 * (x*m + j) + 1, 1, -(str[i][j] - '0') + x - i - 1);
				else addedge(2 * (i*m + j), 2 * (x*m + j) + 1, 1, x - i - 1);
			}
		}
	int cost;
	int flow = minCostMaxflow(start, end, cost);
	if (flow != n*m)printf("-1\n");
	else printf("%d\n", -cost);
}

int main()
{
	int T;
	scanf("%d", &T);
	int iCase = 0;
	while (T--)
	{
		iCase++;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; i++)
			scanf("%s", str[i]);
		printf("Case %d : ", iCase);
		solve();
	}
	return 0;
}
