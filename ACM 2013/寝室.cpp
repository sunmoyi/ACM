#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2005
#define INF 0xfffffff

using namespace std;

int dp[maxn][1005];
int val[maxn] = { 0 };
int n, m;

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &val[i]);
		sort(val + 1, val + n + 1);
		for (int i = 0; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] = INF;
			}
		}
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j * 2 <= i; j++)
			{
				dp[i][j] = min(dp[i - 2][j - 1] + (val[i] * val[i - 1]) * (val[i] - val[i - 1]), dp[i - 1][j]);
			}
		}
		printf("%d\n", dp[n][m]);
	}
}