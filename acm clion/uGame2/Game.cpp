//
// Created by 孙启龙 on 2017/4/29.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
#define maxn 100010

using namespace std;

int n, m;
long long a[maxn], x[maxn];
bool vis[maxn];
struct Edge{
    int to, next;
}edge[maxn << 1];
int head[maxn], tot;

void init()
{
    tot = 0;
    memset(head, 0xff, sizeof(head));
}

void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

struct Node{
    long long sum;
    int id;
    bool operator < (const Node&a)const {
        return sum > a.sum;
    }
}node[maxn];

long long dfs1(int u)
{
    if(vis[u])
        return node[u].sum;
    node[u].sum = a[u];
    vis[u] = true;
    for(int i = head[u]; ~i; i = edge[i].next)
        node[u].sum += dfs1(edge[i].to);
    return node[u].sum;
}

long long dfs2(int u)
{
    if(vis[u])
        return 0;
    long long w = a[u];
    vis[u] = true;
    for(int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        w += dfs2(v);
    }
    return w;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        scanf("%d %d", &n, &m);
        memset(node, 0, sizeof(node));
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            node[i].id = i;
        }
        memset(vis, false, sizeof(vis));
        init();
        int u, v;
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);
            addedge(v, u);
        }
        for(int i = 1; i <= n; i++)
            if(!vis[i])
                dfs1(i);

        sort(node + 1, node + n + 1);
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++)
            x[i] = dfs2(node[i].id);

        long long ans = 0;
        sort(x + 1, x + n + 1, greater<long long>());
        for(int i = 1, cnt = 0; i <= n && cnt < m; i++)
            ans += x[i], cnt++;
        printf("Case #%d: %lld\n", Case, ans);
    }
    return 0;
}