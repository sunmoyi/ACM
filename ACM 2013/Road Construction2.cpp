#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1100

using namespace std;

vector<vector<int>>G(maxn);
bool visited[maxn];
int dfn[maxn];
int low[maxn];
int father[maxn];
bool cut[maxn];
int ntime;
int n, m;
int d[maxn], leave;

void tarjan(int u, int fathe)
{
	father[u] = fathe;
	low[u] = dfn[u] = ntime++;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!dfn[v])
		{
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}
		else if (fathe != v)
			low[u] = min(low[u], dfn[v]);
	}
}

void count()
{
	tarjan(1, 0);
	memset(d, 0, sizeof(d));
	leave = 0;
	for (int u = 1; u <= n; u++)
	{
		for (int i = 0; i < G[u].size(); i++)
		{
			if (low[u] != low[G[u][i]])
				d[low[u]]++;
		}
	}
	for (int i = 0; i <= n; i++)
		if (d[i] == 1)
			leave++;
	printf("%d\n", (leave + 1) / 2);
}

int main(void)
{
	int u, v;
	int i;

	ntime = 1;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		G[v].push_back(u);
		G[u].push_back(v);
	}
	memset(dfn, 0, sizeof(dfn));
	memset(father, 0, sizeof(father));
	memset(cut, 0, sizeof(cut));
	count();
	return 0;
}