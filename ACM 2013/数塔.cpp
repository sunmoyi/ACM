#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, sum, num[105][105];
int dp[105][105];

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d", &sum);
			for (int i = 1; i <= sum; i++)
				for (int j = 1; j <= i; j++)
					scanf_s("%d", &num[i][j]);

			for (int i = 1; i <= sum; i++)
				dp[sum][i] = num[sum][i];

			for (int i = sum - 1; i >= 1; i--)
			{
				for (int j = 1; j <= i; j++)
				{
					dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
					dp[i][j] += num[i][j];
				}
			}
			printf("%d\n", dp[1][1]);
		}
	}
	return 0;
}