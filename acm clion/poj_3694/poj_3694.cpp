//
// Created by 孙启龙 on 2017/8/7.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define maxm 500050
#define mem0(x) memset(x, 0, sizeof(x))
#define mem1(x) memset(x, -1, sizeof(x))

using namespace std;

struct Edge{
    int v, next;
}edge[maxm];
int low[maxn], dfn[maxn], Index, vis[maxn], Dfn[maxn];
int e, n, m, head[maxn];
int cnt, bridge[maxn], father[maxn];

void init()
{
    e = 0, Index = 0, cnt = 0;
    mem0(vis);
    mem0(dfn);
    mem0(Dfn);
    mem0(bridge);
    mem1(head);
    for(int i = 1; i <= n; i++)
        father[i] = i;
}

void insert(int x, int y)
{
    edge[e].v = y;
    edge[e].next = head[x];
    head[x] = e++;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++Index;
    Dfn[u] = Dfn[father[u]] + 1;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(!dfn[v])
        {
            father[v] = u;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u])
                cnt++, bridge[v] = 1;
        }
        else if (v != father[u])
            low[u] = min(low[u], dfn[v]);
    }
}

void LCA(int u, int v)
{
    while (Dfn[u] > Dfn[v])
    {
        if (bridge[u])
            cnt--, bridge[u] = 0;
        u = father[u];
    }
    while (Dfn[v] > Dfn[u])
    {
        if (bridge[v])
            cnt--, bridge[v] = 0;
        v = father[v];
    }
    while (u != v)
    {
        if (bridge[u])
            cnt--, bridge[u] = 0;
        if (bridge[v])
            cnt--, bridge[v] = 0;
        u = father[u];
        v = father[v];
    }
}

void ask()
{
    int q, u, v;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d %d", &u, &v);
        LCA(u, v);
        printf("%d\n", cnt);
    }
    printf("\n");
}

int main (void)
{
    int Case = 1;
    while(scanf("%d %d", &n, &m) != EOF && (n + m))
    {
        printf("Case %d:\n", Case++);
        init();
        int x, y;
        while(m--)
        {
            scanf("%d %d", &x, &y);
            insert(x, y);
            insert(y, x);
        }
        tarjan(1);
        ask();
    }
    return 0;
}