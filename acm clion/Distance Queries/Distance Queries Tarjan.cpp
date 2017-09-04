//
// Created by 孙启龙 on 2017/8/1.
//

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 80080;
const int MAXQ = 20020;

int father[MAXN],Head[MAXN],QHead[MAXN],Dist[MAXN];

struct EdgeNode
{
    int to;
    int next;
    int lca;
}Edges[MAXN];

EdgeNode QEdges[MAXN];

int find(int x)
{
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];
}

bool vis[MAXN];

void LCA(int u)
{
    father[u] = u;
    vis[u] = true;
    for(int k = Head[u]; k != -1; k = Edges[k].next)
    {
        if(!vis[Edges[k].to])
        {
            Dist[Edges[k].to] = Dist[u] + Edges[k].lca;
            LCA(Edges[k].to);
            father[Edges[k].to] = u;
        }
    }

    for(int k = QHead[u]; k != -1; k = QEdges[k].next)
    {
        if(vis[QEdges[k].to])
        {
            //QEdges[k].lca = find(QEdges[k].to);
            QEdges[k].lca = Dist[u] + Dist[QEdges[k].to] - 2*Dist[find(QEdges[k].to)];
            QEdges[k^1].lca = QEdges[k].lca;
        }
    }
}

int main()
{
    int N,M,K,u,v,w,a,b;
    char s;
    while(~scanf("%d%d",&N,&M))
    {
        memset(father,0,sizeof(father));
        memset(Head,-1,sizeof(Head));
        memset(QHead,-1,sizeof(QHead));
        memset(vis,false,sizeof(vis));
        memset(Edges,0,sizeof(Edges));
        memset(QEdges,0,sizeof(QEdges));
        memset(Dist,0,sizeof(Dist));
        int id = 0;
        for(int i = 0; i < M; ++i)
        {
            scanf("%d%d%d %c",&u,&v,&w,&s);
            Edges[id].to = v;
            Edges[id].lca = w;
            Edges[id].next = Head[u];
            Head[u] = id++;
            Edges[id].to = u;
            Edges[id].lca = w;
            Edges[id].next = Head[v];
            Head[v] = id++;
        }
        scanf("%d",&K);
        int iq = 0;
        for(int i = 0; i < K; ++i)
        {
            scanf("%d%d",&a,&b);
            QEdges[iq].to = b;
            QEdges[iq].next = QHead[a];
            QHead[a] = iq++;
            QEdges[iq].to = a;
            QEdges[iq].next = QHead[b];
            QHead[b] = iq++;
        }
        LCA(1);
        for(int i = 0; i < iq; i+=2)
            printf("%d\n",QEdges[i].lca);
    }

    return 0;
}