#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define mod 1000000007

using namespace std;

int n, p[maxn];
long long dp[maxn];

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		dp[1] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &p[i]);
			dp[i + 1] = (2 * dp[i] + 2 - dp[p[i]] + mod) % mod;
		}
		printf("%lld\n", dp[n + 1]);
	}
	return 0;
}