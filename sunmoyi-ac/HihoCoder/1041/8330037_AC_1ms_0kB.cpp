//
// Created by 孙启龙 on 2017/3/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 110

using namespace std;

bool vis[maxn][maxn], ans;
vector<int>G[maxn];
int way[maxn][maxn];
int n, op, List[maxn], now;

void getway(int u, int v)
{
    way[u][u] = 1;
    for(int i = 0; i < G[u].size(); i++)
    {
        if(G[u][i] == v)
            continue;
        getway(G[u][i], u);
        for(int j = 1; j <= n; j++)
            if(way[G[u][i]][j])
                way[u][j] = 1;
    }
}

void dfs(int u, int v)
{
    if(u == List[now + 1])
        now++;
    if(now == op)
    {
        ans = true;
        return;
    }
    while(now < op)
    {
        int nextt = List[now + 1], nowop = now;
        for(int i = 0; i < G[u].size(); i++)
        {
            if(G[u][i] == v)
                continue;
            if(way[G[u][i]][nextt] && vis[u][G[u][i]])
            {
                vis[u][G[u][i]] = false;
                dfs(G[u][i], u);
                break;
            }
        }
        if(nowop == now)
            return;
    }
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(vis, false, sizeof(vis));
        memset(way, 0, sizeof(way));
        for(int i = 0; i < maxn; i++)
            G[i].clear();

        scanf("%d", &n);
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            vis[u][v] = vis[v][u] = true;
        }

        scanf("%d", &op);
        for(int i = 1; i <= op; i++)
            scanf("%d", &List[i]);

        now = 0;ans = false;
        getway(1, -1);
        dfs(1, -1);

        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}