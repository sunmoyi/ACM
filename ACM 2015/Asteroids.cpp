#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 510
#define INF 0x3f3f3f3f

using namespace std;

int linker[maxn];
bool used[maxn];
vector<int>G[maxn];
int V, E, a, b;

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
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungry(void)
{
	int ans = 0;
	memset(linker, -1, sizeof(linker));
	for (int u = 1; u <= V; u++)
	{
		memset(used, 0, sizeof(used));
		if (dfs(u))
			ans++;
	}
	return ans;
}

int main(void)
{
	while (scanf("%d %d", &V, &E) != EOF)
	{
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
		}
		int ans = hungry();
		printf("%d\n", ans);
	}
	return 0;
}