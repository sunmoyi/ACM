#include<stdio.h>
int main()
{
    int i,arr[10],max=arr[0];
    int *p;
    p=arr;
    for(i=0;i<10;i++)
        scanf("%d",&arr[i]);

    for(p=arr;p<arr+10;p++)
    {
        if(*p>max)
            max = *p;
    }
    printf("The maximum number=%d\n",max);
    return 0;
}