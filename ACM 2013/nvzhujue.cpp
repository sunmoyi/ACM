#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, m, a[100][100] = { 0 }, i, j, max, h, l;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		max = 0; h = 0; l = 0;
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
				if (abs(a[i][j]) > max)
				{
					max = abs(a[i][j]); h = i; l = j;
				}
			}
		}
		printf("%d %d %d\n", h, l, a[h][l]);
	}
}