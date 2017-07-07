#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 60
#define INF 99999999999999999

using namespace std;

int t[4][4];
long long dp[4][4][maxn];

long long dfs(int a, int b, int n)
{
	int c = 3 ^ a ^ b;
	if (n == 1)
		return min(t[a][c] + t[c][b], t[a][b]);
	if (dp[a][b][n] != -1)
		return dp[a][b][n];
	long long &ret = dp[a][b][n];
	ret = INF;
	ret = min(ret, t[a][b] + dfs(a, c, n - 1) + dfs(c, b, n - 1));
	ret = min(ret, t[a][c] + t[c][b] + dfs(a, b, n - 1) * 2 + dfs(b, a, n - 1));
	return ret;
}

int main(void)
{
	int n;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &t[i][j]);
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", dfs(0, 2, n));
	return 0;
}