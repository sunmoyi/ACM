#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[10000001];

int main()
{
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	dp[0] = 0;
	dp[1] = x;
	for (int i = 2; i <= n; ++i)
		if (i & 1)
			dp[i] = min(dp[i - 1] + x, dp[i / 2 + 1] + x + y);
		else
			dp[i] = min(dp[i / 2] + y, dp[i - 1] + x);
	printf("%I64d\n", dp[n]);
	return 0;
}