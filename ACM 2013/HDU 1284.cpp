#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long dp[32770], ans;

int main(void)
{
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = i; j <= 32769; j++)
		{
			dp[j] += dp[j - i];
		}
	}
	while (scanf_s("%lld", &ans) != EOF)
	{
		printf("%lld\n", dp[ans]);
	}
}