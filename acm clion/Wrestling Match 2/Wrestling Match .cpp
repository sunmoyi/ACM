//
// Created by 孙启龙 on 2017/10/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>

#define maxn 1010

using namespace std;

vector<int>G[maxn];
int n, m, a, b, u, v;
int color[maxn];

void init()
{
    for(int i = 0; i < maxn; i++)
        G[i].clear();
    memset(color, 0, sizeof(color));
}

bool dfs(int u)
{
    for(int i = 0; i < G[u].size(); i++)
    {
        if(color[G[u][i]] == 0)
        {
            color[G[u][i]] = 3 - color[u];
            if(!dfs(G[u][i]))
                return false;
        }
        else
        {
            if(color[G[u][i]] == color[u])
                return false;
        }
    }
    return true;
}

int main (void)
{
    while(scanf("%d %d %d %d", &n, &m, &a, &b) != EOF)
    {
        init();
        for(int i = 1; i <= m; i++)
            scanf("%d %d", &u, &v), G[u].push_back(v);
        for(int i = 1; i <= a; i++)
            scanf("%d", &u), color[u] = 1;
        for(int i = 1; i <= b; i++)
            scanf("%d", &u), color[u] = 2;
        if(a == 0 && b == 0)
            printf("NO\n");
        else
        {
            bool flag = true;
            for(int i = 1; i <= n; i++)
                if(flag && color[i] != 0 && !dfs(i))
                    flag = false;
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}