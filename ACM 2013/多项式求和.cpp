# include <stdio.h>
int main (void)
{
	int  m, n, i, j;
	float sum, s;
	while (scanf("%d",&m)!=EOF)
	{
		
		for(i = 1 ; i <= m ; i++)
		{
			scanf("%d", &n );
			sum = 0;
			for(j = 1; j <= n ;j++)
			{
				if( j % 2 == 1)
				{
					s = 1.00/j;
				}
				if( j % 2 == 0)
					{
						s =(-1.00)/j;
					}
				sum = sum + s;
			}
			printf("%.2lf\n", sum);
		}
	}
	return 0;
}