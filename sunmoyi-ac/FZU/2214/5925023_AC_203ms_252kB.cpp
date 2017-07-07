#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5005
#define INF 0xf3f3f3f
using namespace std;

int ans;
int sum, maxx;
int val[maxn], cal[maxn];
int dp[maxn];//在价值为i的情况下的最小重量；

int main(void)
{
	int a, b;
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			int maxxx = 0;
			scanf("%d %d", &sum, &maxx);
			for (int i = 1; i <= sum; i++)
			{
				scanf("%d %d", &a, &b);
				cal[i] = a;// weight
				val[i] = b;// value
				maxxx += b;
			}

			memset(dp, INF, sizeof(dp));
			dp[0] = 0;
			for (int i = 1; i <= sum; i++)
			{
				for (int j = maxxx; j >= val[i]; j--)
					dp[j] = min(dp[j], dp[j - val[i]] + cal[i]);
			}
			for (int i = maxxx; i >= 0; i--)
			{
				if (dp[i] <= maxx)
				{
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}