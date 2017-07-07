#include<stdio.h>
int main()
{
    int sum,n,a,i;
    while((scanf("%d",&n)!=EOF)&&n!=0)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
              scanf("%d",&a);
              sum=sum+a;;
        }
        printf("%d\n",sum);
    }
 return 0;
}