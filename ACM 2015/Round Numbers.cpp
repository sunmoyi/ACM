#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50

using namespace std;

int dp[maxn][maxn][maxn], bit[maxn];

int dfs(int pos, int num0, int num1, int work, int first)
{
	if (!pos)
	{
		if (first)
			return 1;
		if (num0 >= num1)
			return 1;
		return 0;
	}
	if (!first && !work && dp[pos][num0][num1] != -1)
		return dp[pos][num0][num1];
	int end = work ? bit[pos] : 1;
	int ans = 0;
	for (int i = 0; i <= end; i++)
	{
		if (first)
		{
			if (i == 0)
				ans += dfs(pos - 1, 0, 0, work && end == i, 1);
			else
				ans += dfs(pos - 1, num0, num1 + 1, work && end == i, 0);
		}
		else
		{
			if (i == 0)
				ans += dfs(pos - 1, num0 + 1, num1, work && end == i, 0);
			else
				ans += dfs(pos - 1, num0, num1 + 1, work && end == i, 0);
		}
	}
	if (!work && !first)
		dp[pos][num0][num1] = ans;
	return ans;
}

int solve(int n)
{
	int len = 1;
	while(n)
	{
		bit[len++] = n % 2;
		n >>= 1;
	}
	return dfs(len - 1, 0, 0, 1, 1);
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	int l, r;
	while (scanf("%d %d", &l, &r) != EOF)
		printf("%d\n", solve(r) - solve(l - 1));
	return 0;
}