#include<stdio.h>
long long  a[25];
int main(void)
{
	int i, j, k, l, n, m;
	a[1] = 0;
	a[2] = 1;
	for (i = 3; i <= 20; i++)
		a[i] = (i - 1)* (a[i - 1] + a[i - 2]);
	while (scanf_s("%d", &n) != EOF)
	{
		printf("%lld\n", a[n]);
	}
	return 0;
}
