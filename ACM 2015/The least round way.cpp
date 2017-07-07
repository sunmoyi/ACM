#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1050

using namespace std;

int m[2][maxn][maxn];
int dp[2][maxn][maxn];
int vis[2][maxn][maxn];
int n;

int solve(int mark)
{
	vis[mark][1][1] = 0;
	dp[mark][1][1] = m[mark][1][1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 1 && j == 1)
				continue;
			if (i == 1)
			{
				dp[mark][i][j] = dp[mark][i][j - 1] + m[mark][i][j];
				vis[mark][i][j] = 1;
			}
			else if (j == 1)
			{
				dp[mark][i][j] = dp[mark][i - 1][j] + m[mark][i][j];
				vis[mark][i][j] = 0;
			}
			else
			{
				int tt1 = dp[mark][i - 1][j];
				int tt2 = dp[mark][i][j - 1];
				if (tt1 < tt2)
				{
					dp[mark][i][j] = tt1 + m[mark][i][j];
					vis[mark][i][j] = 0;
				}
				else
				{
					dp[mark][i][j] = tt2 + m[mark][i][j];
					vis[mark][i][j] = 1;
				}
			}
		}
	}
	return dp[mark][n][n];
}

void print(int mark, int x, int y)
{
	if (x == 1 && y == 1)
		return;
	if (vis[mark][x][y] == 0)
	{
		print(mark, x - 1, y);
		printf("D");
	}
	else
	{
		print(mark, x, y - 1);
		printf("R");
	}
}

int main(void)
{
	int x, y;
	while (scanf("%d", &n) != EOF)
	{
		int tt, t1, t2;
		memset(vis, 0, sizeof(vis));
		memset(m, 0, sizeof(m));
		bool flag = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &tt);
				if (tt == 0)
				{
					flag = 1;
					x = i;
					y = j;
					continue;
				}
				t1 = t2 = tt;
				while (t1 % 2 == 0)
				{
					t1 /= 2;
					m[0][i][j]++;
				}
				while (t2 % 5 == 0)
				{
					t2 /= 5;
					m[1][i][j]++;
				}
			}
		}
		int ans1 = solve(0);
		int ans2 = solve(1);
		int mark = 0;
		int ans = 0;
		if (ans1 < ans2)
		{
			ans = ans1;
			mark = 0;
		}
		else
		{
			ans = ans2;
			mark = 1;
		}
		if (flag && ans > 1)
		{
			printf("1\n");
			for (int i = 2; i <= x; i++)
				printf("D");
			for (int j = 2; j <= n; j++)
				printf("R");
			for (int i = x + 1; i <= n; i++)
				printf("D");
			printf("\n");
			continue;
		}
		printf("%d\n", ans);
		print(mark, n, n);
		printf("\n");
	}
	return 0;
}