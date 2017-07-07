#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int M = 100010;
const int N = 5010;
const int INF = 0x3f3f3f3f;

struct Edge 
{
	int u, v, dis, next;
	Edge() {}
	Edge(int u, int v, int dis, int next) : u(u), v(v), dis(dis), next(next) {}
}E[M * 2];

struct Node 
{
	int u, mark, dis;
	Node() {}
	Node(int u, int mark, int dis) : u(u), mark(mark), dis(dis) {}
	bool operator < (const Node &a) const 
	{
		return dis > a.dis;
	}
};

int head[N], d[N][2];
int tot, n, m, cas = 1;
bool vis[N][2];

void solve() 
{
	if (n == 1)
	{
		printf("Case %d: %d\n", cas++, 0);
		return;
	}

	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) 
		d[i][0] = d[i][1] = INF;
	d[n][0] = 0;
	priority_queue<Node> Q;
	Q.push(Node(n, 0, 0));

	while (!Q.empty()) 
	{
		int u = Q.top().u;
		int mark = Q.top().mark;
		Q.pop();
		if (vis[u][mark]) 
			continue;
		vis[u][mark] = true;

		for (int i = head[u]; ~i; i = E[i].next) 
		{
			int v = E[i].v;

			if (d[v][0] == INF)
			{
				d[v][0] = d[u][mark] + E[i].dis;
				Q.push(Node(v, 0, d[v][0]));
			}
			else if (d[u][mark] + E[i].dis < d[v][0])
			{
				d[v][1] = d[v][0];
				d[v][0] = d[u][mark] + E[i].dis;
				Q.push(Node(v, 0, d[v][0]));
				Q.push(Node(v, 1, d[v][1]));
			}
			else if (d[u][mark] + E[i].dis > d[v][0] && d[u][mark] + E[i].dis < d[v][1]) 
			{
				d[v][1] = d[u][mark] + E[i].dis;
				Q.push(Node(v, 1, d[v][1]));
			}
		}
	}
	printf("Case %d: %d\n", cas++, d[1][1]);
}

void AddEdge(int u, int v, int dis)
{
	E[tot] = Edge(u, v, dis, head[u]);
	head[u] = tot++;
	E[tot] = Edge(v, u, dis, head[v]);
	head[v] = tot++;
}

void init() 
{
	scanf("%d%d", &n, &m);
	memset(head, -1, sizeof(head));
	tot = 0;

	int u, v, dis;
	for (int i = 0; i < m; i++) 
	{
		scanf("%d%d%d", &u, &v, &dis);
		AddEdge(u, v, dis);
	}
}

int main() 
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		init();
		solve();
	}
	return 0;
}