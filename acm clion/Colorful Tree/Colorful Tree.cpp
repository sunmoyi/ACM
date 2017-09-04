//
// Created by 孙启龙 on 2017/8/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 200010

using namespace std;

long long color[maxn], sz[maxn], sum[maxn], vis[maxn];
vector<int>tree[maxn];
long long ans;

long long dfs(int u, int pa)
{
    sz[u] = 1;
    long long allson = 0;
    for(int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i];
        if(v == pa)
            continue;
        long long last = sum[color[u]];
        sz[u] += dfs(v, u);
        long long add = sum[color[u]] - last;
        ans += (sz[v] - add) * (sz[v] - add - 1) / 2;
        allson += sz[v] - add;
    }
    sum[color[u]] += allson + 1;
    return sz[u];
}

int main (void)
{
    int n, Case = 0;
    while(scanf("%d", &n) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        memset(sum, 0, sizeof(sum));

        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld\n", &color[i]);
            if(!vis[color[i]])
                ++cnt;
            vis[color[i]] = 1;
            tree[i].clear();
        }
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        printf("Case #%d: ", ++Case);
        if(cnt == 1)
        {
            printf("%lld\n", (long long)n * (n - 1ll) / 2ll);
            continue;
        }

        ans = 0;
        dfs(1, -1);
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
                continue;
            ans += (n - sum[i]) * (n - sum[i] - 1ll) / 2ll;
        }
        printf("%lld\n", (long long)n * (n - 1ll) / 2ll * cnt - ans);
    }
    return 0;
}