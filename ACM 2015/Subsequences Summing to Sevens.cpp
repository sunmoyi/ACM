#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long sum, num[50010];
int mod[50010];
int summ[50010];
int dp[10];

int main (void)
{
	while (scanf("%lld", &sum) != EOF)
	{
		for (int i = 1; i <= sum; i++)
		{
			scanf("%lld", &num[i]);
			mod[i] = num[i] % 7;
			summ[i] = summ[i - 1] + mod[i];
			summ[i] %= 7;
		}

		memset(dp, 0, sizeof(dp));
		int maxx = 0;
		for (int i = 1; i <= sum; i++)
		{
			if (dp[summ[i]] == 0)
			{
				dp[summ[i]] = i;
				continue;
			}
			int ans = i - dp[summ[i]];
			maxx = max(maxx, ans);
			//dp[summ[i]] = i;
		}
		if (maxx == 0)
			maxx = max(maxx, dp[0]);
		printf("%d\n", maxx);
	}
	return 0;
}