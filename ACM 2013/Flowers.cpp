#include<stdio.h>
int b[10000];
int main(void)
{
	int i, j, k, l, n, m, min;
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		min = 65535;
		for (i = 1; i <= n; i++)
		{
			scanf_s("%d", &b[i]);
			if (min > b[i])
				min = b[i];
		}
		printf("%d\n", m / min);
	}
	return 0;
}