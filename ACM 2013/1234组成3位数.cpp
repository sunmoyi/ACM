# include <stdio.h>
int main (void)
{
	int a,b,c,i,n=0;

	for(a=1;a<=4;a++)
	{
		for(b=1;b<=4;b++)
		{
			for(c=1;c<=4;c++)
			{
				if(a==b||b==c||a==c)
					continue;
				else
				{
					printf("%d%d%d\n",a,b,c);
					n++;
				}
			}
		}
	}
	printf("%d\n",n);
	return 0;
}
