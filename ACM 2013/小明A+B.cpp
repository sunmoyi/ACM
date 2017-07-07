#include <stdio.h>
int main(void)
{
	int a, b, i, n, sum;
	while (scanf_s("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			scanf_s("%d", &a);
			scanf_s("%d", &b);
			a = a % 100;
			b = b % 100;
			sum = a + b;
			sum = sum % 100;
			printf("%d\n", sum);
		}

	}
	return 0;
}