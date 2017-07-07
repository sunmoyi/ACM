#include<stdio.h>
#include<math.h>
int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	while(m!=0||n!=0)
	{
		for(j=(int)sqrt(2.0 * m);j>=1;j--)
		{
			i=(2*m/j+1-j)/2;;
			if((2*i+j-1)*j/2==m)
				printf("[%d,%d]\n",i,i+j-1);
		}
		printf("\n");
		scanf("%d%d",&n,&m);
	}
}