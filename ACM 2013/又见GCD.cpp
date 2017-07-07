#include<stdio.h>
int gcd(int a, int b);
int main(void)
{
	int n, m, i, j, k, l, a;
	while (scanf_s("%d ", &a) != EOF)
	{
		for (l = 1; l <= a; l++)
		{
			scanf_s("%d %d", &n, &m);
			for (i = m + 1 ; i < n; i++)
			{
				if (gcd(n, i) == m)
				{
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}
int gcd(int a, int b)
{
	int i, j, k, l, c;
	while (b > 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;//   a = 12 b = 8 c = 4 a = 8 b = 4 c = 0 a = 4 b = 0
}
