#include <stdio.h>
int main(void)
{
	int a[1000], i, j, k, l, n, m, sum;
	scanf_s("%d", &a[1]);
start:i = 2;
	sum = 0;
	do{
		scanf_s("%d", &a[i]);
		i++;
	} while (a[i - 1] != 0);
	for (j = 1; j <= i - 1; j++)
	{
		for (k = j + 1; k <= i - 1; k++)
		{
			if (a[j] == 2 * a[k] || a[k] == 2 * a[j])
				sum = sum + 1;
		}

	}
	printf("%d\n", sum);
	scanf_s("%d", &a[1]);
	if (a[1] != -1)
		goto start;
	return 0;
}