# include <stdio.h>
int main (void)
{
	int a,b,c,d;

    for(;scanf("%d",&a)!=EOF&&(a!=0);)
	{
		c=0;
		while(a--)
		{
			scanf("%d",&b);
			c=c+b;
		}
		printf("%d\n",c);
	}
    return 0;
}