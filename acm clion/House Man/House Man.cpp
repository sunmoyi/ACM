//
// Created by 孙启龙 on 2017/5/5.
//

#include <iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1005;
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[maxn];
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
bool vis[maxn];
int cnt[maxn];
int dist[maxn];
bool spfa(int start,int n)
{
    memset(vis,false,sizeof(vis));
    memset(dist,inf,sizeof(dist));
    vis[start]=true;
    dist[start]=0;
    queue<int>que;
    while(!que.empty()) que.pop();
    que.push(start);
    memset(cnt,0,sizeof(cnt));
    cnt[start]=1;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=0;i<E[u].size();i++)
        {
            int v=E[u][i].v;
            if(dist[v]>dist[u]+E[u][i].cost)
            {
                dist[v]=dist[u]+E[u][i].cost;
                if(!vis[v])
                {
                    vis[v]=true;
                    que.push(v);
                    if(++cnt[v]>n) return false;
                }
            }
        }
    }
    return true;
}
struct node
{
    int val,pos;
}nt[maxn];
bool cmp(node a,node b)
{
    return a.val<b.val;
}
int main()
{
    int t,n,d,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++) scanf("%d",&nt[i].val),nt[i].pos=i;
        sort(nt+1,nt+1+n,cmp);
        for(int i=0;i<=n;i++) E[i].clear();
        for(int i=1;i<n;i++)
        {
            addedge(i+1,i,-1);
            if(nt[i].pos<nt[i+1].pos)
                addedge(nt[i].pos,nt[i+1].pos,d);
            else addedge(nt[i+1].pos,nt[i].pos,d);
        }
        printf("Case %d: ",cas++);
        int minn,maxn;
        if(nt[1].pos<nt[n].pos)minn=nt[1].pos,maxn=nt[n].pos;
        else minn=nt[n].pos,maxn=nt[1].pos;
        if(!spfa(minn,n)) printf("-1\n");
        else printf("%d\n",dist[maxn]);
    }
    return 0;
}