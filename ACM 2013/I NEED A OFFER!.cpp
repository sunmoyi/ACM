#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int money, sum;
int mon[10010];
double rate[10010];
double a, b;
double dp[10010];

int main(void)
{
	while (scanf_s("%d %d", &money, &sum) != EOF && (money + sum))
	{
		for (int i = 1; i <= sum; i++)
		{
			scanf_s("%d %lf", &mon[i], &a);
			rate[i] = (1 - a);//不被录取的概率
		}

		for (int i = 0; i <= money + 1; i++)
			dp[i] = 1;

		for (int i = 1; i <= sum; i++)
		{
			for (int j = money; j >= mon[i]; j--)
			{
					dp[j] = min(dp[j], dp[j - mon[i]] * rate[i]);
			}
		}
		printf("%.1lf%%\n",(1 - dp[money]) * 100);
	}
	return 0;
}