//
// Created by 孙启龙 on 2017/8/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 400010

using namespace std;

int in[maxn], out[maxn];
long long dp[maxn];
int head[maxn], nextt[maxn], to[maxn], tot = 0;
int n, m, u, v;

void build(int u, int v)
{
    to[++tot] = v;
    nextt[tot] = head[u];
    head[u] = tot;
}

long long dfs(int u)
{
    if(dp[u])
        return dp[u];

    if(out[u] == 0 && in[u])
        dp[u]++;
    for(int i = head[u]; i; i = nextt[i])
    {
        int v = to[i];
        dp[u] += dfs(v);
    }
    return dp[u];
}

int main (void)
{
    memset(dp, 0, sizeof(dp));
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d", &u, &v);
        build(u, v);
        in[v]++, out[u]++;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        if(!in[i])
            ans += dfs(i);
    printf("%lld\n", ans);
    return 0;
}