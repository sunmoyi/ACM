#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 10000
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
				linker[v] = u;
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
	int num1, num, a;
	while (scanf("%d", &V) != EOF)
	{
		for (int i = 0; i < maxn; i++)
			G[i].clear();
		for (int i = 0; i < V; i++)
		{
			scanf("%d", &num1);
			getchar();
			getchar();
			getchar();
			scanf("%d", &num);
			getchar();
			for (int j = 1; j <= num; j++)
			{
				scanf("%d", &a);
				G[num1].push_back(a);
			}
		}
		int ans = hungry();
		printf("%d\n", V - ans / 2);
	}
	return 0;
}