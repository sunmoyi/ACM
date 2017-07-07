#include<stdio.h>
long long micheng(long long a, long long b, long long c);
int main(void)
{
	long long i, j, k, l, n, m, b, a;
	while (scanf_s("%lld", &a) != EOF)
	{
		for (i = 1; i <= a; i++)
		{
			scanf_s("%lld %lld %lld", &b, &n, &m);
			if (n == 0)
				printf("%lld\n", b % m);
			else
				printf("%lld\n", micheng(b, n, m));
		}
	}
	return 0;
}
long long micheng(long long a, long long b, long long c)
{
	long long j, i, k = 1, l;
	while (b > 0)
	{
		if (b % 2 == 1)
			k = k * a % c;
		a = a * a % c;
		b /= 2;
	}
	return k;
}