#include<stdio.h>
int main( )
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF && (n+m))
	{
		int a[100],b[100],c[100];
		int i,j,k=0,t;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(j=0;j<m;j++)
			scanf("%d",&b[j]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(a[i]==b[j])
				{
					a[i]=40000;
					break;
				}
			}
			for(i=0;i<n;i++)
			{
				if(a[i]!=40000)
				{
					c[k]=a[i];
					k++;
				}
			}
			for(i=0;i<k-1;i++)
			{
				for(j=i+1;j<k;j++)
				{
					if(c[i]>c[j])
					{
						t=c[i];
						c[i]=c[j];
						c[j]=t;
					}
				}
			}
			if(k==0)
				printf("NULL\n");
			else
			{
				for(i=0;i<k-1;i++)
					printf("%d ",c[i]);
				printf("%d \n",c[i]);
			}
	}
	return 0;
}