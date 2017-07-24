//
// Created by 孙启龙 on 2017/5/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define maxn 1010
#define maxm 2000010

using namespace std;

struct Edge{
    int to, next, from;
    int cut;
}edge[maxm];
int head[maxn], tot, n, m, Index;
int low[maxn], dfn[maxn],belong[maxn], block;
stack<int>S;


void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].from = u;
    edge[tot].next = head[u];
    edge[tot].cut = 0;
    head[u] = tot++;
}

void init_tarjan()
{
    tot = 0;
    Index = block = 0;
    memset(head, -1, sizeof(head));
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(belong, 0, sizeof(belong));
    while(!S.empty())
        S.pop();
}

void tarjan(int u,int pre)
{
    low[u] = dfn[u] = ++Index;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        if(edge[i].cut)
            continue;
        edge[i].cut = 1;
        edge[i ^ 1].cut = -1;
        if( !dfn[v] )
        {
            tarjan(v,u);
            if( low[u] > low[v] )
                low[u] = low[v];
            if(low[v] > dfn[u])
                edge[i^1].cut = 1;
        }
        else if(v != pre)
            low[u] = min(low[u], dfn[v]);
    }
}

int main (void)
{
    int Case = 1, u, v;
    while(scanf("%d %d", &n, &m) != EOF && (n + m))
    {
        init_tarjan();
        while(m--)
        {
            scanf("%d %d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }

        for(int i = 1; i <= n; i++)
            if(!dfn[i])
                tarjan(i, -1);

        printf("%d\n\n", Case++);
        for(int i = 0; i < tot; i++)
            if(edge[i].cut == 1)
                printf("%d %d\n", edge[i].from, edge[i].to);

        printf("#\n");
    }
    return 0;
}