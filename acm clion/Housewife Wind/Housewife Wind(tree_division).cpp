//
// Created by 孙启龙 on 2017/5/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100010

using namespace std;

int n, head[maxn], cnt, tot, q, s, c;
int dep[maxn], father[maxn], son[maxn], siz[maxn], w[maxn], top[maxn], summ[maxn];

struct node{
    int u, v, w, next;
}edge[maxn << 1];

void addedge(int u, int v, int w)
{
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void init()
{
    memset(head, 0xff, sizeof(head));
    memset(dep, 0, sizeof(dep));
    memset(son, 0, sizeof(son));
    memset(summ, 0, sizeof(summ));
    cnt = 0;
    tot = 0;
}

void dfs1(int u, int fa)
{
    siz[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == fa)
            continue;
        father[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[son[u]] < siz[v])
            son[u] = v;
    }
}

void dfs2(int u, int tp)
{
    w[u] = ++tot;
    top[u] = tp;
    if(son[u])
        dfs2(son[u], tp);
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != son[u] && v != father[u])
            dfs2(v, v);
    }
}

struct LineTree{
    void PushUp(int rt)
    {
        summ[rt] = summ[rt << 1] + summ[ rt << 1 | 1];
    }
    void update(int p, int x, int l, int r, int rt)
    {
        if(l == r)
        {
            summ[rt] = x;
            return ;
        }
        int mid = (l + r) >> 1;
        if(p <= mid)
            update(p, x, l, mid, rt<<1);
        else
            update(p, x, mid + 1, r, rt << 1 | 1);
        PushUp(rt);
    }
    int query(int ll, int rr, int l, int r, int rt)
    {
        if(ll <= l && rr >= r)
        {
            return summ[rt];
        }
        int mid = (l + r) >> 1, ans = 0;
        if(ll <= mid)
            ans += query(ll, rr, l, mid, rt<<1);
        if(rr > mid)
            ans += query(ll, rr, mid + 1, r, rt << 1 | 1);
        return ans;
    }
}trees;

int solve(int u, int v)
{
    int f1 = top[u], f2 = top[v], ans = 0;
    while(f1 != f2)
    {
        if(dep[f1] < dep[f2])
        {
            swap(u, v);
            swap(f1, f2);
        }
        ans += trees.query(w[f1], w[u], 1, n, 1);
        u = father[f1];
        f1 = top[u];
    }
    if(u == v)
        return ans;
    if(dep[u] < dep[v])
        swap(u, v);
    return ans + trees.query(w[son[v]], w[u], 1, n, 1);
}

int main (void)
{
    int u, v, x;
    while(scanf("%d %d %d", &n, &q, &s) != EOF)
    {
        init();
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d %d", &u, &v, &c);
            addedge(u, v, c);
            addedge(v, u, c);
        }
        dfs1(1, -1);
        dfs2(1, 1);
        for(int i = 0; i < cnt; i += 2)
        {
            u = edge[i].u;
            v = edge[i].v;
            if(dep[u] < dep[v])
                swap(u, v);
            trees.update(w[u], edge[i].w, 1, n, 1);
        }
        while(q--)
        {
            scanf("%d", &x);
            if(!x)
            {
                scanf("%d", &v);
                printf("%d\n", solve(s, v));
                s = v;
            }
            else
            {
                scanf("%d %d", &x, &c);
                u = edge[(x - 1) << 1].u;
                v = edge[(x - 1) << 1].v;
                if(dep[u] < dep[v])
                    swap(u, v);
                trees.update(w[u], c, 1, n, 1);
            }
        }
    }
    return 0;
}