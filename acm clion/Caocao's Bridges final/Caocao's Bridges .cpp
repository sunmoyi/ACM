//
// Created by 孙启龙 on 2017/10/23.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

struct Edge{
    int to, next, w;
}edge[maxn * maxn];
int tot;
int head[maxn];
int n, m;
int dfn[maxn], low[maxn], sta[maxn], col[maxn];
int tt, sum, scc, top;

void addedge(int u, int v, int w)
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;

    edge[tot].to = u;
    edge[tot].w = w;
    edge[tot].next = head[v];
    head[v] = tot++;
}

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++tt;
    sta[++top] = u;
    int cnt = 0;
    for(int i = head[u]; i != 0; i = edge[i].next)
    {
        int v = edge[i].to;
        if(!dfn[v])
        {
            sum++;
            tarjan(v, u);
            low[u] = min(low[v], low[u]);
        }
        else if (fa == v)
        {
            if(cnt > 0)
                low[u] = min(low[u], dfn[v]);
            cnt++;
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        int x;
        scc++;
        do{
            x = sta[top--];
            col[x] = scc;
        }while(x != u);
    }
}

int main (void)
{
    int u, v, w;
    int ans;
    while(scanf("%d %d", &n, &m) != EOF && (n + m))
    {
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(col, 0, sizeof(col));
        memset(head, 0, sizeof(head));
        tot = sum = 1;
        tt = scc = top = 0;
        ans = 10010;
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
        }
        tarjan(1, 1);
        if(sum < n)
            printf("0\n");
        else
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = head[i]; j != 0; j = edge[j].next)
                {
                    int v = edge[j].to;
                    if(col[i] != col[v])
                        ans = min(ans, edge[j].w);
                }
            }
            printf("%d\n", ans?(ans == 10010?-1:ans):1);
        }
    }
    return 0;
}