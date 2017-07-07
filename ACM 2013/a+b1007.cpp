# include<stdio.h>
int main(void)
{
	int a, b, c, d, i, j, k, sum;

	while (scanf_s("%d", &a) != EOF)
	{
		for (k = 1; k <= a; k++)
		{
			sum = 0;
			scanf_s("%d", &b);
			for (i = 1; i <= b; i++)
			{
				scanf_s("%d", &c);
				sum = sum + c;

			}
			printf("%d\n", sum);
			if (k != a)
				printf("\n");
		}
	}
	return 0;
}