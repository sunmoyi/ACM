#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

int ans, n;
char p[maxn][maxn];
int dp[maxn][maxn];

int main(void)
{
	while (scanf("%d", &n) != EOF && n)
	{
		ans = 1;
		for (int i = 0; i < n; i++)
			scanf("%s", p[i]);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 || j == n - 1)
					dp[i][j] = 1;
				else
				{
					int t1 = i, t2 = j;
					while (t1 >= 0 && t2 <= n - 1 && p[t1][j] == p[i][t2])
					{
						t1--;
						t2++;
					}
					int t = i - t1;
					if (t > dp[i - 1][j + 1] + 1)
						dp[i][j] = dp[i - 1][j + 1] + 1;
					else
						dp[i][j] = t;
					ans = max(ans, dp[i][j]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}