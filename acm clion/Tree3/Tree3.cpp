//
// Created by 孙启龙 on 2017/10/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxm 55555
#define maxn 11111

using namespace std;

struct Edge{
    int v, next, w;
}edge[maxm];
int head[maxn], e;
int n, k, vis[maxn], ans, root, num;
int maxx[maxn], size[maxn], mi, dis[maxn];

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

void dfs_size(int u, int fa)
{
    size[u] = 1;
    maxx[u] = 0;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != fa && !vis[v])
        {
            dfs_size(v, u);
            size[u] += size[v];
            maxx[u] = max(maxx[u], size[v]);
        }
    }
}

void dfs_root(int r, int u, int fa)
{
    if(size[r] - size[u] > maxx[u])
        maxx[u] = size[r] - size[u];
    if(maxx[u] < mi)
        mi = maxx[u], root = u;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != fa && !vis[v])
            dfs_root(r, v, u);
    }
}

void dfs_dis(int u, int d, int fa)
{
    dis[num++] = d;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != fa && !vis[v])
            dfs_dis(v, d + edge[i].w, u);
    }
}

int calc(int u, int d)
{
    int ret = 0;
    num = 0;
    dfs_dis(u, d, 0);
    sort(dis, dis + num);
    int i = 0, j = num - 1;
    while(i < j)
    {
        while(dis[i] + dis[j] > k && i < j)
            j--;
        ret += (j - i);
        i++;
    }
    return ret;
}

void solve(int u)
{
    mi = n;
    dfs_size(u, 0);
    dfs_root(u, u, 0);
    ans += calc(root, 0);
    vis[root] = 1;
    for(int i = head[root]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(!vis[v])
        {
            ans -= calc(v, edge[i].w);
            solve(v);
        }
    }
}

int main (void)
{
    int u, v, w;
    while(scanf("%d %d", &n, &k) != EOF && (n + k))
    {
        init();
        for(int i = 0; i < n - 1; i++)
            scanf("%d %d %d", &u, &v, &w), add(u, v, w), add(v, u, w);
        solve(1);
        printf("%d\n", ans);
    }
    return 0;
}
