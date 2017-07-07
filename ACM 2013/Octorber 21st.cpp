#include<stdio.h>
int b[10] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30 };
int main(void)
{
	int i, j, k, l, n, m;
	while (scanf_s("%d", &i) != EOF)
	{
		for (j = 1; j <= i; j++)
		{
			k = 0;
			scanf_s("%d %d", &n, &m);
			if (n > 10)
				printf("What a pity, it has passed!\n");
			else if (n == 10 && m > 21)
				printf("What a pity, it has passed!\n");
			else if (n == 10 && m == 21)
				printf("It's today!!\n");
			else if (n < 10)
			{
				switch (n + 1){
				case 1: k += 31;
				case 2: k += 28;
				case 3: k += 31;
				case 4: k += 30;
				case 5: k += 31;
				case 6: k += 30;
				case 7: k += 31;
				case 8: k += 31;
				case 9: k += 30;
				}
				k += b[n] - m + 20 + 1;
				printf("%d\n", k);
			}
			else
			{
				k = 21 - m;
				printf("%d\n", k);
			}

		}
	}
	return 0;
}