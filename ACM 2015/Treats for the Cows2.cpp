#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2010

using namespace std;

int a[maxn], dp[maxn][maxn];

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= n; i++)
			dp[i][i] = a[i] * n;
		for(int l = 1; l < n; l++)
		{
			for (int i = 1; i + l <= n; i++)
			{
				int j = i + l;
				dp[i][j] = max(dp[i + 1][j] + (n - l) * a[i], dp[i][j - 1] + (n - l) * a[j]);
			}
		}
		printf("%d\n", dp[1][n]);
	}
	return 0;
}