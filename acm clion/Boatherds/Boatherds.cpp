//
// Created by 孙启龙 on 2017/10/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 11111
#define maxm 55555

using namespace std;

struct Edge{
    int v, next, w;
}edge[maxm];
int head[maxn], e;
int n, k, vis[maxn], ans, root, num;
int maxx[maxn], size[maxn], mi, dis[maxn];

void init()
{
    memset(head, -1, sizeof(head));
    e = 0;
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
            maxx[u] = max(maxx[u], maxx[v]);
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
        if(dis[i] + dis[j] < k)
            i++;
        else if (dis[i] + dis[j] > k)
            j--;
        else
        {
            if(dis[i] == dis[j])
            {
                ret += (j - i) * (j - i + 1) / 2;
                break;
            }
            int st = i, ed = j;
            while(dis[st] == dis[i])
                st++;
            while(dis[ed] == dis[j])
                ed--;
            ret += (st - i) * (j - ed);
            i = st, j = ed;
        }
    }
    return ret;
}

void dfs(int u)
{
    mi = n;
    dfs_size(u, 0);
    dfs_root(u, u, 0);
    ans += calc(root, 0);
    vis[root] = true;
    for(int i = head[u]; i != -1; i = edge[i].next)
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
    int v, w;
    while(scanf("%d", &n) != EOF && n)
    {
        init();
        for(int i = 1; i <= n; i++)
        {
            while(scanf("%d", &v) != EOF && v)
            {
                scanf("%d", &w);
                add(i, v, w);
                add(v, i, w);
            }
        }
        while(scanf("%d", &k) != EOF && k)
        {
            memset(vis, 0, sizeof(vis));
            ans = 0;
            dfs(1);
            if(ans > 0)
                printf("AYE\n");
            else
                printf("NAY\n");
        }
        printf(".\n");
    }
    return 0;
}