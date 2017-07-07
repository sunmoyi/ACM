#include<cstdio>
#include<cstring>
#include<algorithm>
const int mod = 100000007;
using namespace std;

int n, m, t, v[55], num[55];
int dp[55][1005];

int main(void)
{
	while (scanf_s("%d", &t) != EOF)
	{
		for (int ss = 1; ss <= t; ss++)
		{
			scanf_s("%d %d", &n, &m);
			for (int i = 1; i <= n; i++)
				scanf_s("%d", &v[i]);
			for (int i = 1; i <= n; i++)
				scanf_s("%d", &num[i]);

			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;

			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j <= m; j++)
				{
					for (int k = 0; k <= num[i]; k++)
					{
						if (j - k * v[i] >= 0)
							dp[i][j] += dp[i - 1][j - k * v[i]];
						dp[i][j] %= mod;
					}
				}
			}
			printf("Case %d: %d\n", ss, dp[n][m]);
		}
	}
	return 0;
}