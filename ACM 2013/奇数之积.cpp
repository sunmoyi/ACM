# include <stdio.h>
int main (void)
{
	int S = 1,i,a,b;

	while(scanf("%d",&a)!=EOF)
	{
		S = 1;
		for(i = 1; i <= a; i++)
		{
			scanf("%d",&b);
			if(b%2 == 1)
				S = S * b; 

		}
		printf("%d\n", S);
	}
	return 0;
}