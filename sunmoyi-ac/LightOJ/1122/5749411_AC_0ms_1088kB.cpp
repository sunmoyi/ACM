#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t;
int ans, len;
int num[15];
bool findd[15];
int dp[15][15];


int main(void)
{
	while (scanf("%d", &t) != EOF)
	{
		for (int ss = 1; ss <= t; ss++)
		{
			memset(findd, 0, sizeof(findd));
			memset(dp, 0, sizeof(dp));
			scanf("%d %d", &ans, &len);
			for (int i = 1; i <= ans; i++)
			{
				scanf("%d", &num[i]);
				findd[num[i]] = true;
				dp[1][num[i]] = 1;
			}

			for (int i = 2; i <= len; i++)
			{
				for (int j = 1; j <= 9; j++)
				{
					if (findd[j])
					{
						for (int k = j - 2; k <= j + 2; k++)
						{
							if (k >= 1 && k <= 9)
								dp[i][j] += dp[i - 1][k];
						}
					}
				}
			}
			int sum = 0;
			for (int i = 1; i <= 9; i++)
			{
				sum += dp[len][i];
			}
			printf("Case %d: %d\n", ss, sum);
		}
	}
	return 0;
}