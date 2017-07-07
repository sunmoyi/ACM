/*#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 30
#define INF 0x3f3f3f3f

using namespace std;

int n, m, dp[maxn][maxn][maxn][maxn];
bool has[maxn][maxn];

int sum(int u, int d, int l, int r)
{
	int ans = 0;
	for(int i = u + 1; i <= d; i++)
	{
		for (int j = l + 1; j <= r; j++)
		{
			if (has[i][j])
				ans++;
			if (ans == 2)
				return 2;
		}
	}
	return ans;
}

int dfs(int u, int d, int l, int r)
{
	if (dp[u][d][l][r] != -1)
		return dp[u][d][l][r];
	int total = sum(u, d, l, r);
	if (total == 1)
		return dp[u][d][l][r] = 0;
	if (total == 0)
		return dp[u][d][l][r] = INF;
	dp[u][d][l][r] = INF;
	for (int i = u + 1; i < d; i++)
		dp[u][d][l][r] = min(dp[u][d][l][r], dfs(u, i, l, r) + dfs(i, d, l, r) + r - l);
	for (int i = l + 1; i <= r; i++)
		dp[u][d][l][r] = min(dp[u][d][l][r], dfs(u, d, l, i) + dfs(u, d, i, r) + d - u);
	return dp[u][d][l][r];
}

int main(void)
{
	int k, x, y, icase = 0;
	while (scanf("%d %d %d", &n, &m, &k) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		memset(has, 0, sizeof(has));
		for (int i = 0; i < k; i++)
		{
			scanf("%d %d", &x, &y);
			has[x][y] = true;
		}
		printf("Case %d: %d\n", ++icase, dfs(0, n, 0, m));
	}
	return 0;
}*/