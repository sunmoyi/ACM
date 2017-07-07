#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;
int num[1000010];
int dp[1000010];
int maxx[1000010], maxxx;

int main(void)
{
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= m; i++)
			scanf_s("%d", &num[i]);

		memset(dp, 0, sizeof(dp));
		memset(maxx, 0, sizeof(maxx));

		for (int i = 1; i <= n; i++)
		{
			maxxx = -99999999;
			for (int j = i; j <= m; j++)
			{
				dp[j] = max(dp[j - 1], maxx[j - 1]) + num[j];
				maxx[j - 1] = maxxx;
				maxxx = max(maxxx, dp[j]);
			}
		}
		printf("%d\n", maxxx);
	}
	return 0;
}