#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long dp[100];
int k;

int main(void)
{
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 10; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	while (scanf("%d", &k) != EOF)
	{
		printf("%lld\n", dp[k]);
	}
}