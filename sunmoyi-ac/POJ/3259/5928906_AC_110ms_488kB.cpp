#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#define INF 0xfffffff
#define maxn 10002

using namespace std;

struct node {
	int v;
	int len;
	node(int v = 0, int len = 0) :v(v), len(len) {}
	bool friend operator <(const node&a, const node&b)
	{
		return a.len > b.len;
	}
};

bool inqueue[maxn];
int mindist[maxn];
vector<node>G[maxn];
int cnt[maxn];
int V, E;

void init(void)
{
	for (int i = 0; i < maxn; i++)
	{
		inqueue[i] = false;
		mindist[i] = INF;
		cnt[i] = 0;
		G[i].clear();
	}
}

bool Dijkstra(int s)
{
	priority_queue<node>Q;
	mindist[s] = 0;
	for (int i = 0; i < G[s].size(); i++)
	{
		int u = G[s][i].v;
		inqueue[u] = true;
		cnt[u]++;
		mindist[u] = min(mindist[u], G[s][i].len);
		Q.push(G[s][i]);
	}
	while (!Q.empty())
	{
		node u = Q.top();
		Q.pop();
		inqueue[u.v] = false;

		int len = G[u.v].size();
		for (int j = 0; j < len; j++)
		{
			int v = G[u.v][j].v;
			int len = G[u.v][j].len;
			if (mindist[v] - len > mindist[u.v])
			{
				mindist[v] = len + mindist[u.v];
				if (!inqueue[v])
				{
					inqueue[v] = true;
					if (++cnt[v] >= V)
						return true;
					Q.push(v);
				}
			}
		}
	}
	return false;
}

int main(void)
{
	int ans, a, b, c, len;
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			init();
			scanf("%d %d %d", &V, &E, &c);
			for (int i = 1; i <= E; i++)
			{
				scanf("%d %d %d", &a, &b, &len);
				G[a].push_back(node(b, len));
				G[b].push_back(node(a, len));
			}
			for (int i = 1; i <= c; i++)
			{
				scanf("%d %d %d", &a, &b, &len);
				G[a].push_back(node(b, -len));
			}
			if (Dijkstra(1))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}