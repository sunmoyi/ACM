#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100
#define INF 0x3f3f3f3f

using namespace std;

int dp[maxn][maxn];
int num[maxn];
int s[maxn][maxn];

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
		for (int i = 0; i < n; i++)
		{
			s[i][i + 2] = i + 1;
			dp[i][i + 2] = num[i + 2] - num[i];
		}

		for (int i = 3; i <= n + 1; i++)
		{
			for (int j = 0; j + i <= n + 1; j++)
			{
				int minn = INF;
				int t = i + j;
				for (int k = s[j][t - 1]; k <= s[j + 1][t]; k++)
				{
					int temp = dp[j][k] + dp[k][t] + num[t] - num[j];
					if (temp < minn)
					{
						minn = temp;
						s[j][t] = k;
					}
				}
				dp[j][t] = minn;
			}
		}
		printf("The minimum cutting is %d.\n", dp[0][n + 1]);
	}
	return 0;
}