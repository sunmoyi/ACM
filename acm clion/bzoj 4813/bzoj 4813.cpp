//
// Created by 孙启龙 on 2017/8/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

#define N 110

using namespace std;

int f[N][N], g[N][N];
int n, m;
int nxt[N << 1], to[N << 1], head[N], cnt;

void add(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    nxt[++cnt] = head[v];
    head[v] = cnt;
    to[cnt] = u;
}

void dfs(int u, int fa)
{
    f[u][0] = g[u][0] = 1;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa)
            continue;
        dfs(v, u);
        for (int i = m; ~i; --i)
        {
            for (int j = 0; j <= i - 1; ++j)
            {
                if (i - j - 2 >= 0)
                    f[u][i] = max(f[u][i], f[v][j] + f[u][i - j - 2]);
                g[u][i] = max(g[u][i], g[v][j] + f[u][i - j - 1]);
                if (i - j - 2 >= 0)
                    g[u][i] = max(g[u][i], f[v][j] + g[u][i - j - 2]);
            }
        }
    }
    for (int i = 0; i < m; ++i)
        f[u][i + 1] = max(f[u][i], f[u][i + 1]);
    for (int i = 0; i < m; ++i)
        g[u][i + 1] = max(g[u][i], g[u][i + 1]);
}

int main()
{

    int u, v;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &u);
        scanf("%d", &v);
        add(u, v);
    }
    dfs(0, 0);
    printf("%d", g[0][m]);
    return 0;
}