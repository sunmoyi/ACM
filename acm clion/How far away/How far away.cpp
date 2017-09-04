//
// Created by 孙启龙 on 2017/8/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 80080

using namespace std;

int father[maxn], head[maxn], qhead[maxn], dist[maxn];
struct edgenode{
    int to, next, lca;
}edge[maxn];
edgenode qedge[maxn];
bool vis[maxn];
int n, m, id, iq;

void init()
{
    id = 0;
    iq = 0;
    memset(head, -1, sizeof(head));
    memset(father, 0, sizeof(father));
    memset(qhead, -1, sizeof(qhead));
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
}

int find(int x)
{
    return x == father[x]? x: father[x] = find(father[x]);
}

void LCA(int u)
{
    father[u] = u;
    vis[u] = true;
    for(int k = head[u]; k != -1; k = edge[k].next)
    {
        int v = edge[k].to;
        if(!vis[v])
        {
            dist[v] = dist[u] + edge[k].lca;
            LCA(v);
            father[v] = u;
        }
    }

    for(int k = qhead[u]; k != -1; k = qedge[k].next)
    {
        int v = qedge[k].to;
        if(vis[v])
        {
            qedge[k].lca = dist[u] + dist[v] - 2 * dist[find(v)];
            qedge[k ^ 1].lca = qedge[k].lca;
        }
    }
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d %d", &n, &m);
        for(int i = 1; i < n; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edge[id].to = v;
            edge[id].next = head[u];
            edge[id].lca = w;
            head[u] = id++;
            edge[id].to = u;
            edge[id].next = head[v];
            edge[id].lca = w;
            head[v] = id++;
        }

        for(int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            qedge[iq].to = v;
            qedge[iq].next = qhead[u];
            qhead[u] = iq++;
            qedge[iq].to = u;
            qedge[iq].next = qhead[v];
            qhead[v] = iq++;
        }
        LCA(1);
        for(int i = 0; i < iq; i += 2)
            printf("%d\n", qedge[i].lca);
    }
    return 0;
}