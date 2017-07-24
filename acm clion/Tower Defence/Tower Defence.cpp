//
// Created by 孙启龙 on 2017/7/19.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100010

using namespace std;

struct Edge{
    int v, next, c;
    Edge(int v = 0, int next = 0, int c = 0): v(v), next(next), c(c){};
}edge[maxn << 1];
int head[maxn], dp[maxn][2], nextt[maxn][2], pre[maxn], max1[maxn], max2[maxn];
int tot;
struct Node{
    int u, v;
    Node(int u = 0, int v = 0): u(u), v(v){};
}temp[maxn];

void init()
{
    memset(head, -1, sizeof(head));
    tot = 0;
}

void add_edge(int a, int b, int c)
{
    edge[tot] = Edge(b, head[a], c);
    head[a] = tot++;
}

void dfs(int u, int fa)
{
    pre[u] = fa;
    dp[u][0] = dp[u][1] = 0;
    nextt[u][0] = nextt[u][1] = u;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == fa)
            continue;
        dfs(v, u);
        if(dp[u][0] < dp[v][0] + edge[i].c)
        {
            swap(dp[u][0], dp[u][1]);
            swap(nextt[u][0], nextt[u][1]);
            dp[u][0] = dp[v][0] + edge[i].c;
            nextt[u][0] = nextt[v][0];
        }
        else if (dp[u][1] < dp[v][0] + edge[i].c)
        {
            dp[u][1] = dp[v][0] + edge[i].c;
            nextt[u][1] = nextt[v][0];
        }
    }
}

void dfs1(int u, int fa)
{
    max1[u] = 0;
    dp[u][0] = dp[u][1] = 0;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == fa)
            continue;
        dfs1(v, u);
        max1[u] = max(max1[u], max1[v]);
        if(dp[u][0] < dp[v][0] + edge[i].c)
        {
            swap(dp[u][0], dp[u][1]);
            dp[u][0] = dp[v][0] + edge[i].c;
        }
        else if (dp[u][1] < dp[v][0] + edge[i].c)
            dp[u][1] = dp[v][0] + edge[i].c;
    }
    max1[u] = max(max1[u], dp[u][0] + dp[u][1]);
}

void dfs2(int u, int fa)
{
    max2[u] = 0;
    dp[u][0] = dp[u][1] = 0;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == fa)
            continue;
        dfs2(v, u);
        max2[u] = max(max2[u], max2[v]);
        if(dp[u][0] < dp[v][0] + edge[i].c)
        {
            swap(dp[u][0], dp[u][1]);
            dp[u][0] = dp[v][0] + edge[i].c;
        }
        else if (dp[u][1] < dp[v][0] + edge[i].c)
            dp[u][1] = dp[v][0] + edge[i].c;
    }
    max2[u] = max(max2[u], dp[u][0] + dp[u][1]);
}

int main (void)
{
    int t, a, b, c;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        init();
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            add_edge(a, b, c);
            add_edge(b, a, c);
        }
        dfs(1, -1);
        int ret = 0, u, v, w;
        for(int i = 1; i <= n; i++)
        {
            if(ret < dp[i][0] + dp[i][1])
            {
                ret = dp[i][0] + dp[i][1];
                u = nextt[i][0];
                v = nextt[i][1];
                w = i;
            }
        }

        dfs1(u, -1);
        dfs2(v, -1);
        int cnt = 0;
        while(u != w)
        {
            temp[cnt++] = Node(u, pre[u]);
            u = pre[u];
        }
        while(v != w)
        {
            temp[cnt++] = Node(pre[v], v);
            v = pre[v];
        }
        long long ans = (long long) (n - 1 - cnt) * ret;
        for(int i = 0; i < cnt; i++)
            ans += max(max1[temp[i].v], max2[temp[i].u]);
        cout << ans << endl;
    }
    return 0;
}