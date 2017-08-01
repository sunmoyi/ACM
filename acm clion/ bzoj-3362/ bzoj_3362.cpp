//
// Created by 孙启龙 on 2017/7/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

int N, V, Ans;
int cnt = 0;
int d[maxn];
int edge[maxn << 1], nextt[maxn << 1], head[maxn << 1];

void add(int u, int v)
{
    edge[cnt] = v;
    nextt[cnt] = head[u];
    head[u] = cnt++;
}

void dfs(int u, int fa)
{
    Ans = max(Ans, d[u]);
    for(int i = head[u]; i; i = nextt[i])
    {
        int v = edge[i];
        if(v == fa)
            continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int main (void)
{
    scanf("%d %d", &V, &N);
    int u, v;
    for(int i = 1; i < V; i++)
    {
        scanf("%d %d", &u, &v);;
        add(u, v);
        add(v, u);
    }

    d[0] = 1;
    dfs(0, -1);
    if(N + 1 <= Ans)
        printf("%d", N + 1);
    else
    {
        Ans = Ans + ((N - Ans + 1) >> 1);
        printf("%d\n", min(Ans, V));
    }
    return 0;
}