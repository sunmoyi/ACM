/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110 
#define INF 0x3f3f3f3f

using namespace std;

int dp[maxn], sum[maxn], price[maxn], num, k;
int T;

int main(void)
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &num);
		sum[0] = 0; dp[0] = 0;
		for (int i = 1; i <= num; i++)
		{
			scanf("%d %d", &k, &price[i]);
			sum[i] = sum[i - 1] + k;
			dp[i] = dp[i - 1] + (k + 10) * price[i];
		}
		for (int i = 1; i <= num; i++)
		{
			for (int j = 0; j < i; j++)
			{
				dp[i] = min(dp[i], dp[j] + (sum[i] - sum[j] + 10) * price[i]);
			}
		}
		printf("%d\n", dp[num]);
	}
	return 0;
}*/