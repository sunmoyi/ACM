#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long sum, num[100010], l[100005], r[100005];
long long dp[100005], maxx;

int main(void)
{
	while (scanf_s("%lld", &sum) != EOF && sum)
	{
		maxx = 0;
		memset(dp, 0, sizeof(dp));
		for (long long i = 1; i <= sum; i++)
			scanf_s("%lld", &num[i]);

		l[1] = 1, r[sum] = sum;

		for (long long i = 2; i <= sum; i++)
		{
			long long t = i;
			while (t > 1 && num[t - 1] >= num[i])
				t = l[t - 1];
			l[i] = t;
		}

		for (long long i = sum - 1; i >= 1; i--)
		{
			long long t = i;
			while (t < sum && num[t + 1] >= num[i])
				t = r[t + 1];
			r[i] = t;
		}

		for (long long i = 1; i <= sum; i++)
		{
			maxx = max(maxx, (r[i] - l[i] + 1) * num[i]);
		}

		printf("%lld\n", maxx);
	}
	return 0;
}