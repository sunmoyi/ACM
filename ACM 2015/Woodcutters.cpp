#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define INF 2000000007

using namespace std;

int dp[maxn];//dp[i]砍到i棵树的最小长度
int x[maxn];
int h[maxn];
int n;

int BS(int x)
{
	int l = 0, r = n, mid;
	while (l != r)
	{
		mid = (l + r + 1) >> 1;
		if (dp[mid] < x)
			l = mid;
		else
			r = mid - 1;
	}
	return l ;
}

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			dp[i] = INF;
		dp[0] = -INF;
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &x[i], &h[i]);
		for (int i = 1; i <= n; i++)
		{
			int id = BS(x[i]) + 1;
			if (i == n || x[i] + h[i] < x[i + 1])
				dp[id] = min(dp[id], x[i] + h[i]);
			id = BS(x[i] - h[i]) + 1;
			if (i == 1 || (x[i] - h[i] > x[i - 1]))
				dp[id] = min(dp[id], x[i]);
		}
		int ans = 0;
		for (int i = n; i >= 1; i--)
		{
			if (dp[i] != INF)
			{
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}