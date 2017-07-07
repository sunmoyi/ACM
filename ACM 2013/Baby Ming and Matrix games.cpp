#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int map[20][20];
bool vis[20][20];
int t, n, m;
long long sum;

bool dfs(int a, int b, long long summ)
{
	if (summ == sum)
		return true;

	if (a + 2 < n && vis[a + 2][b] == false)
	{
		vis[a + 2][b] = true;
		if (map[a + 1][b] == 43)
			dfs(a + 2, b, map[a][b] - '0' + map[a + 2][b] - '0');
		if (map[a + 1][b] == 45)
			dfs(a + 2, b, map[a][b] - '0' - map[a + 2][b] - '0');
		if (map[a + 1][b] == 42)
			dfs(a + 2, b, (map[a][b] - '0' )* (map[a + 2][b] - '0'));
		if (map[a + 1][b] == 43)
			dfs(a + 2, b, map[a][b] - '0' + map[a + 2][b] - '0');
		vis[a + 2][b] = false;
	}
	
}
int main(void)
{
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d %d %lld", &n, &m, &sum);
			for (int i = 0; i < n; i++)
			{
				getchar();
				for (int j = 0; j < m; j++)
				{
					scanf("%c", &map[i][j]);
				}
			}
			bool flag = false;
			for (int i = 0; i < n; i += 2)
			{
				for (int j = 0; j < m; j += 2)
				{
					memset(vis, 0, sizeof(vis));
					vis[i][j] = true;
					if (dfs(i, j, 0))
					{
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				printf("Possible\n");
			else
				printf("Impossible\n");
		}
	}
	return 0;
}