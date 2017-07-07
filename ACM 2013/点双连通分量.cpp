#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 200

using namespace std;

vector<vector<int>>G(maxn);
int dfn[maxn];
int low[maxn];
int ntime;
int n, m;

struct	Edge {
	int u, v;
	Edge(int u = 0, int v = 0) :u(u), v(v) {}
};

deque<Edge>edge;
int nblock = 0;

void tarjan(int u, int father)
{
	low[u] = dfn[u] = ntime++;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!dfn[v])
		{
			edge.push_back(Edge(u, v));
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			Edge temp(0, 0);
			if (dfn[u] <= low[v])
			{
				printf("Block No: %d\n", ++nblock);
				do {
					temp = edge.back();
					edge.pop_back();
					printf("%d, %d\n", temp.u, temp.v);
				} while (!(temp.u == u && temp.v == v));
			}
		}
		else
		{
			if (v != father)
			{
				low[u] = min(low[u], dfn[v]);
				if (dfn[u] > dfn[v])
					edge.push_back(Edge(u, v));
			}
		}
	}
}

int main(void)
{
	int u, v;
	int i;
	ntime = 1;
	scanf("%d %d", &n, &m);
	nblock = 0;
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		G[v].push_back(u);
		G[u].push_back(v);
	}
	memset(dfn, 0, sizeof(dfn));
	tarjan(1, 0);
	return 0;
}