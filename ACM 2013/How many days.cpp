#include<stdio.h>
int main(void)
{
	int i, j, k, l, n, m, count;
	while (scanf_s("%d %d", &n, &m) != EOF && n != 0 || m != 0)
	{
		count = 0;
		while (n > 0)
		{
			i = n / m;
			j = n % m;
			n = j + i;
			if (i == 0)
			{
				count += n;
				break;
			}
			else
				count += i * m;
		}
		printf("%d\n", count);
	}
	return 0;
}