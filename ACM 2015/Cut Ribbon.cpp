#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 4010

using namespace std;

int n, a, b, c;
int dp[maxn];

int main(void)
{
	scanf("%d %d %d %d", &n, &a, &b, &c);
	dp[a] = 1, dp[b] = 1, dp[c] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i])
		{
			if (i + a <= n)
				dp[i + a] = max(dp[i + a], dp[i] + 1);
			if (i + b <= n)
				dp[i + b] = max(dp[i + b], dp[i] + 1);
			if (i + c <= n)
				dp[i + c] = max(dp[i + c], dp[i] + 1);
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}