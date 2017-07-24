//
// Created by 孙启龙 on 2017/4/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10010
#define maxm 50050

using namespace std;

struct Edge{
    int v, next, w;
}edge[maxm];
int head[maxn], e;
int n, k, vis[maxn], ans, root, num;
int mx[maxn], size[maxn], mi, dis[maxn];

void init()
{
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    e = ans = 0;
}

void add(int u, int v, int w)
{
    edge[e].v = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
}

void dfssize(int u, int fa)
{
    size[u] = 1;
    mx[u] = 0;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != fa && !vis[v])
        {
            dfssize(v, u);
            size[u] += size[v];
            mx[u] = max(mx[u], size[v]);
        }
    }
}

void dfsroot(int r, int u, int fa)
{
    if(size[r] - size[u] > mx[u])
        mx[u] = size[r] - size[u];
    if(mx[u] < mi)
        mi = mx[u], root = u;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v= edge[i].v;
        if(v != fa && !vis[v] )
            dfsroot(r, v, u);
    }
}

void dfsdis(int u, int d, int fa)
{
    dis[num++] = d;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != fa && !vis[v])
            dfsdis(v, d + edge[i].w, u);
    }
}

int calc(int u, int d)
{
    int ret = 0;
    num = 0;
    dfsdis(u, d, 0);
    sort(dis, dis + num);
    int i = 0, j = num - 1;
    while(i < j)
    {
        while(dis[i] + dis[j] > k && i < j)
            j--;
        ret += j - i;
        i++;
    }
    return ret;
}

void dfs(int u)
{
    mi = n;
    dfssize(u, 0);
    dfsroot(u, u, 0);
    ans += calc(root, 0);
    vis[root] = 1;
    for(int i = head[root]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(!vis[v])
        {
            ans -= calc(v, edge[i].w);
            dfs(v);
        }
    }
}

int main (void)
{
    while(scanf("%d %d", &n, &k) != EOF && (n || k))
    {
        init();
        int u, v, w;
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}