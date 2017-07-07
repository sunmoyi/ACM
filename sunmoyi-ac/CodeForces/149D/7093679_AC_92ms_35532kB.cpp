#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 710
#define mod 1000000007

using namespace std;

long long dp[maxn][maxn][3][3], match[maxn], temp[maxn];

void get_match(char a[])
{
	int top = 0;
	for (int i = 0; a[i]; i++)
	{
		if (a[i] == '(')
			temp[top++] = i;
		else
		{
			match[i] = temp[top - 1];
			match[temp[top - 1]] = i;
			top--;
		}
	}
}

void dfs(int l, int r)
{
	if (l + 1 == r)
	{
		dp[l][r][0][1] = 1;
		dp[l][r][1][0] = 1;
		dp[l][r][0][2] = 1;
		dp[l][r][2][0] = 1;
		return;
	}
	else if (match[l] == r)
	{
		dfs(l + 1, r - 1);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j != 1)
					dp[l][r][0][1] = (dp[l][r][0][1] + dp[l + 1][r - 1][i][j]) % mod;
				if (i != 1)
					dp[l][r][1][0] = (dp[l][r][1][0] + dp[l + 1][r - 1][i][j]) % mod;
				if (j != 2)
					dp[l][r][0][2] = (dp[l][r][0][2] + dp[l + 1][r - 1][i][j]) % mod;
				if (i != 2)
					dp[l][r][2][0] = (dp[l][r][2][0] + dp[l + 1][r - 1][i][j]) % mod;
			}
		}
		return;
	}
	else
	{
		int k = match[l];
		dfs(l, k);
		dfs(k + 1, r);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int x = 0; x < 3; x++)
				{
					for (int y = 0; y < 3; y++)
					{
						if (!((x == 1 && y == 1) || (x == 2 && y == 2)))
							dp[l][r][i][j] = (dp[l][r][i][j] + dp[l][k][i][x] * dp[k + 1][r][y][j]) % mod;
					}
				}
			}
		}
		return;
	}
}

int main(void)
{
	char str[maxn];
	while (scanf("%s", str) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		int len = strlen(str);
		get_match(str);
		dfs(0, len - 1);

		long long ans = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				ans = (ans + dp[0][len - 1][i][j]) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}