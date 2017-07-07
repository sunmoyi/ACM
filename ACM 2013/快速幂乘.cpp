#include<stdio.h>
int main(void)
{
	int a, b, i, j, k, l;
	while (scanf_s("%d %d", &a, &b) != EOF)
	{
		k = 1;
		if (b % 2 == 1)
			k = k * a % 1000;
		else
		{
			a = a * a % 1000;
			b /= 2;
		}
		printf("%d\n", k);
	}
	return 0;
}