# include <stdio.h>
int main (void)
{
	int n, a[100], i, min, d, temp;
	while(scanf("%d", &n) !=EOF && n != 0)
	{
		d = 0;
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d", &a[i]);
		}
		min = a[0];
		for(i = 0 ; i < n ; i++)
		{
			if(a[i] < min)
			{
				d = i;
				min = a[i];
			}
		}
		temp = a[0];
		a[0] = a[d];
		a[d] = temp;
		for(int i = 0 ; i < n ; i++)
		{
			if(i != n - 1 )
				printf("%d ",a[i]);
			else
				printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0 ;
}
