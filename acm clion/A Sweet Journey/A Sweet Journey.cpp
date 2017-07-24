//
// Created by 孙启龙 on 2017/7/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

int dis[maxn];

int main (void)
{
    int test,i,j,n,A,B,L,temp1,temp2,ans;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        memset(dis,0,sizeof(dis));
        scanf("%d%d%d%d",&n,&A,&B,&L);
        for(j=1;j<=n;j++)
        {
            scanf("%d%d",&temp1,&temp2);
            dis[temp2]=(-1)*(temp2-temp1)*(A+B);
        }
        ans=0;
        for(j=1;j<=L;j++)
        {
            dis[j]=dis[j-1]+dis[j]+B;
            ans=min(ans,dis[j]);
        }
        printf("Case #%d: %d\n",i,-1*ans);
    }
    return 0;
}