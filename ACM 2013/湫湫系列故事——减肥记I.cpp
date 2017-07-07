#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, love[105], cal[105], maxx;
int dp[100005];

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		for (int i = 1; i <= ans; i++)
			scanf_s("%d %d", &love[i], &cal[i]);
		scanf_s("%d", &maxx);

		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= ans; i++)
		{
			for (int j = cal[i]; j <= maxx; j++)
			{
				dp[j] = max(dp[j], dp[j - cal[i]] + love[i]);
			}
		}
		printf("%d\n", dp[maxx]);
	}
	return 0;
}