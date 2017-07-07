#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 25

using namespace std;

long long dp[maxn][3];

void init()
{
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= 22; i++)
	{
		dp[i][0] = dp[i - 1][0] * 10 - dp[i - 1][1];//不包含49
		dp[i][1] = dp[i - 1][0];//不包含49 但是首字母位9
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1];//包含49
	}
}
/*
long long solve(long long n)
{
	long long temp = n, len = 0, a[25], flag = 0, ans = 0;
	while (n)
	{
		a[++len] = n % 10;
		n /= 10;
	}
	a[len + 1] = 0;
	for (int i = len; i; i--)
	{
		ans += dp[i - 1][2] * a[i];
		if (flag)
			ans += dp[i - 1][0] * a[i];
		if (!flag && a[i] > 4)
			ans += dp[i - 1][1];
		if (a[i + 1] == 4 && a[i] == 9)
			flag = 1;
	}
	return ans;
}
*/

long long solve(long long n)
{
	long long len = 0, a[25], ans = 0;
	bool flag = false;
	while (n)
	{
		a[++len] = n % 10;
		n /= 10;
	}
	a[len + 1] = 0;
	for (int i = len; i; i--)
	{
		for (int j = 0; j < a[i]; j++)
		{
			ans += dp[i - 1][2];
			if (flag)
				ans += dp[i - 1][0];
			if (!flag && j == 4)
				ans += dp[i - 1][1];
		}
		if (!flag && (a[i + 1] == 4 && a[i] == 9))
			flag = 1;
	}
	return ans;
}

int main(void)
{
	int t;
	long long n;
	init();
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld", &n);
		printf("%lld\n", solve(n + 1))  ;
	}
	return 0;
}