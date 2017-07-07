#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, n, m, v;
int N[105], V[105];
int dp[105][1005];

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d %d", &n, &m, &v);
			for (int i = 0; i < n; i++)
			{
				scanf_s("%d %d", &N[i], &V[i]);//N时常   V价值
			}
			for (int i = 0; i <= m; i++)
			{
				for (int j = 0; j <= v; j++)
				{
					if (i == 0)
						dp[i][j] = 0;
					else
						dp[i][j] = -9999999;
				}
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = m; j >= 1; j--)
				{
					for (int t = v; t >= N[i]; t--)
					{
						dp[j][t] = max(dp[j][t], dp[j - 1][t - N[i]] + V[i]);
					}
				}
			}
			printf("%d\n", dp[m][v] > 0 ? dp[m][v]: 0);
		}
	}
	return 0;
}