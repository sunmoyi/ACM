#include<stdio.h>
int b[5005];
int main(void)
{
	int i, j, k, l, n, m, a, flag, sum;
	k = 1;
	for (i = 2; i < 5000; i++)
	{
		flag = 1;
		for (j = 2; j < i; j++)
			if (i % j == 0)
				flag = 0;
		if (flag = 1)
		{
			b[k] = i;
			k++;
		}
	}
	while (scanf_s("%d", &n) != EOF && n != 0)
	{
		flag = 0; sum = 1;
		for (i = 2; i < n; i++)
		{
			for (l = 1; l < k; l++)
				if (b[k] == i)
					flag += 1;
			for (l = 1; l < k; l++)
				if (b[k] == n - i)
					flag += 1;
			if (flag = 2)
				sum += 1;
		}
		printf("%d\n", sum);
	}
	return 0;
}