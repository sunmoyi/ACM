#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans;
int n, m;
int num[25][1010];
int dp[25][1010];

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf("%d %d", &n, &m);
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					scanf("%d", &num[i][j]);

			for (int j = 0; j <= n; j++)
				dp[j][0] = -INT_MAX / 2 + 1;
			for (int j = 0; j <= m; j++)
				dp[0][j] = -INT_MAX / 2 + 1;
			dp[0][1] = dp[1][0] = 0;

			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					int temp = max(dp[i - 1][j], dp[i][j - 1]);
					for (int s = 2; s <= j; s++)
						if (!(j % s))
							temp = max(temp, dp[i][j / s]);
					dp[i][j] = temp + num[i][j];
				}
			}
			printf("%d\n", dp[n][m]);
		}
	}
	return 0;
}