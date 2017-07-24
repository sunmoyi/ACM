//
// Created by 孙启龙 on 2017/5/1.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long LL;
const int MAXN=1e+5 + 1000;
const int INF = numeric_limits<int>::max();
const LL LL_INF= numeric_limits<LL>::max();
struct Edge
{
    int to,next;
    bool vis,bge;
    Edge(){}
    Edge(int _to,int _next):to(_to),next(_next){vis=false;bge=false;}
}e[MAXN*2];
int cas=0;
int dfn[MAXN],low[MAXN],pre[MAXN];
int sta[MAXN],bleg[MAXN];
int times,n,m,top;
int tot,head[MAXN];
void init(){
    memset(head,-1,sizeof(head));
    tot=0;
}
void Add(int u,int v){
    e[tot]=Edge(v,head[u]);
    head[u]=tot++;
    e[tot]=Edge(u,head[v]);
    head[v]=tot++;
}
int res[MAXN];
void tarjan_3(int u){
    dfn[u]=low[u]=++times;
    sta[++top]=u;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].to;
        if(e[i].vis)continue;
        e[i].vis=e[i^1].vis=true;
        if(!dfn[v]){
            pre[v]=u;
            tarjan_3(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!bleg[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        bleg[0]++;
        res[bleg[0]]=u;
        do{
            bleg[sta[top]]=bleg[0];
            res[bleg[0]]=max(res[bleg[0]],sta[top]);
        }while(sta[top--]!=u);
        bleg[u]=bleg[0];
    }
}
Edge edg[MAXN*2];
int dep[MAXN],val[MAXN],head1[MAXN],tot1;
void init1(){
    memset(head1,-1,sizeof(head1));
    memset(dep,0,sizeof(dep));
    tot1=0;
}
void AddEdge(int u,int v){
    edg[tot1]=Edge(v,head1[u]);
    head1[u]=tot1++;
    edg[tot1]=Edge(u,head1[v]);
    head1[v]=tot1++;
}
void dfs(int u,int d){
    dep[u]=d;
    val[u]=res[u];
    for(int i=head1[u];~i;i=edg[i].next){
        int v=edg[i].to;
        if(!dep[v]){
            dfs(v,d+1);
            val[u]=max(val[u],val[v]);
        }
    }
}
void solve()
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(pre,0,sizeof(pre));
    memset(bleg,0,sizeof(bleg));
    top=times=0;
    tarjan_3(1);

    for(int i=0;i<tot;i++)
    {
        if(e[i].bge)
            continue;
        int u=e[i].to;
        int v=e[i^1].to;
        if(pre[v]==u&&dfn[u]<low[v])
        {
            e[i].bge=e[i^1].bge=true;

        }
    }
    init1();
    for(int i=0;i<tot;i+=2){
        int u=e[i].to,v=e[i^1].to;
        if(bleg[u]!=bleg[v]){
            AddEdge(bleg[u],bleg[v]);
        }
    }

    dfs(bleg[n],1);

    for(int i=0;i<tot;i+=2)
    {
        int u=e[i].to,v=e[i^1].to;
        if(e[i].bge)
        {
            if(dep[bleg[u]]>dep[bleg[v]])
                printf("%d %d\n",val[bleg[u]],val[bleg[u]]+1);
            else
                printf("%d %d\n",val[bleg[v]],val[bleg[v]]+1);
        }
        else printf("0 0\n");
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0,x,y;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            Add(x,y);
        }
        solve();
    }
    return 0;
}