#include <stdio.h>
int main(void)
{
	int n, m, i, j, l, k;
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		k = n;
		for (i = 2; i <= m; i++)
		{
			n = (n * k) % 10;
		}
		printf("%d\n", n);
	}
	return 0;
}