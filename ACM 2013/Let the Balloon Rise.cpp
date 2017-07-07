#include <stdio.h>
#include <string.h>
int main(void)
{
	int n, i, j, k, l, b[1001] = { 0 }, max;
	char a[1001][16];
	while (scanf_s("%d", &n) != EOF && n != 0)
	{
		getchar();
		scanf_s("%s", &a[1]);
		for (i = 2; i <= n; i++)
		{
			getchar();
			scanf_s("%s", &a[i]);
			for (j = 1; j < i; j++)
				if (!strcmp(a[j], a[i]))
					b[j] += 1;
		}
		max = b[1]; l = 1;
		for (k = 1; k <= n; k++)
			if (b[k] > max)
			{
				max = b[k];
				l = k;
			}
		printf("%s", a[l]);
	}
	return 0;
}