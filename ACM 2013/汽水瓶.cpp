#include<stdio.h>
int main(void)
{
	int a, sum;
	while (scanf_s("%d", &a) != EOF && a != 0)
	{
		sum = 0;
		while (a >= 3)
		{
			sum = sum + a / 3;
			a = a - (a / 3) * 2;
		}
		if (a == 0 || a == 1)
			printf("%d\n", sum);
		else
			printf("%d\n", sum + 1);
	}
	return 0;
}