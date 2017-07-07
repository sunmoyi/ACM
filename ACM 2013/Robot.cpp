#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, s, dp[2000010];

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			memset(dp, 0, sizeof(dp));
			dp[1000000] = 1, dp[1000000 - 1] = 1, dp[1000000 + 1] = 1;
			scanf_s("%d", &s);
			for (int i = 2; i <= s; i++)
			{
				for (int j = (-s) + 1000000; j <= (s) + 1000000; j++)
				{
					if (j > 0)
						dp[j] += (dp[j - 1] + dp[j] + dp[j + 1]) % 1000000007;
					else
						dp[j] += (dp[j - 1] + dp[j]) % 1000000007;
				}
			}
			printf("%d\n", dp[1000000]);
		}
	}
	return 0;
}