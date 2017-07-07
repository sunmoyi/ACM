#include <stdio.h>
int a[35][35];
int main(){
	int n, i, j;
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