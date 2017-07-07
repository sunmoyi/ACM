#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, money, year, M[200], V[200];
int dp[100000], sum;

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d", &money, &year);
			scanf_s("%d", &sum);
			for (int i = 1; i <= sum; i++)
			{
				scanf_s("%d %d", &M[i], &V[i]);
				M[i] /= 1000;
			}

			for (int i = 1; i <= year; i++)
			{
				int s = money / 1000;
				memset(dp, 0, sizeof(dp));
				for (int j = 1; j <= sum; j++)
				{
					for (int k = M[j]; k <= s; k++)
					{
						dp[k] = max(dp[k], dp[k - M[j]] + V[j]);
					}
				}
				money += dp[s];
			}
			printf("%d\n", money);
		}
	}
	return 0;
}