//
// Created by 孙启龙 on 2017/3/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define cls(x,c) memset(x,c,sizeof(x))
const int N=10005;
const int M=2005;

using namespace std;

int s[N],vis[N];
vector<int>g[N];
int k,n,m;

void dfs(int u)
{
    cls(vis,0);
    vector<int>ne;
    for (int i=0;i<g[u].size();++i)
    {
        int v=g[u][i];
        if (s[v]) vis[s[v]]=1;
        else ne.push_back(v);
    }
    for (int i=1;i<=k;i++)
    {
        if (!vis[i]) {s[u]=i;break;}
    }

    for (int i=0;i<ne.size();i++)
    {
        if (!s[ne[i]]) dfs(ne[i]);
    }
}
int main()
{
    int a,b,ca=0;
    while (~scanf("%d %d",&n,&m))
    {
        if (ca++) puts("");
        for (int i=0;i<n;i++) g[i].clear();
        for (int i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }
        cls(s,0);
        k=-1;
        for (int i=0;i<n;i++) 
            k=max(k,(int)g[i].size());
        if (k%2==0) 
            k++;
        printf("%d\n",k);
        dfs(0);
        for (int i=0;i<n;i++) 
            printf("%d\n",s[i]);
    }
}  