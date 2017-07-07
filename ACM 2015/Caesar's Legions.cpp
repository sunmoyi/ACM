#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define mod 100000000

using namespace std;

int n1, n2, k1, k2;
int dp[maxn][maxn][2];

int main(void)
{
	while (scanf("%d %d %d %d", &n1, &n2, &k1, &k2) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= k1; i++)
			dp[i][0][0] = 1;
		for (int j = 1; j <= k2; j++)
			dp[0][j][1] = 1;

		for (int i = 1; i <= n1; i++)
		{
			for (int j = 1; j <= n2; j++)
			{
				for (int k = 1; k <= min(k1, i); k++)
					dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % mod;
				for (int k = 1; k <= min(k2, j); k++)
					dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % mod;
			}
		}
		long long sum = (dp[n1][n2][0] + dp[n1][n2][1]) % mod;
		printf("%lld\n", sum);
	}
	return 0;
}