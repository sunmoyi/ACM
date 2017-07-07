#include<stdio.h>
int main()
{
	int N,R;
	int i,j,t;
	int a[1000];
	while(~scanf("%d%d",&N,&R))
	{
		i=0;t=N;
		if(N<0)
			N=-N;
		while(N>0)
		{    
			a[i]=N%R;
			N=N/R;
			i++;
		}
		if(t<0)
			printf("-");

		for(j=i-1;j>=0;j--)
		{
			printf("%X",a[j]);  
		}
		printf("\n");
	}
}