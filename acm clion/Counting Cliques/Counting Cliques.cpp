//
// Created by 孙启龙 on 2016/11/2.
//
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 110

using namespace std;

vector<int>G[maxn];
int v[maxn][maxn];
int n, m, s, ans;
int T;
int tem[20];
int vis[maxn];

void dfs(int u, int temp[], int size)
{
    if(size == s)
    {
        ans++;
        return;
    }
    for(int i = 0; i < G[u].size(); i++)
    {
        int V = G[u][i];
        bool flag = true;
        for(int j = 1; j <= size; j++)
            if(v[V][temp[j]] == 0)
                flag = false;
        if(flag)
        {
            temp[size + 1] = V;
            dfs(V, temp, size + 1);
        }
    }
}

int main (void)
{
    int a, b;
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%d %d %d", &n, &m, &s);
            for(int i = 1; i <= n; i++)
                G[i].clear();
            ans = 0;
            memset(vis, 0, sizeof(vis));
            memset(v, 0, sizeof(v));
            for(int i = 1; i <= m; i++)
            {
                scanf("%d %d", &a, &b);
                if(a > b)
                    swap(a, b);
                G[a].push_back(b);
                v[a][b] = v[b][a] = 1;
            }

            for(int i = 1; i <= n; i++)
            {
                tem[1] = i;
                dfs(i, tem, 1);

            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
