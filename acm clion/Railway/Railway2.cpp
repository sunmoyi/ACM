//
// Created by 孙启龙 on 2017/5/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>

#define maxn 10010
using namespace std;

int n, m;
int ans1, ans2;
vector<int>G[maxn];
int dfs_clock, bcc_cnt;
int dfn[maxn], low[maxn],bccno[maxn];
vector<int> bcc[maxn];
stack<int>S;

void solve()
{
    bool vis[maxn];
    int sum = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= bcc[bcc_cnt][0]; i++)
        vis[bcc[bcc_cnt][i]] = true;
    for(int i = 1; i <= bcc[bcc_cnt][0]; i++)
    {
        int u = bcc[bcc_cnt][i];
        for(int j = 0; j < G[u].size(); j++)
        {
            if(vis[G[u][j]])
                sum++;
        }
    }
    sum /= 2;
    if(sum > bcc[bcc_cnt][0])
        ans2 += sum;
}

void tarjan(int u, int fa)
{
    low[u] = dfn[u] = ++dfs_clock;
    S.push(u);
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u])
            {
                if(low[v] > dfn[u])
                    ans1++;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                bcc[bcc_cnt].push_back(0);
                while(true)
                {
                    int x = S.top();
                    S.pop();
                    bcc[bcc_cnt][0]++;
                    bcc[bcc_cnt].push_back(x);
                    bccno[x] = bcc_cnt;
                    if(x == v)
                        break;
                }
                bcc[bcc_cnt][0]++;
                bcc[bcc_cnt].push_back(u);
                bccno[u] = bcc_cnt;
                solve();
            }
        }
        else if (v != fa)
            low[u] = min(low[u], dfn[v]);
    }
}

int main(void)
{
    while(scanf("%d %d", &n, &m) != EOF && (n + m))
    {
        ans1 = ans2 = bcc_cnt = dfs_clock = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        for(int i = 0; i < n; i++)
            G[i].clear();
        int u, v;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 0; i < n; i++)
            if(!dfn[i])
                tarjan(i, -1);
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
