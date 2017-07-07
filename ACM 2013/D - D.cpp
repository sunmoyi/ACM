#include <cstdio>  
#include <cstring>  
#include <algorithm>  

using namespace std;

int dp[25][4];
int a[25][4];
int n, t;

int main(void)
{
	
	while (scanf("%d", &t) != EOF)
	{
		for (int k = 1; k <= t; k++)
		{
			scanf("%d", &n);
			memset(a, 0, sizeof(a));
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= 3; j++)
					scanf("%d", &a[i][j]);
			}
			for (int i = 1; i <= n; i++)
			{
				for (int j = 3; j < 6; j++)
				{
					dp[i][j % 3 + 1] = a[i][j % 3 + 1] + min(dp[i - 1][(j - 1) % 3 + 1], dp[i - 1][(j + 1) % 3 + 1]);
				}
			}
			printf("Case %d: %d\n", k, min(dp[n][1], min(dp[n][2], dp[n][3])));
		}
	}
	return 0;
}