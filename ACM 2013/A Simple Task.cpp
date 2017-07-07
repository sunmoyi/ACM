#include<stdio.h>
int leicheng(int b);
int main(void)
{
	int n, m, i, j, o, p, a, max;
	while (scanf_s("%d", &a) != EOF)
	{
		for (i = 1; i <= a; i++)
		{
			scanf_s("%d", &n);
			printf("%d", n);
			max = 1;
			while (leicheng( max ) <= n)
				max++;
			for (o = 1; o <= n; o++)
			{
				if (i % 2 == 0)
					continue;
				for (p = 0; p <= max - 1; p++)
				{
					if (n == o * leicheng(p))
						printf("%d %d\n", o, p);
				}
			}
		}
	}
	return 0;
}
int leicheng(int b)
{
	int a, i;
	a = 1; 
	if (b = 0)
		return 1;
	for (i = 1; i <= b; i++)
		a = a * 2;
	return a;
}