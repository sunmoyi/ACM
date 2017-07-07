#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

int n, k, a[maxn][maxn], b[maxn][maxn], dp[maxn];

bool check(int x, int y)
{
	for (int i = 2; i <= k; i++)
		if (b[i][x] < b[i][y])
			return false;
	return true;
}

int main(void)
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			b[i][a[i][j]] = j;
		}
	}

	for (int i = 1; i <= n; i++)
		dp[i] = 1;

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (check(a[1][i], a[1][j]))
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}