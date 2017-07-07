#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int bit[15];
int dp[15][15][3];

int dfs(int pos, int mod, int have, int lim)
{
	int end, ans, mod_x, have_x;
	if (pos <= 0)
		return mod == 0 && have == 2;
	if (!lim && dp[pos][mod][have] != -1)
		return dp[pos][mod][have];
	end = lim ? bit[pos] : 9;
	ans = 0;
	for (int i = 0; i <= end; i++)
	{
		mod_x = (mod * 10 + i) % 13;
		have_x = have;
		if (have == 0 && i == 1)
			have_x = 1;
		if (have == 1 && i != 1)
			have_x = 0;
		if (have == 1 && i == 3)
			have_x = 2;
		ans += dfs(pos - 1, mod_x, have_x, lim && i == end);
	}
	if (!lim)
		dp[pos][mod][have] = ans;
	return ans;
}

void solve(int n)
{
	memset(dp, -1, sizeof(dp));
	memset(bit, 0, sizeof(bit));
	int len = 0;
	while (n)
	{
		bit[++len] = n % 10;
		n /= 10;
	}
	printf("%d\n", dfs(len, 0, 0, 1));
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		solve(n);
	}
	return 0;
}