//
// Created by 孙启龙 on 2017/8/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 5555
#define INF0x3f3f3f3f

using namespace std;

vector<int>G[maxn], GG[maxn];
int a, b, n, m, num[maxn], vis[maxn];
int u, v;
int ans1, ans2, ans3;

int dfs1(int u)
{
    if(vis[u])
        return 0;
    vis[u] = true;
    int ans = 1;
    for(int i = 0; i < G[u].size(); i++)
        ans += dfs1(G[u][i]);
    return ans;
}

int dfs2(int u)
{
    if(vis[u])
        return 0;
    vis[u] = true;
    int ans = 1;
    for(int i = 0; i < GG[u].size(); i++)
        ans += dfs2(GG[u][i]);

    return ans;
}

int main (void)
{
    while(scanf("%d %d %d %d", &a, &b, &n, &m) != EOF)
    {
        for(int i = 0; i < n; i++)
            G[i].clear(), GG[i].clear();
        while(m--)
            scanf("%d %d", &u, &v), G[u].push_back(v), GG[v].push_back(u);

        ans1 = ans2 = ans3 = 0;
        for(int i = 0; i < n; i++)
            memset(vis, 0, sizeof(vis)), num[i] = dfs1(i);
        for(int i = 0; i < n; i++)
            (n - num[i] < a)? ans1++: ans1, (n - num[i] < b)? ans2++: ans2;

        for(int i = 0; i < n; i++)
            memset(vis, 0, sizeof(vis)), num[i] = dfs2(i);
        for(int i = 0; i < n; i++)
            num[i] > b? ans3++ : ans3;

        printf("%d\n%d\n%d\n", ans1, ans2, ans3);
    }
    return 0;
}