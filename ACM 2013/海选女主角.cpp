# include <stdio.h>
# include <stdlib.h>
int main (void)
{
	int m, n, i , j , d, t;
	signed long  a[100][100], max;

	while(scanf("%d %d", &m, &n) ==2)
	{
		max = 0;d = 0; t = 0;
		for( i = 1; i <= m ; i++ )
		{
			if(i != 0)
				getchar();
			for(j = 1; j <= n; j++)
			{
				scanf("%d",&a[i][j]);
				if(abs(a[i][j]) > max)
					{
						max = abs(a[i][j]);
						d = i;
						t = j;
					}
			}
		}
		printf("%d %d %d\n" ,d, t, a[d][t]);
		}
	return 0;
}