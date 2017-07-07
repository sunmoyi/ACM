#include<stdio.h>
int a[10000];
int i, j, k, l, n, m, b;
int main(void)
{
	while (scanf_s("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			j = 0; b = 0;
			scanf_s("%d", &m);
			while (m > 0)
			{
				if (m % 2 == 1)
				{
					a[j] = b;
					j++;
				}
				b++;
				m /= 2;
			}
			if (j)
			{
				for (k = 0; k < j - 1; k++)
					printf("%d ", a[k]);
				printf("%d\n", a[j - 1]);
			}
		}
	}
	return 0;
}