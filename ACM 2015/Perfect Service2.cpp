#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 10010

using namespace std;

vector<int>G[maxn];
int dp[maxn][3];
int vis[maxn];

int DP(int u)
{
	vis[u] = 1;
	dp[u][0] = 1, dp[u][1] = 0, dp[u][2] = maxn;
	queue<int>Q;
	for (int i = 0; i < G[u].size(); i++)
	{
		if (!vis[G[u][i]])
		{
			DP(G[u][i]);
			Q.push(G[u][i]);
			dp[u][0] += min(dp[G[u][i]][0], dp[G[u][i]][1]);
			dp[u][1] += dp[G[u][i]][2];
		}
	}
	while (!Q.empty())
	{
		dp[u][2] = min(dp[u][2], dp[u][1] - dp[Q.front()][2] + dp[Q.front()][0]);
		Q.pop();
	}
	return 0;
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF && n != -1)
	{
		if (!n)
			continue;
		for (int i = 1; i <= n; i++)
			G[i].clear();
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		DP(1);
		printf("%d\n", min(dp[1][0], dp[1][2]));
	}
	return 0;
}