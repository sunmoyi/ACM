#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=200010;
int F[MAXN];
int val[MAXN];
int find(int x)
{
    if(F[x]==-1)return x;
    int tmp=find(F[x]);
    val[x]+=val[F[x]];
    return F[x]=tmp;
}
int main()
{
    int n,m;
    int u,v,w;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(F,-1,sizeof(F));
        memset(val,0,sizeof(val));
        int ans=0;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            u=u-1;
            int t1=find(u);
            int t2=find(v);
            if(t1!=t2)
            {
                F[t2]=t1;
                val[t2]=val[u]-val[v]+w;
            }
            else
            {
                if(val[v]-val[u]!=w)ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}