#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 10005
#define INF 0xfffffff
using namespace std;

struct edge{
	int to;
	int cap;
	int rev;
	edge(int to = 0, int cap = 0, int rev = 0) : to(to), cap(cap), rev(rev){}
};
vector<edge>G[maxn];
bool used[maxn];
int V, E;

void add_edge(int from, int to, int cap)
{
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size() - 1));
}

int dfs(int v, int t, int f)
{
	if (v == t)
		return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0)
		{
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
}

int max_flow(int s, int t)
{
	int flow = 0;
	for (;;)
	{
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0)
			return flow;
		flow += f;
	}
}

int main(void)
{
	int a, b, len;
	while (scanf("%d %d", &V, &E) != EOF)
	{
		for (int i = 1; i <= V; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			add_edge(a, b, len);
		}
		int S, T;
		scanf("%d %d", &S, &T);
		int ans = max_flow(S, T);
		printf("%d\n", ans);
	}
	return 0;
}