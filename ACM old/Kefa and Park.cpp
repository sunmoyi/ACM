//
// Created by 孙启龙 on 2016/10/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100010

using namespace std;

vector<int>G[maxn];
int n, m, ans, cnt, temp;
int num[maxn];

void dfs(int fa, int u, int k)
{
    if(num[u])
        k++;
    else
        k = 0;

    if(k > m)
        return;

    bool flag = true;
    for(int i = 0; i < G[u].size(); i++)
    {
        if(G[u][i] == fa)
            continue;
        flag = false;
        dfs(u, G[u][i], k);
    }
    if(flag)
        ans++;
}

int main (void)
{
    int a, b;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 0; i <= n + 1; i++)
            G[i].clear();
        for(int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        ans = 0;
        dfs(-1, 1, 0);
        printf("%d\n", ans);
    }
    return 0;
}
