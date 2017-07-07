#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2200

using namespace std;

double dp[maxn][maxn], p;
int n, t;

int main(void)
{
	while (scanf("%d %lf %d", &n, &p, &t) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= t; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (j == n)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j] * (1 - p);
				if (j)
					dp[i][j] += dp[i - 1][j - 1] * p;
			}
		}
		double ans = 0;
		for (int i = 1; i <= n; i++)
			ans += dp[t][i] * i;
		printf("%lf\n", ans);
	}
	return 0;
}