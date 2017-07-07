//
// Created by 孙启龙 on 2016/11/17.
//

#include<stdio.h>
#include<cmath>
#include<string.h>
using namespace std;
bool zero(int n,int x[])
{
    for(int i=0;i<n;++i)
    {
        if(x[i])
        {
            return 0;
        }
    }
    return 1;
}
void slove(int n,int x[])
{
    int time=1000;
    while(time--)
    {
        int tp[15];
        for(int i=0;i<n;++i)
        {
            tp[i]=abs(x[i%n]-x[(i+1)%n]);
        }
        for(int i=0;i<n;++i)
        {
            x[i]=tp[i];
        }
        if(zero(n,x))
        {
            printf("ZERO\n");
            return;
        }
    }
    printf("LOOP\n");
}
int main()
{
    int t,n,x[20];
    //freopen("shuju.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&x[i]);
        }
        slove(n,x);
    }
    return 0;
}