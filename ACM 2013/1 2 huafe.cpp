#include<cstdio>

using namespace std;

int dp[15];

int main(void)
{
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 10; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	int k;
	while (scanf("%d", &k) != EOF)
		printf("%d\n", dp[k]);
	return 0;
}