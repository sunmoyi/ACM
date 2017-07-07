#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 5050
#define INF 0x3f3f3f3f

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
	for (int u = 1; u <= V; u++)
	{
		memset(used, 0, sizeof(used));
		if (dfs(u))
			res++;
	}
	return res;
}

int main(void)
{
	int T, a, b;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d", &V);
			for (int i = 0; i <= V + 1; i++)
				G[i].clear();
			E = V * 3 / 2;
			for (int i = 1; i <= E; i++)
			{
				scanf("%d %d", &a, &b);
				G[a].push_back(b);
				G[b].push_back(a);
			}
			int ans = hungry();
			//printf("%d\n", ans);
			printf("%d\n", V - ans / 2);
		}
	}
	return 0;
}