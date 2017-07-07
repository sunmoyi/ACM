#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<math.h>

using namespace std;

long long num[1000];
int T, k;

void swap(long long *a, long long *b)
{
	int temp = *a;
	*a = *b; 
	*b = temp;
}


long long gcd(long long a, long long b)
{
	if (a < b)
		swap(&a, &b);
	int c;
	while (b > 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long god(long long a, long long b)
{
	long long c;// ’‚”–µ„πÌ
	c = a * b;
	long long d = gcd(a, b);
	return c / d;
}
int main(void)
{
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d", &k);
			for (int i = 1; i <= k; i++)
			{
				scanf("%lld", &num[i]);
			}
			while (k > 1)
			{
				if (k % 2 == 0)
				{
					for (int i = 1; i <= k; i += 2)
					{
						num[i / 2 + 1] = god(num[i], num[i + 1]);
					}
					k = (k - 1) / 2 + 1;
				}
				else
				{
					for (int i = 1; i < k; i += 2)
					{
						num[i / 2 + 1] = god(num[i], num[i + 1]);
					}
					num[k / 2 + 1] = num[k];
					k = k / 2 + 1;
				}
			}
			printf("%lld\n", num[1]);
		}
	}
	return 0;
}
