#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, dp[10005], sum[3] = { 150, 200, 350 };
int maxx;

int main(void)
{
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= 2; i++)
	{
		for (int j = sum[i]; j <= 10004; j++)
		{
			dp[j] = max(dp[j], dp[j - sum[i]] + sum[i]);
		}
	}
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d", &maxx);

			printf("%d\n", maxx - dp[maxx]);
		}
	}
}