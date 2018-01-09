//
// Created by 孙启龙 on 2017/10/23.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#define maxn 100010

using namespace std;

int n, m, timee, cnt, dfn[maxn], low[maxn], belong[maxn], sum[maxn], in[maxn], out[maxn];
bool visited[maxn];
vector<int>G[maxn];
stack<int>S;

void init()
{
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(belong, 0, sizeof(belong));
    memset(sum, 0, sizeof(sum));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    while(!S.empty())
        S.pop();
    for(int i = 0; i < maxn; i++)
        G[i].clear();
    timee = 1;
    cnt = 0;
}

void input()
{
    int u, v;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }
}

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = timee++;
    S.push(u);
    visited[u] = 1;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
//        if(v == fa)
//            continue;
        if(!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (visited[v])
            low[u] = min(dfn[v], low[u]);
    }
    if(low[u] == dfn[u])
    {
        cnt++;
        while(true)
        {
            int t = S.top();
            S.pop();
            belong[t] = cnt;
            sum[cnt]++;
            visited[t] = false;
            if(t == u)
                break;
        }
    }
}

void build()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < G[i].size(); j++)
        {
            int x = belong[i], y = belong[G[i][j]];
            if(x != y)
                out[x]++, in[y]++;
        }
    }
}

long long get_ans()
{
    long long ans = -1;
    for(int i = 1; i <= cnt; i++)
    {
        if(!in[i] || !out[i])
        {
            long long x = sum[i], y = n - sum[i];
            ans = max(ans, x * y + x * (x - 1) + y * (y - 1) - m);
        }
    }
    return ans;
}

void solve(int Case)
{
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i, i);
    if(cnt == 1)
        printf("Case %d: -1\n", Case);
    else
    {
        build();
        printf("Case %d: %lld\n", Case, get_ans());
    }
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        init();
        input();
        solve(Case);
    }
    return 0;
}