#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long sum, num[1010];
long long dp[1010];

int main(void)
{
	while (scanf_s("%lld", &sum) != EOF && sum)
	{
		for (int i = 1; i <= sum; i++)
			scanf_s("%lld", &num[i]);

		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= sum; i++)
		{
			dp[i] = num[i];
			for (int j = 1; j < i; j++)
			{
				if (num[j] < num[i])
					dp[i] = max(dp[i], dp[j] + num[i]);
			}
		}
		long long maxx = 0;
		for (int i = 1; i <= sum; i++)
		{
			maxx = max(maxx, dp[i]);
		}
		printf("%lld\n", maxx); 
	}
	return 0;
}