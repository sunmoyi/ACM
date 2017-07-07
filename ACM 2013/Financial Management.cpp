#include <stdio.h>
int main(void)
{
	double money, sum = 0, i;
	while (scanf_s("%lf", &money) != EOF)
	{
		sum += money;
		for (i = 2; i <= 12; i++)
		{
			scanf_s("%lf", &money);
			sum += money;
		}
		printf("$%.2lf\n", sum / 12);
		sum = 0;

	}
}