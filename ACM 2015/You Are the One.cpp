#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 110
#define inf 0x7fffffff

using namespace std;

int dp[maxn][maxn];
int sum[maxn];
int a[maxn];
int n;

int main()
{
	int t, iCase = 1;
	scanf("%d", &t);
	while (t--) 
	{
		sum[0] = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++) 
			{
				dp[i][j] = inf;
			}
		}
		for (int p = 1; p <= n; p++)
		{
			for (int i = 1; i <= n - p + 1; i++)
			{
				int j = i + p - 1;
				for (int k = 1; k <= p; k++) 
				{
					dp[i][j] = min(dp[i][j],dp[i + 1][i + k - 1] + dp[i + k][j] + 
												(k - 1)*a[i] + 
												(sum[j] - sum[i + k - 1])*k);
				}
			}
		}
		printf("Case #%d: %d\n", iCase++, dp[1][n]);
	}
	return 0;
}