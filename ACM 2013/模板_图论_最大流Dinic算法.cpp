#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 10005
#define INF 0xfffffff
using namespace std;

struct edge {
	int to;
	int cap;
	int rev;
	edge(int to = 0, int cap = 0, int rev = 0) : to(to), cap(cap), rev(rev){}
};
vector<edge>G[maxn];
int level[maxn];
int iter[maxn];
int V, E;

void add_edge(int from, int to, int cap)
{
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size() - 1));
}

void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int>Q;
	level[s] = 0;
	Q.push(s);
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		for (int i = 0; i <= G[v].size(); i++)
		{
			edge &e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0)
			{
				level[e.to] = level[v] + 1;
				Q.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f)
{
	if (v == t)
		return f;
	for (int &i = iter[v]; i < G[v].size(); i++)
	{
		edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to])
		{
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0)
			{
				e.to -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
}

int max_flow(int s, int t)
{
	int flow = 0;
	while (1)
	{
		bfs(s);
		if (level[t] < 0)
			return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while ((f = dfs(s, t, INF)) > 0)
		{
			flow += f;
		}
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