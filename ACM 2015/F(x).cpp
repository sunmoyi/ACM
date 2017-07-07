#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[20][200000];
int bit[20];
int A, B, T;

int F(int x)
{
	int ans = 0;
	int len = 0;
	while (x)
	{
		ans += (x % 10) * (1 << len);
		len++;
		x /= 10;
	}
	return ans;
}

int dfs(int pos, int num, bool flag)
{
	if (pos == -1)
		return num >= 0;
	if (num < 0)
		return 0;
	if (!flag && dp[pos][num] != -1)
		return dp[pos][num];
	int ans = 0;
	int end = flag ? bit[pos] : 9;
	for (int i = 0; i <= end; i++)
		ans += dfs(pos - 1, num - i * (1 << pos), flag && i == end);
	if (!flag)
		dp[pos][num] = ans;
	return ans;
}

int solve()
{
	int len = 0;
	while (B)
	{
		bit[len++] = B % 10;
		B /= 10;
	}
	return dfs(len - 1, F(A), 1);
}

int main (void)
{
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= T; i++)
	{
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d\n", i, solve());
	}
	return 0;
}