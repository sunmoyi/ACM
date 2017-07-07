#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[2005][2005];

int main(void)
{
	dp[0][0] = 1;
	for (int i = 1; i < 2005; i++)
	{
		dp[i][1] = 1;
		dp[i][i] = 1;
	}
	for (int i = 3; i < 2005; i++)
	{
		for (int j = 2; j < i; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1007;
		}
	}
	int num, a, b;
	while (scanf("%d", &num) != EOF)
	{
		while (num--)
		{
			scanf("%d %d", &a, &b);
			printf("%d\n", dp[b + 1][a + 1]);
		}
	}
	return 0;
}