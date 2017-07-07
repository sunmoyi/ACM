#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
bool vis[20];
int a[20];

bool isprimer(int m)
{
	bool flag = true;
	if (m == 1 || m == 2)
		return true;
	for (int i = 2; i < m; i++)
	{
		if (m % i == 0)
			return false;
	}
	return true;
}

int dfs(int ans)
{
	if (ans == n && isprimer(a[1] + a[n]))
	{
		for (int i = 1; i < n; i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n]);
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (!vis[i] && isprimer(a[ans] + i))
			{
				vis[i] = true;
				a[ans + 1] = i;
				dfs(ans + 1);
				vis[i] = false;
			}
		}
	}
}

int main(void)
{
	int ans = 1;
	while (scanf("%d", &n) != EOF)
	{
		if (ans != 1)
			printf("\n");
		memset(vis, 0, sizeof(vis));
		memset(a, 0, sizeof(a));
		a[1] = 1;
		printf("Case %d:\n", ans++);
		dfs(1);
	}
	return 0;
}