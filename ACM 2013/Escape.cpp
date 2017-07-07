#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 100010;
const int maxm = 11;
int linker[maxn][maxm], g[maxn][maxm], cnt[maxm], capacity[maxn], n, m;
bool vis[maxm];

bool dfs(int x)
{
	for (int i = 0; i < m; i++)
	{
		if (g[x][i] == 0 || vis[i]) 
			continue;
		vis[i] = true;
		if (cnt[i] < capacity[i])
		{
			linker[i][cnt[i]++] = x;
			return true;
		}
		else
		{
			for (int j = 0; j < capacity[i]; j++)
			{
				if (dfs(linker[i][j]))
				{
					linker[i][j] = x;
					return true;
				}
			}
		}
	}
	return false;
}
bool hungary(int n)
{
	for (int i = 0; i < n; i++)
	{
		memset(vis, false, sizeof(bool)*(m));
		if (!dfs(i))
			return false;
	}
	return true;
}
int main()
{
	while (scanf_s("%d%d", &n, &m) != EOF)
	{
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf_s("%d", &g[i][j]);
			}
		}

		for (int i = 0; i < m; i++)
		{
			scanf_s("%d", &capacity[i]);
		}

		if (hungary(n) == true)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}