#include<cstdio>  
#include<string>  
#include<cstring>  
#include<iostream>  
#include<cmath>  
#include<algorithm>  
using namespace std;  
struct eg  
{  
    int x,y,w;  
}e[1005];  
bool cmp(eg a,eg b)  
{  
    if(a.x==b.x)  
        return a.y<b.y;  
    return a.x<b.x;  
}  
int main()  
{  
    int n,m,r,dp[1005],ans;  
    scanf("%d%d%d",&n,&m,&r);  
    for(int i=0;i<m;i++)  
    {  
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);  
    }  
    sort(e,e+m,cmp);  
    ans=0;  
    for(int i=0;i<m;i++)dp[i]=e[i].w;  
    for(int i=0;i<m;i++)  
    {  
        for(int j=0;j<i;j++)  
        {  
            if(e[i].x>=e[j].y+r)  
            dp[i]=max(dp[i],dp[j]+e[i].w);  
        }  
        ans=max(ans,dp[i]);  
    }  
    printf("%d\n",ans);  
    return 0;  
}  