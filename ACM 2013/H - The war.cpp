#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXNODE = 10010;
const int MAXEDGE = 200010;
const int INF = 0x3f3f3f3f;

struct Edge {
	int u, v, id, c, next;
	bool bridge;
	Edge() {}
	Edge(int u, int v, int id, int c, int next) : u(u), v(v), id(id), c(c), next(next), bridge(false) {}
}E[MAXEDGE];

struct Node {
	int v, c;
	Node() {}
	Node(int v, int c) :v(v), c(c) {}
};

vector<Node> bcc[MAXNODE];
int head[MAXNODE], belong[MAXNODE], pre[MAXNODE], Stack[MAXNODE], lowlink[MAXNODE];
int n, m, tot, top, dfs_clock, bcc_cnt;

void AddEdge(int u, int v, int id, int c)
{
	E[tot] = Edge(u, v, id, c, head[u]);
	head[u] = tot++;
	E[tot] = Edge(v, u, id, c, head[v]);
	head[v] = tot++;
}

void init() 
{
	memset(head, -1, sizeof(head));
	tot = 0;

	int u, v, c;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		AddEdge(u, v, i, c);
	}
}

void dfs(int u, int fa) 
{
	pre[u] = lowlink[u] = ++dfs_clock;
	Stack[++top] = u;

	for (int i = head[u]; ~i; i = E[i].next) 
	{
		if (E[i].id == fa) 
			continue;
		int v = E[i].v;
		if (!pre[v])
		{
			dfs(v, E[i].id);
			lowlink[u] = min(lowlink[u], lowlink[v]);
			if (lowlink[v] > pre[u])
			{
				E[i].bridge = E[i ^ 1].bridge = true;
				bcc_cnt++;
				while (1) 
				{
					int x = Stack[top--];
					belong[x] = bcc_cnt;
					if (x == v) break;
				}
			}
		}
		else lowlink[u] = min(lowlink[u], pre[v]);
	}
}

void find_bcc() 
{
	memset(pre, 0, sizeof(pre));
	dfs_clock = top = bcc_cnt = 0;

	for (int i = 1; i <= n; i++)
		if (!pre[i]) 
		{
			dfs(i, -1);
			if (top) 
			{
				++bcc_cnt;
				while (top) 
				{
					int x = Stack[top--];
					belong[x] = bcc_cnt;
				}
			}
		}
}

int ans;

int dfs2(int u, int fa) 
{
	int Min1 = INF, Min2 = INF;

	for (int i = 0; i < bcc[u].size(); i++)
	{
		int v = bcc[u][i].v;
		if (v == fa)
			continue;
		Min2 = min(min(dfs2(v, u), bcc[u][i].c), Min2);
		if (Min2 < Min1) swap(Min2, Min1);
	}
	ans = min(Min2, ans);
	return Min1;
}

void solve()
{
	find_bcc();
	if (bcc_cnt == 1)
	{
		printf("-1\n");
		return;
	}

	Edge Min;
	Min.c = INF;
	for (int i = 1; i <= bcc_cnt; i++) 
		bcc[i].clear();
	for (int i = 0; i < tot; i++) 
	{
		if (!E[i].bridge) 
			continue;
		if (E[i].c < Min.c) 
			Min = E[i];
		int x = belong[E[i].u], y = belong[E[i].v];
		bcc[x].push_back(Node(y, E[i].c));
	}

	ans = INF;
	int u = belong[Min.u], v = belong[Min.v];
	dfs2(u, v);
	dfs2(v, u);
	if (ans == INF) ans = -1;
	printf("%d\n", ans);
}

int main() 
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		init();
		solve();
	}
	return 0;
}