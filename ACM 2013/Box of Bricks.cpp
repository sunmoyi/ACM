#include<stdio.h>
int main(void)
{
	int n, a[200], sum, i, j, k = 1, l, average, sum2;
	while (scanf_s("%d", &n) != EOF && n != 0)
	{
		sum = 0; sum2 = 0;
		for (i = 1; i <= n; i++)
		{
			scanf_s("%d", &a[i]);
			sum = sum + a[i];
		}
		average = sum / n;
		for (i = 1; i <= n; i++)
		{
			if (a[i] > average)
				sum2 = sum2 + a[i] - average;
		}
		printf("Set #%d\n", k);
		printf("The minimum number of moves is %d.\n", sum2);
		printf("\n");
		k++;
	}
	return 0;
}