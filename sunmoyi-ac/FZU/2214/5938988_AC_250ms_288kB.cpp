#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0xf3f3f3f
using namespace std;
struct Money
{
    int w;
    int v;
}aver[5005];
int dp[5005];

int main()
{
    int t,n,m;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            cin>>n>>m;
            int sum=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d%d",&aver[i].w,&aver[i].v);
                sum+=aver[i].v;
            }
            memset(dp,INF,sizeof(dp));
            dp[0]=0;
            for(int i=0;i<n;i++)
                for(int j=sum;j>=aver[i].v;j--)
                    dp[j]=min(dp[j],dp[j-aver[i].v]+aver[i].w);
            for(int i=sum;i>=0;i--)
            {
                if(dp[i]<=m)
                {
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
