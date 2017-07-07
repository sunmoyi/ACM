#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char map[10][10];
int vis[10];
int n, m, cnt;

void dfs(int line, int cur)
{
	int i, j;
	if (cur == m)
	{
		cnt++;
		return;
	}
	else
	{
		for (i = line + 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (map[i][j] == '#' && vis[j] == 0)
				{
					vis[j] = 1;
					dfs(i, cur + 1);
					vis[j] = 0;
				}
			}
		}
	}
}

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && n != -1 || m != -1)
	{
		getchar();
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%c", &map[i][j]);
			}
			getchar();
		}
		dfs(0, 0);
		printf("%d\n", cnt);
	}
	return 0;
}