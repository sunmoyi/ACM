#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10

using namespace std;

int dp[maxn][maxn];

void init()
{
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= 7; i++)
		for (int j = 0; j <= 9; j++)//第i位出现的数
			for (int k = 0; k <= 9; k++)//第i - 1位出现的数
				if (j != 4 && !(j == 6 && k == 2))
					dp[i][j] += dp[i - 1][k];
}

int solve(int n)
{
	int digit[10];
	int len = 0;
	while (n > 0)
	{
		digit[++len] = n % 10;
		n /= 10;
	}
	digit[len + 1] = 0;
	int ans = 0;
	for (int i = len; i; i--)
	{
		for (int j = 0; j < digit[i]; j++)
		{
			if (j != 4 && !(digit[i + 1] == 6 && j == 2))
				ans += dp[i][j];
		}
		if (digit[i] == 4 || (digit[i] == 2 && digit[i + 1] == 6))
			break;
	}
	return ans;
}

int main(void)
{
	int l, r;
	init();
	while (scanf("%d %d", &l, &r) != EOF && (l + r))
	{
		printf("%d\n", solve(r + 1) - solve(l)) ;
	}
	return 0;
}