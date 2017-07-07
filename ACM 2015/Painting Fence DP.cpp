#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5010
#define INF 0x3f3f3f3f

using namespace std;

int value[maxn], dp[maxn][maxn];
int n;

int main(void)
{
	scanf("%d", &n);
	value[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &value[i]);
	for (int i = 0; i <= n; i++)
		dp[n][i] = 0;
	for (int i = n; i >= 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (value[j] >= value[i])
				dp[i - 1][j] = dp[i][i];
			else
				dp[i - 1][j] = min(dp[i][j] + 1, dp[i][i] + value[i] - value[j]);
		}
	}
	printf("%d\n", dp[0][0]);
}