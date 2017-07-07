//
// Created by 孙启龙 on 2017/3/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 200010

using namespace std;

vector<int>G[maxn];
int color[maxn];
int num[maxn], ans;
int n;

void dfs(int u, int fa, int fafa)
{
    if(num[fa] == 0)
        num[fa]++;
    if(num[fa] == color[fa] || num[fa] == color[fafa])
        num[fa]++;
    if(num[fa] == color[fa] || num[fa] == color[fafa])
        num[fa]++;

    color[u] = num[fa];
    num[fa]++;
    ans = max(ans, color[u]);

    for(int i = 0; i < G[u].size(); i++)
    {
        if(G[u][i] != fa)
            dfs(G[u][i], u, fa);
    }
}

int main (void)
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, 0, 0);

    printf("%d\n", ans);
    for(int i = 1; i < n; i++)
        printf("%d ", color[i]);
    printf("%d\n", color[n]);
    return 0;
}