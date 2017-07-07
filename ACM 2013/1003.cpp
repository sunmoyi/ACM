# include<stdio.h>
void huan ( int *a,int*b)
{
	int t;

	t=*a;
	*a=*b;
	*b=t;

}
void digui(int a[],int b,int c)
{

}
int main(void)
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	int i;
	

	digui(a,0,8);
	if(a[0]+a[1]+a[4]+a[3]==20&&a[1]+a[2]+a[4]+a[5]==20&&a[3]+a[4]+a[6]+a[7]==20&&a[4]+a[5]+a[7]+a[8]==20&&a[1]+a[3]+a[7]+a[5]==20&&a[0]+a[2]+a[6]+a[8]==20)
	{
		for(i=0;i<=2;i++)
		{
			if(i==2||i==5||i==8)
				printf("%d\n",&a[i]);
			else
				printf("%d  ",&a[i]);
		}
		
		return 0;	
			
	}









}