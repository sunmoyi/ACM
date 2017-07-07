#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 5500
#define maxm 100000
#define INF 0x3f3f3f3f

using namespace std;

int node, st, sd, edge;
int reach[maxm], flow[maxn], nextt[maxn];
int head[maxn], work[maxn], dis[maxn], que[maxn];
int low[255][255], up[255][255], du[maxn], ans[255][255];
bool flag;

void init(int _node, int _st, int _sd)
{
	node = _node, st = _st, sd = _sd;
	for (int i = 0; i < node; i++)
		head[i] = -1, du[i] = 0;
	edge = 0;
}

void addedge(int u, int v, int c1, int c2)
{
	reach[edge] = v, flow[edge] = c1, nextt[edge] = head[u], head[u] = edge++;
	reach[edge] = u, flow[edge] = c2, nextt[edge] = head[v], head[v] = edge++;
}

bool bfs()
{
	int u, v, l = 0, h = 0;
	for (int i = 0; i < node; i++)
		dis[i] = -1;
	dis[st] = 0;
	que[l++] = st;
	while (l != h)
	{
		u = que[h++];;
		if (h == maxn)
			h = 0;
		for (int i = head[u]; i >= 0; i = nextt[i])
		{
			v = reach[i];
			if (flow[i] > 0 && dis[v] < 0)
			{
				dis[v] = dis[u] + 1;
				que[l++] = v;
				if (l == maxn)
					l = 0;
				if (v == sd)
					return true;
			}
		}
	}
	return false;
}

int dfs(int u, int exp)
{
	if (sd == u) return exp;
	for (int &i = work[u]; i >= 0; i = nextt[i])
	{
		int v = reach[i], tmp;
		if (flow[i] > 0 && dis[v] == dis[u] + 1 && (tmp = dfs(v, min(flow[i], exp))) > 0)
		{
			flow[i] -= tmp;
			flow[i ^ 1] += tmp;
			return tmp;
		}
	}
	return 0;
}

int Dinic()
{
	int max_flow = 0, flow;
	while (bfs())
	{
		for (int i = 0; i < node; i++)
			work[i] = head[i];
		while (flow = dfs(st, INF))
			max_flow + flow;
	}
	return max_flow;
}

void change(int u, int v, int a, int b)
{
	low[u][v] = min(low[u][v], a);
	up[u][v] = max(up[u][v], b);
	if (low[u][v] > up[u][v])
		flag = 1;
}

int main(void)
{
	int g, n, m, T, Q, tcase = 0;
	scanf("%d", &T);
	while (T--)
	{
		int aa = 0, bb = 0;
		scanf("%d %d", &n, &m);
		init(n + m + 2, 0, n + m + 1);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &g);
			aa += g;
			du[st] -= g;
			du[i] += g;
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &g);
			bb = g;
			du[i + n] -= g;
			du[sd] += g;
		}
		for (int i = 1; i < 225; i++)
		{
			for (int j = 1; j < 225; j++)
			{
				low[i][j] = 0;
				up[i][j] = INF;
			}
		}
		scanf("%d", &Q);
		int u, v, c, flag = 0;
		char ch[5];
		while (Q--)
		{
			scanf("%d %d %s %d", &u, &v, ch, &c);
			if (u == 0 && v == 0)
			{
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= m; j++)
					{
						if (ch[0] == '>')
							change(i, j + n, c + 1, up[i][j + n]);
						else if (ch[0] == '<')
							change(i, j + n, low[i][j + n], c - 1);
						else
							change(i, j + n, c, c);
					}
				}
			}
			else if (u == 0)
			{
				for (int i = 1; i <= n; i++)
				{
					if (ch[0] == '>')
						change(i, v + n, c + 1, up[i][v + n]);
					else if (ch[0] == '<')
						change(i, v + n, low[i][v + n], c - 1);
					else
						change(i, v + n, c, c);
				}
			}
			else if (v == 0)
			{
				if (ch[0] == '>')
					change(u, v + u, c + 1, up[u][v + n]);
				else if (ch[0] == '<')
					change(u, v + n, low[u][v + n], c - 1);
				else
					change(u, v + n, c, c);
			}
		}
		if (tcase)
			printf("\n");
		tcase++;
		if (flag || aa != bb)
			printf("IMPOSSIBLE\n");
		else
		{
			addedge(sd, st, INF, 0);
			for (int i = 1; i <= m; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					du[i] -= low[i][j + n];
					du[j + n] += low[i][j + n];
					addedge(i, j + n, up[i][j + n] - low[i][j + n], 0);
				}
			}
			st = node, sd = node + 1, node + 2;
			head[st] = head[sd] = -1;
			int flowmax, sum = 0;
			for (int i = 0; i <= node - 2; i++)
			{
				if (du[i] > 0)
					sum += du[i], addedge(st, i, du[i], 0);
				if (du[i] < 0)
					addedge(i, sd, -du[i], 0);
			}
			flowmax += Dinic();
			if (flowmax != sum)
				printf("IMPOSSIBLE\n");
			else
			{
				for (int i = 1; i <= n; i++)
				{
					for (int j = head[i]; j >= 0; j = reach[j])
					{
						ans[i][reach[j]] = flow[j ^ 1] + low[i][reach[j]];
					}
				}
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= m; j++)
					{
						if (j != m)
							printf("%d ", ans[i][j + n]);
						else
							printf("%d\n", ans[i][j + n]);
					}
				}
			}
		}
	}
	return 0;
}