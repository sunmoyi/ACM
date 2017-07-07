#include<stdio.h>
long long a[1005][1005];
int main(void)
{
	long long n, m, i, j, k, l, max1, max2, b[1005], t;
	while (scanf_s("%lld %lld", &n, &m) != EOF)
	{
		for (i = 1; i <= 1005; i++)
			b[i] = 0;
		for (i = 1; i <= m; i++)
		{
			max1 = -1;
			for (j = 1; j <= n; j++)
			{
				scanf_s("%lld", &a[i][j]);
				if (a[i][j] > max1)
				{
					k = j;
					max1 = a[i][j];
				}
			}
			b[k]++;
		}
		max2 = -1;
		for (l = 1; l <= n; l++)
			if (b[l] > max2)
			{
				max2 = b[l];
				t = l;
			}
		printf("%lld\n", t);
	}
	return 0;
}