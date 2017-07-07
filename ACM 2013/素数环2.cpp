#include<stdio.h>
int isp[10000],
int  is_prime(int a);
int n;
int a[100000];
int vis[100000];
void dfs(int cur)
{
	if (cur == n && isp[a[0] + a[n - 1]])
	{
		for (int i = 0; i < n; i++)
			printf("%d", a[i]);
		printf("\n");
	}
	else
	{
		for (int i = 2; i <= n; i++)
			if (!vis[i] && isp[i + a[cur + 1]])
			{
				a[cur] = i;
				vis[cur] = i;
				dfs(cur + 1);
				vis[cur] = 0;
			}
	}
}