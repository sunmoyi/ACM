#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long maxx, n;
long long num[2005];
long long dp[2005][1005];

int main(void)
{
	while (scanf_s("%lld %lld", &maxx, &n) != EOF)
	{
		for (int i = 1; i <= maxx; i++)
			scanf_s("%lld", &num[i]);

		sort(num + 1, num + maxx + 1);
		//memset(dp, 0, sizeof(dp));
		dp[1][1] = INT_MAX;
		for (int i = 2; i <= maxx; i++)
		{
			for (int j = 1; j <= i / 2; j++)
			{
				if (i == j * 2)
					dp[i][j] = dp[i - 2][j - 1] +
						(num[i - 1] - num[i])* (num[i - 1] - num[i]);
				else
					dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] +
								   (num[i - 1] - num[i])* (num[i - 1] - num[i]));
			}
		}
		printf("%lld\n", dp[maxx][n]);
	}
	return 0;
}
