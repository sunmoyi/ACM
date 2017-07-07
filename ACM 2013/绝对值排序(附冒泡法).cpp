# include <stdio.h>
# include <math.h>
void maopao (int * a , int len);
int main (void)
{
	int a[100], b[100], i, j, k, t;
	while(scanf("%d",&k) != EOF && k != 0)
	{
		for(i = 0 ; i< k ; i++)
		{
			scanf("%d",&a[i]);
		}
		maopao (a, k);
		for(i = 0 ; i< k -1 ; i++)
			printf("%d ",a[i]);
		printf("%d\n",a[k - 1]);
	}
	return 0;

}
void maopao (int * a, int len)
{
	int i, j, t;

	for (i=0; i<len-1; ++i)
	{
		for (j=0; j<len-1-i; ++j)
		{
			if (abs(a[j]) < abs(a[j+1]))  
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t; 
			}
		}
	}
}