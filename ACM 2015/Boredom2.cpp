#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

long long temp;
long long num[maxn];
long long dp[maxn];
long long maxx = 0;

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &temp);
			num[temp]++;
			maxx = max(maxx, temp);
		}

		dp[0] = 0;
		dp[1] = num[1];
		for (int i = 2; i <= maxx; i++)
			dp[i] = max(dp[i - 1], dp[i - 2] + num[i] * i);
		printf("%lld\n", dp[maxx]);
	}
	return 0;
}