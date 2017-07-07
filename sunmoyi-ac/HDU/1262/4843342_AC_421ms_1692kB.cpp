#include<stdio.h>
int b[10000];
int main(void)
{
	int i, j, k, l, n, m, flag, a = 1, min, c, d;
	for (i = 2; i <= 10000; i++)
	{
		flag = 1;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				flag = 0;
		}
		if (flag == 1)
		{
			b[a] = i;
			a++;
		}
	}
	while (scanf_s("%d", &n) != EOF)
	{
		for (i = n / 2; i >= 2; i--)
		{
			flag = 0;
			for (j = 1; j < a; j++)
				if (b[j] == i)
				{
					flag++;
					break;
				}
			for (j = 1; j < a; j++)
				if (b[j] == n - i)
				{
					flag++;
					break;
				}
			if (flag == 2)
			{
				c = i;
				d = n - i;
				break;
			}
		}
		printf("%d %d\n", c, d);
	}
	return 0;
}