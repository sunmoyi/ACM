#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 510
#define INF 0x3f3f3f3f

using namespace std;

int a[maxn];
int n, vis[maxn];
int dp[maxn][maxn];

int getstep(int l1, int r1, int l2, int r2)
{
	priority_queue<int>q1, q2;
	for (int i = l1; i <= r1; i++)
		q1.push(a[i]);
	for (int i = l2; i <= r2; i++)
		q2.push(a[i]);
	int ans = 0;
	while (!q1.empty() && !q2.empty())
	{
		ans++;
		int t1 = q1.top();
		int t2 = q2.top();
		if (t1 > t2)
			q1.pop();
		else
			q2.pop();
	}
	return ans;
}

int dfs(int l, int r)
{
	if (dp[l][r] != -1)
		return dp[l][r];
	if (l == r)
		return dp[l][r] = 0;
	dp[l][r] = INF;
	for(int i = l + 1; i <= r; i++)
	{
		int step = getstep(l, i - 1, i, r);
		dp[l][r] = min(dp[l][r], dfs(l, i - 1) + dfs(i, r) + step);
	}
	return dp[l][r];
}

int solve()
{
	int l = 0, ans = 0;
	memset(dp, -1, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	vis[a[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		if (vis[a[i]])
		{
			for (int j = 1; j <= i - l; j++)
				if (!vis[j])
					return INF;
			ans += dfs(l, i - 1);
			memset(vis, 0, sizeof(vis));
			vis[a[i]] = 1;
			l = i;
		}
		else
			vis[a[i]] = 1;
	}
	for (int i = 1; i <= n - l; i++)
		if (!vis[i])
			return INF;
	ans += dfs(l, n - 1);
	return ans;
}

int main (void)
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int ans = solve();
		if (ans == INF)
			printf("impossible\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}