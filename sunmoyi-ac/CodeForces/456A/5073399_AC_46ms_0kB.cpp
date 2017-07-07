#include<stdio.h>
#define N 100050
int main() 
{
	int n,a,b,flag=1,i;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
	{
        scanf("%d%d",&a,&b);
		if ( a != b ) 
			flag=0;
	}
    if (flag) 
		printf("Poor Alex\n");
    else 
		printf("Happy Alex\n");
     return 0;
}