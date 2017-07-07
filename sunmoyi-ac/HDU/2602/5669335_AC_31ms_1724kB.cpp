#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, n, v, w[1005], m[1005];
int dp[1005];

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d", &n, &v);
			for (int i = 1; i <= n; i++)
				scanf_s("%d", &w[i]);
			for (int i = 1; i <= n; i++)
				scanf_s("%d", &m[i]);// ti ji

			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; i++)
			{
				for (int j = v; j >= m[i]; j--)
				{
					dp[j] = max(dp[j], dp[j - m[i]] + w[i]);
				}
			}
			printf("%d\n", dp[v]);
		}
	}
	return 0;
}