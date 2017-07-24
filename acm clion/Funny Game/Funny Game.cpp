//
// Created by 孙启龙 on 2017/5/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
    int n,sum[200010],i,dp[200010];
    while(scanf("%d",&n)!=EOF)
    {
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            scanf("%d",&sum[i]),sum[i]+=sum[i-1];

        dp[n]=sum[n];
        for(i=n-1;i>=2;i--)
            dp[i]=max(dp[i+1],sum[i]-dp[i+1]);

        printf("%d\n",dp[2]);
    }
    return 0;
}