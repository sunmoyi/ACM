//
// Created by 孙启龙 on 2017/7/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define maxn 20010

using namespace std;

struct node{
    int to, next;
}edge[maxn << 1];
int tot, head[maxn], deep[maxn], fa[maxn], ans[maxn];

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}

void add(int from, int to)
{
    edge[tot].to = to;
    edge[tot].next = head[from];
    head[from] = tot++;
}

void dfs(int u, int father, int dep)
{
    deep[u] = dep;
    ans[u] = 1;
    fa[u] = father;

    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != father)
            dfs(v, u, dep + 1);
    }
}

void LCA(int x, int y)
{
    while(x != y)
    {
        if(deep[x] > deep[y])
        {
            ans[x]++;
            x = fa[x];
        }
        else
        {
            ans[y]++;
            y = fa[y];
        }
    }
}

int main (void)
{
    int t, n, m, i;
    scanf("%d", &t);

    for(int j = 1; j <= t; j++)
    {
        init();
        int u, v;
        scanf("%d %d", &n, &m);
        for(i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);
            add(u, v);
            add(v, u);
        }
        dfs(1, 0, 1);

        for(;i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            LCA(u, v);
        }

        int res = INF;
        for(int i = 2; i <= n; i++)
            res = min(res, ans[i]);
        printf("Case #%d: %d\n", j, res);
    }
}