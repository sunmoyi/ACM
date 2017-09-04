//
// Created by 孙启龙 on 2017/8/7.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define maxm 100010

using namespace std;

int id, iq;
int head[maxn], qhead[maxn], dp[maxn], fa[maxn], vis[maxn], lca[maxn << 1];
struct Edge{
    int u, v, next;
    Edge(int u = 0, int v = 0, int next = 0): u(u), v(v), next(next){}
}edge[maxn << 1], qedge[maxn << 1];

void init()
{
    id = iq = 0;
    memset(head, 0xff, sizeof(head));
    memset(qhead, 0xff, sizeof(qhead));
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < maxn; i++)
        fa[i] = i;
}

void addedge(int u, int v){
    edge[id].u = u;
    edge[id].v = v;
    edge[id].next = head[u];
    head[u] = id++;
};

void addask(int u, int v)
{
    qedge[iq].u = u;
    qedge[iq].v = v;
    qedge[iq].next = qhead[u];
    qhead[u] = iq++;
}

int find(int x)
{
    return x == fa[x]? x: fa[x] = find(fa[x]);
}

void tarjan(int u)
{
    vis[u] = 1;
    fa[u] = u;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(!vis[v])
        {
            tarjan(v);
            fa[v] = u;
        }
    }

    for(int i = qhead[u]; i != -1; i = qedge[i].next)
    {
        int v = qedge[i].v;
        if(vis[v])
            lca[i] = lca[i ^ 1] = find(v);
    }
}

void DP(int u)
{
    vis[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(!vis[v])
        {
            DP(v);
            dp[u] += dp[v];
        }
    }
}

int main (void)
{
    int n, q;
    while(scanf("%d %d", &n, &q) != EOF)
    {
        init();
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        for(int i = 1; i <= q; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            addask(u, v);
            addask(v, u);
            dp[u]++;dp[v]++;
        }
        tarjan(1);
        for(int i = 1; i <= q << 1; i += 2)
            dp[lca[i]] -= 2;
        memset(vis, 0, sizeof(vis));
        DP(1);
        int res = 0;
        for(int i = 2; i <= n; i++)
        {
            if(dp[i] == 1)
                res++;
            else if (dp[i] == 0)
                res += q;
        }
        printf("%d\n", res);
    }
}