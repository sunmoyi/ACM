#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 10005
#define INF x0fffffff
using namespace std;

int linker[maxn];
bool used[maxn];
vector<int>G[maxn];
int V, E;

bool dfs(int u)
{
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!used[v])
		{
			used[v] = true;
			if (linker[v] == -1 || dfs(linker[v]))
			{
				linker[v] == u;
				return true;
			}
		}
	}
	return false;
}

int hungry(void)
{
	int res = 0;
	memset(linker, -1, sizeof(linker));
	for (int u = 0; u < V; u++)
	{
		memset(used, 0, sizeof(used));
		if (dfs(u))
			res++;
	}
	return res;
}

int main(void)
{
	int a, b;
	while (scanf("%d %d", &V, &E) != EOF)
	{
		for (int i = 1; i <= V; i++)
		{
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int ans = hungry();
		printf("%d\n", ans);
	}
	return 0;
}