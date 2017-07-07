#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t, n, m;
long long p[30];
long long dp[30][180];

void init()
{
	memset(dp, 0, sizeof(dp));
	p[0] = 1;
	for (int i = 1; i <= 28; i++)
		p[i] = p[i - 1] * 6;
	for (int i = 1; i <= 6; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= 25; i++)
	{
		for (int j = i; j <= i * 6; j++)
		{
			for (int k = 1; k <= 6; k++)
			{
				if ((j - k) >= (i - 1))
					dp[i][j] += dp[i - 1][j - k];
			}
		}
	}
	for (int i = 1; i <= 25; i++)
	{
		for (int j = i * 6; j >= 0; j--)
			dp[i][j] += dp[i][j + 1];
	}
}

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main(void)
{
	init();
	scanf_s("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf_s("%d %d", &n, &m);
		long long a = p[n];
		long long b = dp[n][m];
		long long c = gcd(a, b);
		if (a / c == 1)
			printf("Case %d: %lld\n", i, b / c);
		else
			printf("Case %d: %lld/%lld\n", i, b / c, a / c);
	}

	return 0;
}