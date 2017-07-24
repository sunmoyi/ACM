//
// Created by 孙启龙 on 2017/3/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1010

using namespace std;

vector<int>adj[maxn];
int vis[maxn][2], d[maxn][2], n, m;

int dp(int i, int j, int f)
{
    if(vis[i][j])
        return d[i][j];
    vis[i][j] = 1;
    int &ans = d[i][j];

    ans = 2000;
    for(int k = 0; k < adj[i].size(); k++)
    {
        if(adj[i][k] != f)
            ans += dp(adj[i][k], 1, i);
    }
    if(!j && f >= 0)
        ans++;

    if(j || f < 0)
    {
        int sum = 0;
        for(int k = 0; k < adj[i].size(); k++)
        {
            if(adj[i][k] != f)
            {
                sum += dp(adj[i][k], 0, i);
            }
        }
        if(f >= 0)
            sum++;
        ans = min(ans, sum);
    }
    return ans;
}

int main (void)
{
    int T, a, b;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            adj[i].clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i][0])
                ans += dp(i, 0, -1);
        }
        printf("%d %d %d\n", ans / 2000, m - ans % 2000, ans % 2000);
    }
    return 0;
}