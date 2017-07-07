#include<stdio.h>
#include<math.h>
int main(void)
{
	int a[200], i, j, k, sum;
	i = 1;
	do{
		scanf_s("%d", &a[i]);
		i++;
	} while (a[i - 1] != 0);
	printf("PERFECTION OUTPUT\n");
	for (j = 1; j <= i - 2; j++)
	{
		sum = 1;
		for (k = 2; k < sqrt((double)a[j]); k++)
		{
			if (a[j] % k == 0)
				sum = sum + k + a[j] / k;
		}
		if (sum == a[j])
			printf("%5d  PERFECT\n", a[j]);
		if (sum > a[j])
			printf("%5d  ABUNDANT\n", a[j]);
		if (sum < a[j])
			printf("%5d  DEFICIENT\n", a[j]);
	}
	printf("END OF OUTPUT\n");
	return 0;
}