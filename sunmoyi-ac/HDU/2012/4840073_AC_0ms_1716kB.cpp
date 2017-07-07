# include <stdio.h>
int main(void)
{
	long long x, y, i, j, k, flag;
	while (scanf("%lld %lld", &x, &y) != EOF && x != 0 || y != 0)
	{
		flag = 1;
		for (i = x; i <= y; i++)
		{
			k = i * i + i + 41;
			for (j = 2; j < k; j++)
			{
				if (k % j == 0)
					flag = 0;
			}
		}
		if (flag)
			printf("OK\n");
		else
			printf("Sorry\n");
	}
	return 0;
}