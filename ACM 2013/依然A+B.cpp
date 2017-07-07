#include<stdio.h>
int main(void)
{
	long long a, b;
	while(scanf_s("%lld %lld", &a, &b) != EOF)
	{
		printf("%lld\n", a + b);
	}
	return 0;
}