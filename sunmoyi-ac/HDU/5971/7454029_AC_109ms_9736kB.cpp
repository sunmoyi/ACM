//
// Created by 孙启龙 on 2016/11/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 500010

using namespace std;

int color[maxn];
vector<int>G[maxn];
int n, m, x, y;

bool dfs(int u)
{
    int size = G[u].size();
    for(int i = 0; i < size; i++)
    {
        if(color[G[u][i]] == -1)
        {
            color[G[u][i]] = !color[u];
            if(!dfs(G[u][i]))
                return false;
        }
        else if(color[G[u][i]] == color[u])
            return false;
    }
    return true;
}

int main (void)
{
    int a, b;
    while(scanf("%d %d %d %d", &n, &m, &x, &y) != EOF)
    {
        for(int i = 0; i <= n; i++)
            G[i].clear();
        memset(color, -1, sizeof(color));
        if(n == 1)
        {
            printf("NO\n");
            continue;
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
        }
        for(int i = 1; i <= x; i++)
        {
            scanf("%d", &a);
            color[a] = 1;
        }
        for(int i = 1; i <= y; i++)
        {
            scanf("%d", &a);
            color[a] = 0;
        }
        if(x == 0 && y == 0)
        {
            printf("NO\n");
            continue;
        }

        bool flag = true;
        for(int i = 1; i <= n; i++)
            if(!dfs(i))
                flag = false;
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}