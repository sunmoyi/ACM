#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 200

using namespace std;

vector<vector<int>>G(maxn);
bool visited[maxn];
int dfn[maxn];
int low[maxn];
int father[maxn];
bool cut[maxn];
int ntime;
int n, m;

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
	int nrootsons = 0;
	int i;
	tarjan(1, 0);
	for (int i = 1; i <= n; i++)
	{
		int v = father[i];
		if (v == 1)
			nrootsons++;
		else
		{
			if (dfn[v] <= low[i])
				cut[v] = true;
		}
	}
	if (nrootsons > 1)
		cut[1] = true;
	for (i = 1; i <= n; i++)
		if (cut[i])
			printf("%d\n", i);
	for (int i = 1; i <= n; i++)
	{
		int v = father[i];
		if (v > 0 && dfn[v] < low[i])
			printf("%d, %d\n", v, i);
	}
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