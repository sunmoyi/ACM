//
// Created by 孙启龙 on 2017/10/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>

#define maxn 110

using namespace std;

vector<int>G[maxn];
int V[maxn][maxn];
int temp[maxn];
int n, m, S;
int ans;

void dfs(int u, int tot)
{
    if(tot == S)
    {
        ans++;
        return;
    }
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        bool flag = true;
        for(int j = 1; j <= tot; j++)
            if(!V[temp[j]][v])
                flag = false;
        if(!flag)
            continue;
        temp[tot + 1] = v;
        dfs(v, tot + 1);
    }
}

int main (void)
{
    int T, u, v;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &n, &m, &S);
        memset(V, 0, sizeof(V));
        for(int i = 0; i < maxn; i++)
            G[i].clear();

        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            if(u > v)
                swap(u, v);
            G[u].push_back(v);
            V[u][v] = V[v][u] = 1;
        }
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            temp[1] = i;
            dfs(i, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}