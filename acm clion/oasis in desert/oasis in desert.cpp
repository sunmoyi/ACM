//
// Created by 孙启龙 on 2017/7/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>

#define INF 0x3f3f3f3f
#define maxn 510
using namespace std;

int p[maxn];
int dis[maxn][maxn];
vector<int>G[maxn];
int f[maxn], vis[maxn];
int cnt;
int t, n, m, k, a, b, l;

void floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

void initgraph()
{
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(dis[i][j] <= k)
                G[i].push_back(j), G[j].push_back(i);
}

bool dfs(int u, int col)
{
    p[u]=col;

    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(p[v]==col)//如果相邻的两个点颜色一样，那就是非法的
            return false;
        else if(p[v]==0)
        {
            if(col==1)
            {
                if(!dfs(v,2))
                    return false;
            }
            else
            {
                if(!dfs(v,1))
                    return false;
            }
        }
    }
    return true;
}

bool pain()
{
    for(int i=1;i<=n;i++)
    {
        if(p[i]==0)
        {
            p[i]=1;
            if(!dfs(i,1))
                return false;
        }
    }
    return true;
}

bool dfs2(int i)
{
    vis[i] = true;
    for(int j = 0; j < G[i].size(); j++)
    {
        int u = G[i][j];
        if(f[u] == -1 || (!vis[f[u]] && dfs2(f[u])))
        {
            f[u] = i;
            f[i] = u;
            return 1;
        }
    }
    return 0;
}

bool match()
{
    memset(f, -1, sizeof(f));
    for(int i = 1; i <= n; i++)
    {
        if(f[i] == -1)
        {
            memset(vis, 0, sizeof(vis));
            cnt += dfs2(i);
        }
    }
    return cnt * 2 == n;
}

void solve()
{
    int con = 1;
    for(int i = 1; i <= n; i++)
        if(dis[1][i] < INF)
            con++;
    if(!pain() || con < n || !match())
        printf("Impossible\n");
    else
    {
        vector<int>ans;
        for(int i = 1; i <= n; i++)
            if(p[i] == 1)
                ans.push_back(i);
        printf("%ld\n", ans.size());
        for(int i = 0; i < ans.size() - 1; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans.back());
    }
}

int main (void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &m, &k);
        memset(dis, 0x3f, sizeof(dis));
        for(int i = 1; i <= n; i++)
            dis[i][i] = 0;
        memset(p, 0, sizeof(p));
        memset(G, 0, sizeof(G));
        cnt = 0;
        while(m--)
        {
            scanf("%d %d %d", &a, &b, &l);
            dis[a][b] = dis[b][a] = l;
        }
        if(n == 0)
            printf("0\n");
        else
        {
            floyd();
            initgraph();
            solve();
        }
    }
    return 0;
}