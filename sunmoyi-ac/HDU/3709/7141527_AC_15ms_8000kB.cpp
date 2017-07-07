#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20

using namespace std;

int bit[maxn];
long long dp[maxn][maxn][2010];

long long dfs(int pos, int o, int l, int work)
{
	if (pos == -1)
		return l == 0;
	if (l < 0)
		return 0;
	if (!work && dp[pos][o][l] != -1)
		return dp[pos][o][l];
	long long ans = 0;
	int end = work ? bit[pos] : 9;
	for (int i = 0; i <= end; i++)
	{
		int next = l + (pos - o) * i;
		ans += dfs(pos - 1, o, next, work && i == end);
	}
	if (!work)
		dp[pos][o][l] = ans;
	return ans;
}

long long solve(long long n)
{
	int len = 0;
	while (n)
	{
		bit[len++] = n % 10;
		n /= 10;
	}
	long long ans = 0;
	for (int i = 0; i < len; i++)
		ans += dfs(len - 1, i, 0, 1);
	return ans - (len - 1);
}

int main(void)
{
	int T;
	long long l, r;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	while (T--)
	{
		scanf("%lld %lld", &l, &r);
		printf("%lld\n", solve(r) - solve(l - 1));
	}
	return 0;
}