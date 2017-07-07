#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int sum, price[5005], ans, dp[500005];
int l;
int main(void)
{
	while (scanf_s("%d", &ans) != EOF && ans > 0)
	{
		memset(dp, 0, sizeof(dp));
		l = 0;
		sum = 0;
		while (ans--)
		{
			int charge, num;
			scanf_s("%d %d", &charge, &num);
			sum += charge * num;
			while (num--)
			{
				price[l++] = charge;
			}
		}
		for (int i = 0; i < l; i++)
		{
			for (int j = sum / 2; j >= price[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - price[i]] + price[i]);
			}
		}
		printf("%d %d\n", sum - dp[sum / 2], dp[sum / 2]);
	}
	return 0;
}