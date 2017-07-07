# include<stdio.h>
void exchange (int a[],int n);
int main (void)
{
	int a[10],i;

	printf("please input ten mumber\n");
	for(i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
		printf("%d     ",a[i]);
	}
	exchange (a,10);
	for(i=0;i<=9;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
void exchange (int a[],int n)
{
	int i,j,temp;
	for(i=0;i<=8;i++)
	{
		for(j=i+1;j<=9;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}