#include <stdio.h>
long long fibbonacci(int b);
long long a[1000000];
int vis[1000000] = { 0 };
int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF && n != -1)
	{
		printf("%lld\n", fibbonacci(n));
	}
	return 0;
}
long long fibbonacci(int b)
{
	a[1] = 1;
	a[2] = 1;
	a[3] = 2;
	if (b <= 3 || vis[b] == 1)
		return a[b];
	else
	{
		a[b] = fibbonacci(b - 1) + fibbonacci(b - 2);
		vis[b] = 1;
		return a[b];
	}
}