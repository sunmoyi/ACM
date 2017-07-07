#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 1000010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int v, c;
	node(int v = 0, int c = 0) :v(v), c(c){}
	bool friend operator < (const node&a, const node&b)
	{
		return a.c > b.c;
	}
};

struct edge {
	int v, cost;
	edge(int v = 0, int cost = 0) :v(v), cost(cost){}
};

vector<edge>G[maxn];
bool vis[maxn];
int dis[maxn];

void Dijkstra(int n, int start)
{
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++)
		dis[i] = INF;
	priority_queue<node>Q;
	dis[start] = 0;
	Q.push(node(start, 0));
	while (!Q.empty())
	{
		node temp = Q.top();
		Q.pop();
		int u = temp.v;
		if (vis[u])
			continue;
		vis[u] = true;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].v;
			int cost = G[u][i].cost;
			if (!vis[v] && dis[v] > dis[u] + cost)
			{
				dis[v] = dis[u] + cost;
				Q.push(node(v, dis[v]));
			}
		}
	}
}

int main(void)
{
	int T;
	int N, M, C;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; Case++)
	{
		scanf("%d %d %d", &N, &M, &C);
		for (int i = 1; i <= 3 * N; i++)
			G[i].clear();
		int u, v, w;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &u);
			G[i].push_back(edge(N + 2 * u - 1, 0));
			G[N + 2 * u].push_back(edge(i, 0));
		}
		for (int i = 1; i < N; i++)
		{
			G[N + 2 * i - 1].push_back(edge(N + 2 * (i + 1), C));
			G[N + 2 * (i + 1) - 1].push_back(edge(N + 2 * i, C));
		}
		while (M--)
		{
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(edge(v, w));
			G[v].push_back(edge(u, w));
		}
		Dijkstra(3 * N, 1);
		if (dis[N] == INF)
			dis[N] = -1;
		printf("Case #%d: %d\n", Case, dis[N]);
	}
	return 0;
}