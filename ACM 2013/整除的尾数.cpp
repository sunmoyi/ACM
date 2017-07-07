#include <stdio.h>
int main(void)
{
	int  a, b, i, j, k, c[100], n;
	while (scanf_s("%d %d", &a, &b) != EOF && a != 0 || b != 0)
	{
		k = a * 100; n = 0;
		for (i = 0; i < 100; i++)
		{
			j = k + i;
			if (j % b == 0)
			{
				c[n] = i;
				n++;
			}
		}
		for (i = 0; i < n - 1; i++)
		{
			if (c[i] >= 10)
				printf("%d ", c[i]);
			else
				printf("0%d ",c[i]);
		}
		if (c[n - 1] >= 10)
			printf("%d\n", c[n - 1]);
		else
			printf("0%d\n",c[n - 1]);
	}
	return 0;
}