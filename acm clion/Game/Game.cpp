//
// Created by 孙启龙 on 2017/3/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50010

using namespace std;

int trap[maxn], gift[maxn], n, c, ans;
int dp[maxn << 1][5], head[maxn], cnt;

struct Edge{
    int u, v, next;
    Edge(int u = 0, int v = 0, int n = 0): u(u), v(v), next(n){}
}edge[maxn << 1];

void add(int u, int v)
{
    edge[cnt] = Edge(u, v, head[u]);
    memset(dp[cnt], -1, 20);
    head[u] = cnt++;
}

int dfs(int dx, int tp)
{
    if(tp == c)
        return 0;
    if(dp[dx][tp] != -1)
        return dp[dx][tp];
    int u = edge[dx].u;
    int v = edge[dx].v;
    int res = gift[v];
    int a = tp + trap[v];
    for(int i = head[v]; i != -1; i = edge[i].next)
    {
        if(edge[i].v == u)
            continue;
        res = max(res, gift[v] + dfs(i, a));
    }
    return dp[dx][tp] = res;
}

int main (void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &c);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &gift[i], &trap[i]);
            head[i] = -1;
        }
        cnt = 0;
        for(int i = 1; i < n; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            add(a, b);
            add(b, a);
        }
        ans = 0;
        for(int i = 0; i < cnt; i++)
        {
            int u = edge[i].u;
            ans = max(ans, gift[u] + dfs(i, trap[u]));
        }
        printf("%d\n", ans);
    }
    return 0;
}