#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

const int MAXN=610;
int F[MAXN];
int val[MAXN];
int find(int x)
{
    if(F[x]==-1)return x;
    int tmp=find(F[x]);
    val[x]+=val[F[x]];
    val[x]%=2;
    return F[x]=tmp;
}
int a[MAXN][2];//a[i][0],a[i][1]表示每个大集合分成两部分的个数
vector<int>b[MAXN][2];
bool used[MAXN];
int dp[MAXN][MAXN/2];
int pre[MAXN][MAXN/2];
int main()
{
    int n,p1,p2;
    while(scanf("%d%d%d",&n,&p1,&p2)==3)
    {
        if(n==0 && p1==0 && p2==0)break;
        memset(F,-1,sizeof(F));
        memset(val,0,sizeof(val));
        int u,v;
        char str[10];
        while(n--)
        {
            scanf("%d%d%s",&u,&v,&str);
            int tmp;
            if(str[0]=='y')//相同
              tmp=0;
            else tmp=1;//相反
            int t1=find(u),t2=find(v);
            if(t1!=t2)
            {
                F[t1]=t2;
                val[t1]=(val[v]-val[u]+tmp+2)%2;
            }
        }
        for(int i=0;i<MAXN;i++)
        {
            b[i][0].clear();
            b[i][1].clear();
            a[i][0]=0;
            a[i][1]=0;
        }
        memset(used,false,sizeof(used));
        int cnt=1;
        for(int i=1;i<=p1+p2;i++)
          if(!used[i])
          {
              int tmp=find(i);
              for(int j=i;j<=p1+p2;j++)
              {
                  if(find(j)==tmp)
                  {
                      used[j]=true;
                      b[cnt][val[j]].push_back(j);
                      a[cnt][val[j]]++;
                  }
              }
              cnt++;
          }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<cnt;i++)
        {
            for(int j=p1;j>=0;j--)
            {
                if(j-a[i][0]>=0 && dp[i-1][j-a[i][0]])
                {
                    dp[i][j]+=dp[i-1][j-a[i][0]];
                    pre[i][j]=j-a[i][0];
                }

                if(j-a[i][1]>=0 && dp[i-1][j-a[i][1]])
                {
                    dp[i][j]+=dp[i-1][j-a[i][1]];
                    pre[i][j]=j-a[i][1];
                }

            }
        }
        if(dp[cnt-1][p1]!=1)
        {
            printf("no\n");
        }
        else
        {
            vector<int>ans;
            ans.clear();
            int t=p1;
            //printf("%d\n",cnt);

            for(int i=cnt-1;i>=1;i--)
            {
                int tmp=t-pre[i][t];
                //printf("%d\n",i);
                //printf("%d  %d\n",t,tmp);
                if(tmp==a[i][0])
                {
                    for(int j=0;j<a[i][0];j++)
                      ans.push_back(b[i][0][j]);
                }
                else
                {
                    for(int j=0;j<a[i][1];j++)
                      ans.push_back(b[i][1][j]);
                }
                t=pre[i][t];
            }

            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++)
              printf("%d\n",ans[i]);
            printf("end\n");
        }

    }
    return 0;
}