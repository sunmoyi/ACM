#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 50010

using namespace std;

vector<int>G[maxn];
int dp[maxn][505], n, k, ans;

void dfs(int now, int fa)
{
	for (int i = 1; i <= k; i++)
		dp[now][i] = 0;
	dp[now][0] = 1;

	for (int i = 0; i < G[now].size(); i++)
	{
		int u = G[now][i];
		if (u == fa)
			continue;
		dfs(u, now);
		for (int j = 0; j < k; j++)
			ans += dp[u][j] * dp[now][k - j - 1];
		for (int j = 1; j <= k; j++)
			dp[now][j] += dp[u][j - 1];
	}
}

int main(void)
{
	scanf("%d %d", &n, &k);
	int a, b;
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	ans = 0;
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}