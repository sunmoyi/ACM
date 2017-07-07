#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

int n, a[maxn], dp[maxn][maxn];

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		memset(dp, 0, sizeof(dp));
		for (int i = 2; i <= n - 1; i++)
			dp[i][i] = a[i - 1] * a[i] * a[i + 1];
		for (int l = 2; l <= n - 2; l++)
		{
			for (int i = 2; i + l <= n; i++)
			{
				int j = i + l - 1;
				dp[i][j] = INF;
				for (int k = i; k <= j; k++)
					dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[i - 1] * a[k] * a[j + 1]);
			}
		}
		printf("%d\n", dp[2][n - 1]);
	}
	return 0;
}