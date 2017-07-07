#include<stdio.h>
long long a[35][35] = {1};
int main(void)
{	
	int i, j, k, l, n, m, flag = 0;
	while (scanf_s("%d", &n) != EOF)
	{
		
		for (i = 1; i <= n; ++i)
		{
			a[i][1] = 1;
			a[i][i] = 1;
		}
		for (i = 3; i <= n; ++i)
		{
			for (j = 2; j < i; ++j)
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
		for (i = 1; i <= n; ++i)
		{
			printf("%d", a[i][1]);
			for (j = 2; j <= i; ++j)
			{
				printf(" %d", a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}