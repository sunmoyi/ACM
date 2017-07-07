#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T, gcd, lcm;

int main(void)
{
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d %d", &gcd, &lcm);
			if (lcm % gcd != 0)
			{
				printf("-1\n");
				continue;
			}
			
			int ans = lcm / gcd;
			for (int i = 1; i * i <= ans; i++)
			{
				if (ans % i == 0)
				{
					printf("%d %d\n", i * gcd, ans / i * gcd);
					break;
				}
			}
		}
	}
	return 0;
}