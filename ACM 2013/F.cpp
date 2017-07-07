#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

long long dp[1000010];

int main(void)
{
	long long ans;
	dp[0] = 1;
	for (long long i = 0; (ans = pow(2, i)) < 1000010; i++)
	{
		for (int j = ans; j < 1000010; j++)
		{
			dp[j] += (dp[j - ans]);
			dp[j] %= 1000000007;
		}
	}
	int k;
	while (scanf("%d", &k) != EOF)
	{
		printf("%lld\n", dp[k]);
	}
	return 0;
}