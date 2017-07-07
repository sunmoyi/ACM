#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long  n, price, money;
double sum;
char str[45][10];

int main(void)
{
	while (scanf("%lld %lld", &n, &price) != EOF)
	{
		getchar;
		for (int i = 1; i <= n; i++)
			scanf("%s", str[i]);


		sum = 1;
		for (int i = n - 1; i >= 1; i--)
		{
			if (strlen(str[i]) > 4)
				sum = sum * 2 + 1;
			else
				sum = sum * 2;
		}


		money = 0;
		while (sum)
		{
			if ((sum / 2) == (int)(sum / 2))
			{
				money += price* (sum / 2);
				sum /= 2;
			}
			else
			{
				money += price * (sum / 2);
				sum--;
				sum /= 2;
			}
		}
		printf("%lld\n", money);
	}
	return 0;
}