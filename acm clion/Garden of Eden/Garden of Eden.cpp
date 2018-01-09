//
// Created by 孙启龙 on 2017/10/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>

#define maxn 500010

using namespace std;

int n, k, maxx, root;
long long ans;
vector<int>tree[maxn];
vector<int>sta;
int size[maxn], maxv[maxn], a[maxn];
long long hashh[1200];
bool vis[maxn];

void init()
{
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i++)
        tree[i].clear();
}

void dfs_size(int u, int fa)
{
    size[u] = 1;
    maxv[u] = 0;
    for(int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i];
        if(v == fa || vis[v])
            continue;
        dfs_size(v, u);
        size[u] += size[v];
        maxv[u] = max(maxv[u], size[v]);
    }
}

void dfs_root(int r, int u, int fa)
{
    if(size[r] - size[u] > maxv[u])
        maxv[u] = size[r] - size[u];
    if(maxv[u] < maxx)
        maxx = maxv[u], root = u;
    for(int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i];
        if(v == fa || vis[v])
            continue;
        dfs_root(r, v, u);
    }
}

void dfs_state(int u, int pre, int s)
{
    sta.push_back(s);
    int cnt = tree[u].size();
    for (int i = 0; i < cnt; i++) {
        int v = tree[u][i];
        if (v == pre || vis[v]) continue;
        dfs_state(v, u, s | (1 << a[v]));
    }
}

long long cal(int u, int s)
{
    long long res = 0;
    sta.clear();
    dfs_state(u, -1, s);
    memset(hashh, 0, sizeof(hashh));
    int cnt = sta.size();
    for(int i = 0; i < cnt; i++)
        hashh[sta[i]]++;
    for(int i = 0; i < cnt; i++)
    {
        hashh[sta[i]]--;
        res += hashh[(1 << k) - 1];
        for(int s0 = sta[i]; s0; s0 = (s0 - 1) & sta[i])
            res += hashh[((1 << k) - 1) ^ s0];
        hashh[sta[i]]++;
    }
    return res;
}

void dfs(int u)
{
    maxx = n;
    dfs_size(u, -1);
    dfs_root(u, u, -1);
    ans += cal(root, (1 << a[root]));
    vis[root] = true;
    int rt = root;//mark 使用vector这里会出现这个问题，在dfs的过程中root会变
    for(int i = 0; i < tree[rt].size(); i++)
    {
        int v = tree[rt][i];
        if(!vis[v])
        {
            ans -= cal(v, (1 << a[rt]) | (1 << a[v]));
            dfs(v);
        }
    }
}

int main (void)
{
    int u, v;
    while(scanf("%d %d", &n, &k) != EOF)
    {
        init();
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]), --a[i];
        for(int i = 1; i < n; i++)
            scanf("%d %d", &u, &v), tree[u].push_back(v), tree[v].push_back(u);
        if(k == 1)
            printf("%d\n", n * n);
        else
        {
            ans = 0;
            dfs(1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}