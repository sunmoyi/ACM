//
// Created by 孙启龙 on 2017/1/19.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000

using namespace std;

int n, m, G[maxn][maxn], c[maxn], topo[maxn], t;

bool dfs(int u)
{
    c[u] = -1;
    for(int v = 0; v < n; v++)
        if(G[u][v])
        {
            if(c[v] < 0)
                return false;
            else if (!c[v])
                dfs(v);
        }
    c[u] = 1;
    topo[--t] = u;
    return true;
}

bool topsort()
{
    t = n;
    memset(c, 0, sizeof(c));
    for(int u = 0; u < n; u++)
        if(!c[u])
            if(!dfs(u))
                return false;
    return true;
}

int main (void)
{
    while(scanf("%d %d", &n, &m) == 2 && n)
    {
        memset(G, 0, sizeof(G));
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            G[u][v] = 1;
        }
        if(topsort())
        {
            for(int i = 0; i < n - 1; i++)
                printf("%d ", topo[i] + 1);
            printf("%d\n", topo[n - 1] + 1);
        }
        else
            printf("No\n");
    }
    return 0;
}