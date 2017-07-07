#include<stdio.h>
int b[105][105];
int c[105][105] = {0};
int main(void)
{
	int i, j, k, l, n, m, a;
	while (scan("%d", &a) != EOF && a != 0)
	{
		for (j = 0; j <= 104; j++)
			for (k = 0; k <= 104; k++)
				b[j][k] = 0;
		for (j = 0; j <= 104; j++)
			for (k = 0; k <= 104; k++)
				c[j][k] = 0;

		n = 1; 
		m = a;
		b[1][a] = 1;
		i = 2;
		c[1][a] = 1;
		
		while (i - 1 < a * a)
		{
			while (m - 1 >= 1 && m - 1 <= a && n >= 1 && m <= a && c[n][m - 1] == 0)
			{
				b[n][m - 1] = i++;
				c[n][m - 1] = 1;
				m--;
			}
			while (n + 1 >= 1 && n + 1 <= a && m >= 1 && m <= a && c[n + 1][m] == 0)
			{
				b[n + 1][m] = i++;
				c[n + 1][m] = 1;
				n++;
			}
			while (m + 1 >= 1 && m + 1 <= a && n >= 1 && n <= a && c[n][m + 1] == 0)
			{
				b[n][m + 1] = i++;
				c[n][m + 1] = 1;
				m++;
			}
			while (n - 1 >= 1 && n - 1 <= a && m >= 1 && m <= a && c[n - 1][m] == 0)
			{
				b[n - 1][m] = i++;
				c[n - 1][m] = 1;
				n--;
			}
		}
		for (j = 1; j <= a; j++)
		{
			for (k = 1; k <= a; k++)
			{
				if (k == 1)
					printf("%d", b[k][j]);
				else
					printf(" %d", b[k][j]);
			}
			printf("\n");
		}
	}
	return 0;
}