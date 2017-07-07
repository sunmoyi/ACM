#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char map[10][10];
int vis[10];
int n, m, num, cnt;

void dfs(int cur, int line)
{
	if (cur == num)
	{
		cnt++;
		return;
	}
	else
	{
		if (line <= n)
		{
			for (int i = 1; i <= n; i++)
				if (map[line][i] == '#' && vis[i] == 0)
				{
					vis[i] = 1;
					dfs(cur + 1, line + 1);
					vis[i] = 0;
				}
		}
		if (line < n)
			dfs(cur, line + 1);
		else
			return;
	}
}

int main(void)
{
	while (scanf("%d %d", &n, &num) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		if (n == -1 && num == -1)
			break;
		getchar();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				scanf("%c", &map[i][j]);
			getchar();
		}
		dfs(0, 1);
		printf("%d\n", cnt);
	}
	return 0;
}