#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 550

using namespace std;

long long dp[maxn][maxn];
int num[maxn];
int sum, n, m;
long long mod;

int main(void)
{
	while (scanf("%d %d %d %lld", &sum, &n, &m, &mod) != EOF)
	{
		for (int i = 1; i <= sum; i++)
			scanf("%d", &num[i]);

		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= sum; i++)//No.i chegnxuyuan 
		{
			for (int j = 1; j <= n; j++)//daima hangshu 
			{
				for (int k = num[i]; k <= m; k++)//bug shuliang
				{
					dp[j][k] = (dp[j][k] + dp[j - 1][k - num[i]]) % mod;
				}
			}
		}

		long long sum = 0;
		for (int i = 0; i <= m; i++)
			sum = (sum + dp[n][i]) % mod;
		printf("%lld\n", sum);
	}
	return 0;
}