//
// Created by 孙启龙 on 2017/8/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 10010

using namespace std;

vector<int>G[maxn];
int father[maxn], depth[maxn];
bool vis[maxn];
int qx, qy, ans;

void init()
{
    for(int i = 0; i < maxn; i++)
        G[i].clear();
    memset(vis, false, sizeof(vis));
}

int find(int x)
{
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];
}

void LCA(int u)
{
    father[u] = u;
    vis[u] = true;
    for(int k = 0; k < G[u].size(); k++)
    {
        int v = G[u][k];
        if(!vis[v])
        {
            depth[v] = depth[u] + 1;
            LCA(v);
            father[v] = u;
        }
    }

    if(qx == u && vis[qy])
        ans = depth[qx] + depth[qy] - 2 * depth[find(qy)];
    if(qy == u && vis[qx])
        ans = depth[qx] + depth[qy] - 2 * depth[find(qx)];
}

int main (void)
{
    int t, n, x, y;
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d", &n);
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
        }
        scanf("%d %d", &qx, &qy);
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                depth[i] = 1;
                LCA(i);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}