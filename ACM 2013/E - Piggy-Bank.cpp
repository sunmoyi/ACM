#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, minn, maxx, dp[10050], w[505], v[505], n;

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d", &minn, &maxx);
			scanf_s("%d", &n);
			for (int i = 1; i <= n; i++)
			{
				scanf_s("%d %d", &v[i], &w[i]);
			}

			for (int i = 1; i <= 10049; i++)
				dp[i] = 10000000;
			dp[0] = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = w[i]; j <= maxx - minn; j++)
				{
					dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
				}
			}
			if (dp[maxx - minn] == 10000000)
				printf("This is impossible.\n");
			else
				printf("The minimum amount of money in the piggy-bank is %d.\n", dp[maxx - minn]);
		}
	}
	return 0;
}