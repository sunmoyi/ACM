#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int a[15];
int G[15][15];
int g[15][15];

int uN, vN;
int linker[15];
bool used[15];

bool dfs(int u)
{
	for (int v = 1; v <= vN; v++)
	{
		if (g[u][v] && !used[v])
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

int hungry()
{
	int res = 0;
	memset(linker, -1, sizeof linker);
	for (int u = 1; u <= uN; u++)
	{
		memset(used, false, sizeof used);
		if (dfs(u)) res++;
	}
	return res;
}

int main(void)
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0)
		{
			printf("0\n");
			continue;
		}
		memset(G, 0, sizeof G);
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			G[a][b] = 1;
		}
		uN = vN = n;
		int ans = 100;
		for (int i = 1; i <= n; i++)
			a[i] = i;
		do {
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					g[i][j] = 0;
					if (j == n)
					{
						if (!G[i][a[j]] && !G[i][1])
							g[i][j] = 1;
					}
					else if (!G[i][a[j]] && !G[i][a[j + 1]])
						g[i][j] = 1;
				}
			}
			int num = hungry();
			ans = min(ans, n - num);
		} while (next_permutation(a + 2, a + n + 1));
		printf("%d\n", ans);
	}
	return 0;
}