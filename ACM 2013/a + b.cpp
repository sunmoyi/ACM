#include <stdio.h>
int main(void)
{
	long long a, b, sum;
	while (scanf("%lld %lld", &a, &b) != EOF);
	{
		sum = a + b;
		printf("%lld\n", sum);
	}
	return 0;
}
