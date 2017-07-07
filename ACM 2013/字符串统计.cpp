# include <stdio.h>
# include <string.h>
int main (void)
{
	int n, i, k, x, j;
	char a[10000];

	while(scanf("%d",&n) != EOF)
	{
		for(j = 1; j <= n ;j++)
		{
			k = 0;
			scanf("%s",a);
			x = strlen(a);
			for(i = 0 ; i < x ;i++ )
			{
				if(a[i] >= '0'&& a[i] <= '9')
					k = k + 1 ;
			}
			printf("%d\n", k);
		}
	}
	return 0;
}
