//
// Created by 孙启龙 on 2017/7/19.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define maxm 20010
#define INF 0x3f3f3f3f
using namespace std;

struct edge{
    int v, to;
}e[maxn];
int p, q, head[maxn], a[maxn], c[maxn << 1];
bool vis[maxn];
long long k, s[maxn << 1], ans;

void add_edge(int u, int v)
{
    e[p].v = v;
    e[p].to = head[u];
    head[u] = p++;
}

int lowbit(int a)
{
    return a & (-a);
}

void update(int i, int x)
{
    for(;i <= q; i += lowbit(i))
        c[i] += x;
}

int sum(int n)
{
    int sum = 0;
    for(int i = n; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}

void dfs(int x)
{
    ans += sum(lower_bound(s, s + q, a[x] ? k / a[x] : INF) - s + 1);
    update(lower_bound(s, s + q, a[x]) - s + 1, 1);
    for(int i = head[x]; i != -1; i = e[i].to)
        dfs(e[i].v);
    update(lower_bound(s, s + q, a[x]) - s + 1, -1);
}

int main (void)
{
    int t, n, u, v;
    scanf("%d", &t);
    while(t--)
    {
        p = q = 0;
        ans = 0;
        memset(head, -1, sizeof(head));
        memset(c, 0, sizeof(c));
        memset(vis, false, sizeof(vis));
        scanf("%d %lld", &n, &k);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            s[q++] = a[i];
            if(!a[i])
                s[q++] = INF;
            else
                s[q++] = k / a[i];
        }
        sort(s, s + q);
        q = unique(s, s + q) - s;
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);
            vis[v] = true;
            add_edge(u, v);
        }
        for(int i = 1; i <= n; i++)
            if(!vis[i])
                dfs(i);
        printf("%lld\n", ans);
    }
    return 0;
}