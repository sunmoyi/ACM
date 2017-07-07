//
// Created by 孙启龙 on 16/10/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 150
#define INF 0x3f3f3f3f

using namespace std;

int f[maxn][maxn], g[maxn][maxn], vis[maxn][maxn];
int t, m, n, p, l, cnt;

void spfa()
{
    int st = n + m;
    queue<int>q1;
    queue<int>q2;
    memset(vis, 0, sizeof(vis));
    memset(f, INF, sizeof(f));
    for(int i = 0; i <= cnt; i++)
        f[m + n][i] = 0;
    q1.push(st);
    q2.push(cnt);
    while(!q1.empty())
    {
        int u = q1.front();
        q1.pop();
        int t1 = q2.front();
        q2.pop();
        vis[u][t1] = 0;
        for (int i = 1; i <= n + m; i++)
        {
            if (f[i][t1] > f[u][t1] + g[u][i])
            {
                f[i][t1] = f[u][t1] + g[u][i];
                if (!vis[i][t1])
                {
                    vis[i][t1] = 1;
                    q1.push(i);
                    q2.push(t1);
                }
            }
            if (t1 > 0 && g[u][i] <= l && f[u][t1] < f[i][t1 - 1])
            {
                f[i][t1 - 1] = f[u][t1];
                if (!vis[i][t1 - 1])
                {
                    vis[i][t1 - 1] = 1;
                    q1.push(i);
                    q2.push(t1 - 1);
                }
            }
        }
    }
}

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n + m; i++)
            for (int j = 1; j <= n + m; j++)
                if (g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
}

int main (void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d %d", &n, &m, &p, &l, &cnt);
        memset(g, INF, sizeof(g));
        int u, v, w;
        for(int i = 0; i < p; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            g[u][v] = g[v][u] = w;
        }
        floyd();
        spfa();
        int minn = INF;
        for(int i = 0; i <= cnt; i++)
            minn = min(minn, f[1][i]);
        printf("%d\n", minn);
    }
    return 0;
}