#include<stdio.h>
int main(void)
{
	int a, b[100], n, m, i, j;
	while (scanf("%d", &a) != EOF)
	{
		if (a == 0)
		{
			printf("0\n");
		}
		for (i = 1; a > 0; i++)
		{
			b[i] = a % 2;
			a = a / 2;
		}
		i--;
		for (j = i; j > 0; j--)
		{
			if (j != 1)
				printf("%d", b[j]);
			else
				printf("%d\n", b[j]);
		}
	}
	return 0;
}