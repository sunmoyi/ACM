#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, maxx, money[105];
double rankk, rate[105];
double dp[10005];
int total;

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			total = 0;
			scanf_s("%lf %d", &rankk, &maxx);
			for (int i = 1; i <= maxx; i++)
			{
				scanf_s("%d %lf", &money[i], &rate[i]);
				total += money[i];
			}
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;

			for (int i = 1; i <= maxx; i++)
			{
				for (int j = total; j >= money[i]; j--)
				{
					dp[j] = max(dp[j], dp[j - money[i]] * (1 - rate[i]));
				}
			}

			for (int i = total; i >= 0; i--)
			{
				if (dp[i] >= (1 - rankk))
				{
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}