//
// Created by 孙启龙 on 2017/8/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1000005

using namespace std;

struct Edge{
    int v, w;
    Edge(int v = 0, int w = 0): v(v), w(w){}
};
vector<Edge>G[maxn];
int w[maxn];

int size[maxn];

void dfs(int u, int pre)
{
    size[u] = 1;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].v;
        if(v != pre)
        {
            w[v] = G[u][i].w;
            dfs(v, u);
            size[u] += size[v];
        }
    }
}

int main (int agrc, char* agrv[])
{
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF)
    {
        for(int i = 1; i <= n; i++)
            G[i].clear();
        memset(size, 0, sizeof(size));
        memset(w, 0, sizeof(w));

        for(int i = 1; i <= n - 1; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(Edge(v, w));
            G[v].push_back(Edge(u, w));
        }
        dfs(1, -1);
        long long sum = 0;
        for(int i = 2; i <= n; i++)
            sum += (long long)w[i] * min(size[i], k);
        printf("%lld\n", sum);
    }
    return 0;
}