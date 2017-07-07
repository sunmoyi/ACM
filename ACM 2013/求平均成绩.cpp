#include<stdio.h>
int main()
{
	int m,n,i,j,k,sum;
	double s[60][10],a[60],b[10];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%lf",&s[i][j]);
		for(i=0;i<n;i++)
		{
			a[i]=0;
			for(j=0;j<m;j++)
				a[i]=a[i]+s[i][j];
		}
		for(i=0;i<n-1;i++)
		{
			printf("%.2lf ",a[i]/m);
		}
		printf("%.2lf\n",a[i]/m);
		for(i=0;i<m;i++)
		{
			b[i]=0;
			for(j=0;j<n;j++)
				b[i]=b[i]+s[j][i];
		}
		for(i=0;i<m-1;i++)
			printf("%.2lf ",b[i]/n);
		printf("%.2lf\n",b[i]/n);
		sum=0;
		for(i=0;i<n;i++)
		{
			k=1;
			for(j=0;j<m;j++)
			{
				if(s[i][j]<b[j]/n)
				{
					k=0;
					break;
				}
			}
			if(k)
				sum++;
		}
		printf("%d\n\n",sum);
	}
	return 0;
}