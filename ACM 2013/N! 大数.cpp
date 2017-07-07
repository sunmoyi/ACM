#include<stdio.h>
#define y 100000
int main()
{
	int i, n, m, j, x, k, a[y];
	while (scanf_s("%d", &n) != EOF)
	{
		a[0] = 1;
		k = 1;
		for (i = 1; i <= n; i++)
		{
			m = 0;
			for (j = 0; j<k; j++)
			{
				x = m + a[j] * i;
				a[j] = x % 10;
				m = x / 10;
			}
			while (m)
			{
				a[k++] = m % 10;
				m = m / 10;

			}
		}
		for (i = y - 1; i >= 0; i--)
		{
			if (a[i])
				break;
		}
		for (j = k - 1; j >= 0; j--)
			printf("%d", a[j]);
		printf("\n");
	}
}