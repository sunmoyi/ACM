#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2010
#define mod 1000000007

using namespace std;

long long dp[maxn][maxn];//dp[i][j] the last number is i, the lenth of the sequence is j
long long n, k;

int main(void)
{
	while (scanf("%lld %lld", &n, &k) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i < maxn; i++)
			dp[i][1] = 1;
		for (int j = 2; j <= k; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int p = i; p <= n; p += i)
				{
					dp[p][j] = (dp[p][j] + dp[i][j - 1]) % mod;
				}
			}
		}
		long long sum = 0;
		for (int i = 1; i <= n; i++)
			sum = (sum + dp[i][k]) % mod;
		printf("%lld\n", sum);
	}
	return 0;
}