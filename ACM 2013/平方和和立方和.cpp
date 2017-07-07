# include <stdio.h>
int main (void)
{
	int start, end , i  ,temp ;
	long  j , k;
	while(scanf("%d %d",&start ,&end) == 2)
	{
		if(start > end)
		{
			temp = start ;
			start = end;
			end = temp;
		}
		j = 0;k = 0; 
		for( i = start; i <= end; i++)
		{
			if(i % 2 == 1 )
				j = j + i *i * i; 
			else
				k = k + i*i;

		}
		printf("%d %d\n", k, j );
	}
	return 0;
}