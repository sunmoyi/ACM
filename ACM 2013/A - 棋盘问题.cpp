#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;
char map[10][10];
bool vis[10];
int ans;
void dfs(int a, int num)
{
	if (num == m)
	{
		ans++;
		return;
	}
	else
	{
		for (int i = a + 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] == '#' && vis[j] == false)
				{
					vis[j] = true;
					dfs(i, num + 1);
					vis[j] = false;
				}
			}
		}
	}
	return;
}
int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && (n + m ) != -2)
	{
		ans = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
		{
			getchar();
			for (int j = 1; j <= n; j++)
				scanf("%c", &map[i][j]);
		}
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}