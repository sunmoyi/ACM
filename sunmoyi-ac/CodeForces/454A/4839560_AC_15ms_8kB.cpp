#include<stdio.h>
int main(void)
{
	int i, j, k, l, n, a;
	while (scanf_s("%d", &n) != EOF)
	{
		for (i = 1; i <= (n - 1) / 2; i++)
		{
			for (j = (n + 1) / 2 - i; j > 0; j--)
				printf("*");
			for (k = 1; k <= 2 * i - 1; k++)
				printf("D");
			for (j = (n + 1) / 2 - i; j > 0; j--)
				printf("*");
			printf("\n");
		}
		for (i = 1; i <= n; i++)
			printf("D");
		printf("\n");
		for (i = (n - 1) / 2; i >= 1; i--)
		{
			for (j = (n + 1) / 2 - i; j > 0; j--)
				printf("*");
			for (k = 1; k <= 2 * i - 1; k++)
				printf("D");
			for (j = (n + 1) / 2 - i; j > 0; j--)
			printf("*");
			printf("\n");
		}
	}
	return 0;
}