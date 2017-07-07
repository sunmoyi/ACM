#include<stdio.h>
int main(void)
{
	int i, j, k, l, x, y, a;
	while (scanf_s("%d", &a) != EOF)
	{
		while (a--)
		{
			scanf_s("%d %d", &x, &y);
			if (x % 2 == 1)
			{
				if (x == y)
					printf("%d\n", 2 * x - 1);
				else if (y == x - 2)
					printf("%d\n", 2 * x - 3);
				else
					printf("No Number\n");
			}
			else if (x % 2 == 0)
			{
				if (x == y)
					printf("%d\n", 2 * x);
				else if (y == x - 2)
					printf("%d\n", 2 * x - 2);
				else
					printf("No Number\n");
			}

		}
	}
	return 0;
}