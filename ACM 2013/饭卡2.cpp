#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int price[2222], dp[2222];

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		memset(price, 0, sizeof(price));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			scanf("%d", &price[i]);

		sort(price + 1, price + n + 1);
		int maxx = price[n], m;
		scanf("%d", &m);
		if (m < 5)
			printf("%d\n", m);
		else
		{
			m -= 5;
			for (int i = 1; i < n; i++)
			{
				for (int j = m; j >= price[i]; j--)
				{
					dp[j] = max(dp[j], dp[j - price[i]] + price[i]);
				}
			}
			printf("%d\n", m + 5 - dp[m] - maxx);
		}
	}
	return 0;
}