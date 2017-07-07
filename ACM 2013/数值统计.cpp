#include<stdio.h>
int main(void)
{
	int n,i,b1,b2,b3;
	double a[101];
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		for(i=0;i<n;i++) 
			scanf("%lf",&a[i]);
		b1=b2=b3=0;
		for(i=0;i<n;i++)
		{
			if(a[i]<0) 
				b1++;
			else if(a[i]==0)
				b2++;
			else 
				b3++;
		}
		printf("%d %d %d\n",b1,b2,b3);
	}
}