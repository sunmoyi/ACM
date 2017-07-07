#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0xfffffff
using namespace std;

int n, hire, fire, sala, minn, temp;
int maxx, g[15], dp[15][1000];

int main(void)
{
	while (scanf_s("%d", &n) != EOF && n)
	{
		scanf_s("%d %d %d", &hire, &sala, &fire);
		maxx = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%d", &g[i]);
			maxx = max(maxx, g[i]);
		}

		memset(dp, 0, sizeof(dp));
		for (int i = g[1]; i <= maxx; i++)
			dp[1][i] = (hire + sala) * i;
		for (int i = 2; i <= n; i++)
		{
			for (int j = g[i]; j <= maxx; j++)
			{
				minn = INF;
				for (int k = g[i - 1]; k <= maxx; k++)
				{
					if (k > j)
						temp = dp[i - 1][k] + fire * (k - j) + sala * j;
					else
						temp = dp[i - 1][k] + hire * (j - k) + sala * j;
					if (temp < minn)
						minn = temp;
				}
				dp[i][j] = minn;
			}
		}

		minn = INF;
		for (int i = g[n]; i <= maxx; i++)
		{
			minn = min(minn, dp[n][i]);
		}
		printf("%d\n", minn);
	}
	return 0;
}