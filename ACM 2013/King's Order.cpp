#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long  ans, n, dp[2005][4];

int main(void)
{
	while (scanf_s("%lld", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%lld", &n);

			memset(dp, 0, sizeof(dp));

			dp[1][0] = 26;
			dp[1][1] = 0;
			dp[1][2] = 0;

			for (int i = 2; i <= n; i++)
			{
				dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][0]) * 25 % 1000000007;
				dp[i][1] = dp[i - 1][0];
				dp[i][2] = dp[i - 1][1];
			}

			long long  sum = 0;
			sum = (sum + dp[n][0]) % 1000000007;
			sum = (sum + dp[n][1]) % 1000000007;
			sum = (sum + dp[n][2]) % 1000000007;
			printf("%d\n", sum % 1000000007);
		}
	}
	return 0;
}