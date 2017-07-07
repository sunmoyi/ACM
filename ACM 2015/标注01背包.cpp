#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[13010];
int w[3510], d[3510];

int main(void)
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &w[i], &d[i]);
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
		{
			for (int j = m; j >= w[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
			}
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}