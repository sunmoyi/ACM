#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

int a[maxn], dp[maxn][4];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
		{
			dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
			dp[i][1] = dp[i][2] = INF;
		}
		else if (a[i] == 1)
		{
			dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = INF;
		}
		else if (a[i] == 2)
		{
			dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
			dp[i][1] = INF;
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		}
		else
		{
			dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		}
	}
	printf("%d\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
	return 0;
}