#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define mod 1000000007

using namespace std;

long long dp[maxn], sum[maxn];
long long t, k, a, b;

int main(void)
{
	while (scanf("%lld %lld", &t, &k) != EOF)
	{
		for (int i = 0; i < maxn; i++)
		{
			dp[i] = 1;
			sum[i] = i;
		}
		sum[0] = 0;
		for (int i = k; i < maxn; i++)
		{
			dp[i] = dp[i - 1] + dp[i - k];
			dp[i] %= mod;
			sum[i] = (sum[i - 1] + dp[i]) % mod;
		}

		while (t--)
		{
			scanf("%lld %lld", &a, &b);
			printf("%lld\n", (sum[b] - sum[a - 1] + mod) % mod);
		}
	}
	return 0;
}