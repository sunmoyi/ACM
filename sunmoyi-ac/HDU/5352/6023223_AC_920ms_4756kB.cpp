#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 205;
const int N = 205*500;
vector <int> G[N];
int ans[maxn*2], p[maxn], used[maxn], vis[maxn];
int n, m, k, num, nu, maps[maxn][maxn];
void dfs (int u)
{//求连通块内的点
    vis[u] = 1;
    p[num ++] = u;
    for (int i=1; i<=n; i++)
        if (!vis[i] && maps[u][i])
            dfs (i);
}
bool Find (int u)
{
    for (int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if (!vis[v])
        {
            vis[v] = 1;
            if (!used[v] || Find(used[v]))
            {
                used[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungry ()
{
    int res = 0;
    memset (used, 0, sizeof(used));
    for (int i=nu-1; i>=0; i--)//倒序求最大匹配
        for (int j=i*k; j<(i+1)*k; j++)
        {
            memset (vis, 0, sizeof(vis));
            if (Find(j))
            {
                res ++;
                ans[i] ++;
            }
        }
    return res;
}
int main ()
{
    int t;
    scanf ("%d", &t);
    while (t --)
    {
        scanf ("%d %d %d", &n, &m, &k);
        memset (maps, 0, sizeof(maps));
        for (int i=0; i<N; i++)
            G[i].clear();
        nu = 0;
        while (m --)
        {
            int type, x, y, z;
            scanf ("%d", &type);
            if (type == 1)
            {
                scanf ("%d", &x);
                num = 0;
                memset (vis, 0, sizeof(vis));
                dfs (x);
                for (int i=0; i<num; i++)//建边
                    for (int j=nu*k; j<(nu+1)*k; j++)//拆点
                        G[j].push_back(p[i]);
                nu ++;
            }
            else if (type == 2)
            {
                scanf ("%d %d", &x, &y);
                maps[x][y] = maps[y][x] = 1;
            }
            else
            {
                scanf ("%d", &z);
                while (z --)
                {
                    scanf ("%d %d", &x, &y);
                    maps[x][y] = maps[y][x] = 0;
                }
            }
        }
        memset (ans, 0, sizeof(ans));
        int res = hungry ();
        printf ("%d\n", res);
        for (int i=0; i<nu; i++)
            printf ("%d%c", ans[i], i==nu-1?'\n':' ');
    }
    return 0;
}