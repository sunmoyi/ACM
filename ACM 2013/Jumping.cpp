#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0xfffffff

using namespace std;

long long dp[1005], a[1005];
int sum;

int main(void)
{
	while (scanf_s("%d", &sum) != EOF && sum)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= sum; i++)
			scanf_s("%d", &a[i]);

		dp[0] = 0;
		long long maxx = 0;
		for (int i = 1; i <= sum; i++)
		{
			long long tmax = 0;
			if (a[i] <= 0)
			{
				dp[i] = 0;
				continue;
			}
			for(int j = 0; j <= i; j++)
			{
				if (a[j] < a[i] && a[j] >= 0 && dp[j] + a[i] > tmax)
					tmax = dp[j] + a[i];
			}
			dp[i] = tmax;
			if (tmax > maxx)
				maxx = tmax;
		}
		printf("%lld\n", maxx);
	}
	return 0;
}