//
// Created by 孙启龙 on 2017/8/7.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include <functional>
#include <cmath>

#define maxn 100010

using namespace std;
struct edge{
    int to, next;
}G[maxn << 1];
int id, head[maxn];
int tot, deep[maxn << 1], father[maxn << 1], dp[20][maxn << 1], first[maxn], timee[maxn << 1];
int n, m;
bool vis[maxn];
int a[maxn];

void init()
{
    id = 0;
    memset(head, -1, sizeof(head));
    tot = 0;
    memset(vis, 0, sizeof(vis));
}

void addedge(int u, int v)
{
    G[id].to = v;
    G[id].next = head[u];
    head[u] = id++;
}

void dfs(int u, int fa, int cur)
{
    vis[u] = true;
    timee[++tot] = u;
    deep[tot] = cur;
    first[u] = tot;
    father[u] = fa;

    for(int i = head[u]; i != -1; i = G[i].next)
    {
        int v = G[i].to;
        if(!vis[v])
        {
            dfs(v, u, cur + 1);
            timee[++tot] = u, deep[tot] = cur;
        }
    }
}

void RMQinit(int n)
{
    for(int i = 1; i <= n; i++)
        dp[0][i] = i;
    for(int i = 1; (1<<i) <= n; i++)
        for(int j = 1; j <= n - (1<<i) + 1; j++)
            dp[i][j] = deep[dp[i-1][j]] < deep[dp[i-1][j+(1<<(i-1))]] ? dp[i-1][j] : dp[i-1][j+(1<<(i-1))];
}

int RMQ(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return deep[dp[k][l]] < deep[dp[k][r-(1<<k)+1]] ? dp[k][l] : dp[k][r-(1<<k)+1];
}

int LCA(int v, int u)
{
    v = first[v], u = first[u];
    if(v > u)
        swap(v, u);
    int pos = RMQ(v, u);
    return timee[pos];
}

int solve(int l, int r, int k)
{
    int temp[maxn], num = 0;
    int lca = LCA(l ,r);
    while(l != lca)
        temp[num++] = a[l], l = father[l];
    while(r != lca)
        temp[num++] = a[r], r = father[r];
    temp[num++] = a[lca];
    sort(temp, temp + num, greater<int>());

    if(k > num)
        return -0x3f3f3f3f;
    else
        return temp[k - 1];
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        init();
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d %d", &v, &u);
            addedge(v, u);
            addedge(u, v);
        }
        dfs(1, 0, 1);
        RMQinit(2 * n - 1);
        for(int i = 1; i <= m; i++)
        {
            int u, v, k;
            scanf("%d %d %d", &k, &u, &v);
            if(k == 0)
                a[u] = v;
            else
            {
                int ans = solve(u, v, k);
                if(ans == -0x3f3f3f3f)
                    printf("invalid request!\n");
                else
                    printf("%d\n", ans);
            }
        }
    }
    return 0;
}