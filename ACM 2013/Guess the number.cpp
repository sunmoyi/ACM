#include<stdio.h>
int main(void)
{
	int i, j, k, l, a, b, c;
	while (scanf_s("%d", &i) != EOF)
	{
		for (j = 1; j <= i; j++)
		{
			scanf_s("%d %d %d", &a, &b, &c);
			//printf("%d %d %d   ", a, b, c);
			for (k = 1000; k <= 9999; k++)
			{
				if (k % a == 0 && (k + 1) % b == 0 && (k + 2) % c == 0)
					break;
			}
			if (k == 10000)
				printf("Impossible\n");
			else
				printf("%d\n", k);
		}
	}
	return 0;
}