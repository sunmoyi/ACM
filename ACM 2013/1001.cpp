# include <stdio.h>
int main (void)
{
	int a,i,sum;

	for(;scanf("%d",&a)!=EOF;)
	{
		sum = 0;
		for(i=1;i<=a;i++)
		{
			sum = sum +i;
		}
		printf("%d\n",sum);
	}

	return 0;
}