#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#define LL long long
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9;
const int N=5e2+10;
char s1[N],s2[N];
int k,dp[N],pre[N];
int main()
{
    while(~scanf("%d",&k))
    {
        scanf("%s%s",s1+1,s2+1);
        int ans=0,l1=strlen(s1+1),l2=strlen(s2+1);
        for(int i=1;i<=l2;i++)
        {
            int p1=1,p2=i,cnt=0;
            while(p1<=l1&&p2<=l2)
            {
                if(s1[p1]==s2[p2])
                    dp[p1]=dp[p1-1];
                else
                {
                    dp[p1]=dp[p1-1]+1;
                    pre[++cnt]=p1;
                }
                if(dp[p1]<=k)
                    ans=max(ans,p1);
                else
                    ans=max(ans,p1-pre[dp[p1]-k]);
                p1++,p2++;
            }
        }
        for(int i=1;i<=l1;i++)
        {
            int p1=i,p2=1,cnt=0;
            while(p1<=l1&&p2<=l2)
            {
                if(s1[p1]==s2[p2])
                    dp[p2]=dp[p2-1];
                else
                {
                    dp[p2]=dp[p2-1]+1;
                    pre[++cnt]=p2;
                }
                if(dp[p2]<=k)
                    ans=max(ans,p2);
                else
                    ans=max(ans,p2-pre[dp[p2]-k]);
                p1++,p2++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}