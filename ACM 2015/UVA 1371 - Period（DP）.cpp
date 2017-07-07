#include<cstdio>
#include <cstring>
#include<algorithm>
#define maxn 5010
#define maxm 60
#define INF 0x3f3f3f3f

using namespace std;

int t, n, m, dp[maxn][maxm];
char a[maxn], b[maxm];

bool judge(int mid)
{
	memset(dp, 0x42, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++)
	{
		if (dp[i][m] <= mid)
			dp[i][0] = 0;
		for (int j = 0; j <= m; j++)
		{
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (a[i + 1] != b[j + 1]));
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
		}
	}
	return dp[n][m] <= mid;
}

int main(void)
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", b + 1);
		scanf("%s", a + 1);
		n = strlen(a + 1);
		m = strlen(b + 1);
		int l = 0, r = m;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (judge(mid))
				r = mid;
			else
				l = mid + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}