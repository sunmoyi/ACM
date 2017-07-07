#include<cstdio>  
#include<cstring>  
#include<iostream>  
using namespace std;
const int maxn = 10001;
int n, m, a[30], dp[maxn];
bool vis[maxn][30];
int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i<m; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i<m; i++)
			for (int j = n; j >= a[i]; j--)
				if (dp[j] <= dp[j - a[i]] + a[i])
				{
					dp[j] = dp[j - a[i]] + a[i];
					vis[j][i] = 1;
				}
		for (int i = m - 1, j = n; i >= 0; i--)
		{
			if (vis[j][i])
			{
				printf("%d ", a[i]);
				j -= a[i];
			}
		}
		printf("sum:%d\n", dp[n]);
	}
	return 0;
}