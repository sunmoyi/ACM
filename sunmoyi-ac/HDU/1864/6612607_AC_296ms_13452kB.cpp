#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[3000050];

int main(void)
{
	char ch;
	double x, y;
	int summ, a, b, c, v, money[35];
	int t, k;
	while (scanf("%lf%d", &x, &t) != EOF && t)
	{
		summ = (int)(x * 100);
		memset(money, 0, sizeof(money));
		memset(dp, 0, sizeof(dp));
		int l = 0;
		for(int i = 1; i <= t; i++)
		{
			scanf("%d", &k);
			a = b = c = 0;
			int flag = 1;
			while (k--)
			{
				scanf(" %c:%lf", &ch, &y);
				v = int(y * 100);
				if (ch == 'A' && a + v <= 60000)
					a += v;
				else if (ch == 'B' && b + v <= 60000)
					b += v;
				else if (ch == 'C' && c + v <= 60000)
					c += v;
				else flag = 0;
			}
			if (a + b + c <= 100000 && a <= 60000 && b <= 60000 && c <= 60000 && flag)
				money[l++] = a + b + c;
		}
		for (int i = 0; i < l; i++)
		{
			for (int j = summ; j >= money[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - money[i]] + money[i]);
			}
		}
		printf("%.2lf\n", dp[summ] / 100.0);
	}
	return 0;
}