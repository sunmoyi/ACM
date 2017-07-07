#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, sum, num[1000010];
int kk[1000010];
int dp[1000010];

int main(void)
{
	while (scanf_s("%d %d", &n, &sum) != EOF)
	{
		for (int i = 1; i <= sum; i++)
			scanf_s("%d", &num[i]);

		memset(dp, 0, sizeof(dp));
		memset(kk, 0, sizeof(kk));

		int maxx;
		for (int i = 1; i <= n; i++)
		{
			maxx = -99999999;
			for (int j = i; j <= sum; j++)
			{
				dp[j] = max(dp[j - 1] + num[j], kk[j - 1] + num[j]);
				kk[j - 1] = maxx;
				maxx = max(maxx, dp[j]);
			}
		}
		printf("%d\n", maxx);
	}
	return 0;
}