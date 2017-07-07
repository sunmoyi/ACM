#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long ans, sum, num[1005], val[1005], dp[1005], a[1005];

int main(void)
{
	scanf_s("%lld", &ans);
	while (ans--)
	{
		memset(a, 0, sizeof(a));
		scanf_s("%lld", &sum);
		for (int i = 1; i <= sum; i++)
		{
			scanf_s("%lld %lld", &num[i], &val[i]);
			a[i] = a[i - 1] + num[i];
		}

		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= sum; i++)
		{
			dp[i] = dp[i - 1] + (num[i] + 10) * val[i];
			for (int j = 0; j < i; j++)
			{
				dp[i] = min(dp[i], dp[j] + (a[i] - a[j] + 10) * val[i]);
			}
		}
		printf("%lld\n", dp[sum]);
	}

	return 0;
}