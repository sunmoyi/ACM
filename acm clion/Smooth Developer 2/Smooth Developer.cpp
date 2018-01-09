//
// Created by 孙启龙 on 2017/8/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<string>

#define maxn 111111

using namespace std;

map<string, int>M;
vector<int>g[maxn];
int T, n, k, vis[maxn], num;
char c[22], s[maxn][22];
string str;

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(vis[v])
            continue;
        dfs(v);
    }
}

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        M.clear();
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++)
            g[i].clear();
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", s[i]);
            str = s[i];
            M[str] = i;
            scanf("%d", &num);
            while(num--)
            {
                scanf("%s", c);
                str = c;
                int pos = M[str];
                if(pos != i)
                    g[i].push_back(pos);
            }
        }
        memset(vis, 0, sizeof(vis));
        while(k--)
        {
            scanf("%s", c);
            if(!vis[M[c]])
                dfs(M[c]);
        }
        for(int i = 1; i <= n; i++)
            if(vis[i])
                printf("%s\n", s[i]);
    }
    return 0;
}