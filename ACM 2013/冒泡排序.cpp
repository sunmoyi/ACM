# include<stdio.h>
void maopao (int a[],int n);
int main (void)
{
	int a[5],i;

	printf("please input ten mumber\n");
	for(i=0;i<=4;i++)
	{
		scanf("%d",&a[i]);
		printf("%d     \n",a[i]);
	}
	maopao (a,5);
	for(i=0;i<=4;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
/*  ��һ��void maopao(int a[], int n)
{
    int i, j, temp;
    for (j = 0; j < n - 1; j++)
    {  
		for (i = 0; i < n - 1 - j; i++)
        {
            if(a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
	 }
}*/
/*������*/void maopao (int a[],int n)         //�ⲻ��ð��
{
	int i,j,t;

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{
			if(a[i]>a[j])
			{
				t = a[i];
                a[i] = a[j];
                a[j] = t;
			}
		}
	}
}