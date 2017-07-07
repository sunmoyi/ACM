#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[12000],st[12000],sf[12000],L[12000];
int main()
{
    int n,s;
    while(scanf("%d%d",&n,&s)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",st+i,sf+i);
        dp[n+1]=st[n+1]=sf[n+1]=0;
        for(int i=n;i>=1;i--)
            st[i]+=st[i+1],sf[i]+=sf[i+1];
        int a=0,b=0;
        L[a]=n+1;
        for(int i=n;i>=1;i--)
        {
            while(a<b&&dp[L[a+1]]-dp[L[a]]<=(st[L[a+1]]-st[L[a]])*sf[i])
                a++;
            dp[i]=dp[L[a]]+(st[i]-st[L[a]]+s)*sf[i];
            while(a<b&&(dp[i]-dp[L[b]])*(st[L[b]]-st[L[b-1]])<=(st[i]-st[L[b]])*(dp[L[b]]-dp[L[b-1]]))
                b--;
            L[++b]=i;
        }
        printf("%d\n",dp[1]);
    }
    return 0;
}