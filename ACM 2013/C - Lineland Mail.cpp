#include<stdio.h>
long long a[100005];
long long max(long long a, long long b);
long long min(long long a, long long b);
int main(void)
{
	long long n, i, j;
	while (scanf_s("%lld", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
			scanf_s("%lld", &a[i]);
		for (j = 1; j <= n; j++)
		{
			if (j == 1)
				printf("%lld %lld\n", a[2] - a[1], a[n] - a[1]);
			if (j == n)
				printf("%lld %lld\n", a[n] - a[n - 1], a[n] - a[1]);
			if (j != 1 && j != n)
				printf("%lld %lld\n", min(a[j + 1] - a[j], a[j] - a[j - 1]), max(a[j] - a[1], a[n] - a[j]));
		}
	}
	return 0;
}
long long max(long long a, long long b)
{
	if (a >= b)
		return a;
	else
		return b;
}
long long min(long long a, long long b)
{
	if (a >= b)
		return b;
	else
		return a;
}