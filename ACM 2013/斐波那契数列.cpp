#include <stdio.h>

long long a[100000];


long long fibbonacci(int b)
{
	a[1] = 1;
	a[2] = 1;
	a[3] = 2;
	if (b <= 3)
		return a[b];
	else
	{
		a[b] = fibbonacci(b - 1) + fibbonacci(b - 2);
	
		return a[b];	
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%lld\n", fibbonacci(n));

	return 0;
}
