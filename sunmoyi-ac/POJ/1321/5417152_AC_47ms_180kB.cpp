#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char map[10][10];
bool vis[10];
int a, b;
int ans;

void dfs(int n, int cur)
{
	if (cur == b)
	{
		ans++;
		return;
	}
	else
	{
		for (int i = n ; i <= a; i++)
		{
			for (int j = 1; j <= a; j++)
			{
				if (map[i][j] == '#' && !vis[j])
				{
					vis[j] = true;
					dfs(i + 1, cur + 1);
					vis[j] = false;
				}
			}
		}
	}
	return;
}

int main(void)
{
	while (scanf("%d %d", &a, &b) != EOF && (a + b) != -2)
	{
		ans = 0;
		memset(vis, 0, sizeof(vis));
		getchar();
		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= a; j++)
			{
				scanf("%c", &map[i][j]);
			}
			getchar();
		}
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}