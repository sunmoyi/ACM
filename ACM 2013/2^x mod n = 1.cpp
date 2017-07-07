#include<stdio.h>
int main(void)
{
	int n, m, i, j, k, l, a;
	while (scanf_s("%d", &a) != EOF)
	{
		if (a == 1)
			printf("2^? mod 1 = 1\n");
		else if (a % 2 == 0)
			printf("2^? mod %d = 1\n", a);
		else
		{
			n = 2;
			for (i = 2;; i++)
			{
				n = n * 2 % a;
				if (n % a == 1)
				{
					printf("2^%d mod %d = 1\n", i, a);
					break;
				}
			}
		}
	}
	return 0;
}