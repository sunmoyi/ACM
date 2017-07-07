#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	while (scanf_s("%d", &n) != EOF && n)
	{
		int i, price[2013] = { 0 }, dp[2013] = { 0 }, maxx = -9999999, ss = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%d", &price[i]);
			if (price[i] > maxx)
			{
				maxx = price[i];
				ss = i;
			}
		}
		int j, m;
		scanf_s("%d", &m);
		if (m < 5)
		{
			printf("%d\n", m);
			continue;
		}
		m -= 5;
		for (int i = 1; i <= n; i++)
		{
			for (int j = m; j >= price[i] && i != ss; j--)
			{
				dp[j] = max(dp[j], dp[j - price[i]] + price[i]);
			}
		}
		printf("%d\n", m + 5 - dp[m] - maxx);
	}
	return 0;
}