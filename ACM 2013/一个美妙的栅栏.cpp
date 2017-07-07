#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 25

using namespace std;

long long dp[maxn][maxn][2];

void init(int n)
{
	memset(dp, 0, sizeof(dp));
	dp[1][1][0] = 1;//up
	dp[1][1][1] = 1;//down
	for (int j = 2; j <= n; j++)
	{
		for (int i = 1; i <= j; i++)
		{
			for (int x = i; x < j; x++)
				dp[i][j][0] += dp[x][j - 1][1];
			for (int x = 1; x < i; x++)
				dp[i][j][1] += dp[x][j - 1][0];
		}
	}
}

int ans[maxn];

void solve(int n, long long c)
{
	int tn = n;
	int flag, cur;
	long long sum = 0LL;
	for (int i = 1; i <= n; i++)
	{
		if (sum + dp[i][n][0] + dp[i][n][1] >= c)
		{
			ans[1] = i;
			c -= sum;
			cur = i;
			break;
		}
		sum += (dp[i][n][0] + dp[i][n][1]);
	}
	if (c < dp[cur][n][1])
		flag = 1;
	else
	{
		c -= dp[cur][n][1];
		flag = 0;
	}
	--n;
	int len = 2;
	while (n > 0)
	{
		if (flag == 0)
		{
			for (int i = cur; i <= n; i++)
			{
				if (dp[i][n][1] >= c)
				{
					cur = i;
					ans[len++] = cur;
					break;
				}
				c -= dp[i][n][1];
			}
		}
		else
		{
			for (int i = 1; i<cur; i++)
			{
				if (dp[i][n][0] >= c)
				{
					cur = i;
					ans[len++] = cur;
					break;
				}
				c -= dp[i][n][0];
			}
		}
		--n;
		flag = 1 - flag;
	}
	int vis[maxn] = { 0 };
	for (int i = 1; i <= tn; i++)
	{
		for (int j = 1; j <= tn; j++)
		{
			if (vis[j] == 0)
			{
				ans[i]--;
				if (ans[i] == 0)
				{
					printf("%d%c", j, i == tn ? '\n' : ' ');
					vis[j] = 1;
					break;
				}
			}
		}
	}
}

int main(void)
{
	int T, n;
	long long c;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %lld", &n, &c);
		solve(n, c);
	}
	return 0;
}