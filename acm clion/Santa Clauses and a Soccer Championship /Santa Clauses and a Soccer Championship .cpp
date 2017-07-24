//
// Created by 孙启龙.
//

#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn=2e5+50;
int vis[maxn];
int n,k,root,sum;
int home[maxn];
vector<int> one,two;
vector<int> g[maxn];

int find_Root(int u)
{
    int sum=home[u]?1:0;
    for(int i=0; i<g[u].size(); i++)
    {
        int nt=g[u][i];
        if(!vis[nt])
        {
            vis[nt]=1;
            sum+=find_Root(nt);
        }
    }
    if(sum>=k&&root==-1) root=u;
    return sum;
}
void solve(int u)
{
    if(home[u])
    {
        if(one.size()<k)
            one.push_back(u);
        else
            two.push_back(u);
    }
    for(int i=0; i<g[u].size(); i++)
    {
        int nt=g[u][i];
        if(!vis[nt])
        {
            vis[nt]=1;
            solve(nt);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0; i<2*k; i++)
    {
        int x;
        scanf("%d",&x);
        home[x]=1;
    }
    memset(vis,0,sizeof(vis));
    vis[1]=1,root=-1;
    find_Root(1);
    memset(vis,0,sizeof(vis));
    vis[root]=1;
    solve(root);
    printf("1\n%d\n",root);
    for(int i=0; i<one.size(); i++)
        printf("%d %d %d\n",one[i],two[i],root);
    return 0;
}