#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5050

using namespace std;

int sum;
int num[maxn];
int dp[maxn];

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		for (int i = 1; i <= sum; i++)
			scanf("%d", &num[i]);
		memset(dp, 0x42, sizeof(dp));
		dp[1] = 0;
		for (int i = 2; i <= sum; i++)
		{
			for (int j = i - 1; j >= 1; j--)
			{
				if (i - j <= num[j])
					dp[i] = min(dp[i], dp[j] + 1);
			}
		}
		printf("%d\n", dp[sum]);
	}
	return 0;
}