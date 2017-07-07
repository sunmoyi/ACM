#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5010

using namespace std;

int n, m, k;
long long num[maxn];
long long dp[maxn][maxn];

int main(void)
{
	while (scanf("%d %d %d", &n, &m, &k) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &num[i]);
			num[i] += num[i - 1];
		}
		memset(dp, 0, sizeof(dp));
		for (int i = m; i <= n; i++)
			for (int j = 1; j <= k; j++)
				dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + num[i] - num[i - m]);
		printf("%lld\n", dp[n][k]);
	}
	return 0;
}