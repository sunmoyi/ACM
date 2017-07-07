#include<cstdio>
#include<cstring>

using namespace std;

int n, k;
int val[110];
int dp[10100];

int main()
{
	int t;
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ca++)
	{
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &val[i]);


		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = val[i]; j <= k; j++)
			{
				dp[j] = (dp[j] + dp[j - val[i]]) % 100000007;
			}
		}

		printf("Case %d: %d\n", ca, dp[k]);
	}
	return 0;
}