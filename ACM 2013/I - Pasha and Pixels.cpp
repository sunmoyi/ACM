#include<stdio.h>
int a[1005][1005] = { 0 };
int main(void)
{
	int n, m, k, i, j, l, flag;
	while (scanf("%d %d %d"), &n, &m, &k)
	{
		flag = 1;
		for (i = 1; i <= k; i++)
		{
			scanf("%d %d", &j, &l);
			a[j][k] = 1;
			if (j >= 2 && j <= n - 1 && l >= 2 && l <= m - 1)
			{
				if (a[j][k] == a[j + 1][k] == a[j][k + 1] == a[j + 1][k + 1] == 1 ||
					a[j][k] == a[j - 1][k] == a[j][k + 1] == a[j - 1][k + 1] == 1 ||
					a[j][k] == a[j + 1][k] == a[j][k - 1] == a[j + 1][k - 1] == 1 ||
					a[j][k] == a[j - 1][k] == a[j][k - 1] == a[j - 1][k - 1] == 1)
				{
					printf("%d\n", k);
					flag = 1;
					break;
				}
			}
			if (j = 1 && l >= 2 && l <= m - 1)
			{
				if
			}
		}
		if (flag = 1)
			break;
		else
			printf("0\n");
	}
	return 0;
}