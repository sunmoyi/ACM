#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100
#define INF 0x3f3f3f3f

using namespace std;

int dp[maxn][maxn];
int num[maxn];

int main(void)
{
	int L, n;
	while (scanf("%d", &L) != EOF && L)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);

		num[0] = 0;
		num[n + 1] = L;
		memset(dp, 0, sizeof(dp));
		for (int p = 1; p <= n + 1; p++)
		{
			for (int i = 0; i <= n + 1; i++)
			{
				int j = i + p;
				if (j > n + 1)
					break;
				int minn = INF;
				for (int k = i + 1; k < j; k++)
				{
					minn = min(minn, dp[i][k] + dp[k][j] + num[j] - num[i]);
				}
				if(minn != INF)
					dp[i][j] = minn;
			}
		}
		printf("The minimum cutting is %d.\n", dp[0][n + 1]);
	}
	return 0;
}