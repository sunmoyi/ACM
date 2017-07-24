//
// Created by 孙启龙 on 2017/4/25.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

#define MEM(a) memset(a, 0 ,sizeof(a))

const int maxn = 10000*2+5;
vector<int> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], ans[maxn], dfs_clock, scc_cnt;
stack<int> s;

void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    s.push(u);
    for (int i = 0; i < (int)G[u].size(); i++)
    {
        int v = G[u][i];
        if (!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (!sccno[v])
            lowlink[u] = min(lowlink[u], pre[v]);
    }
    if (lowlink[u] == pre[u])
    {
        scc_cnt++;
        for (;;)
        {
            int x = s.top();
            s.pop();
            sccno[x] = scc_cnt;
            if (x == u)
                break;
        }
    }

}
void find_scc(int n)
{
    dfs_clock = scc_cnt = 0;
    MEM(sccno); MEM(pre); MEM(ans);
    for (int i = 1; i <= n; i++)
    {
        if (!pre[i])
            dfs(i);
    }
}
int main()
{
    int n, m, u, v;
    while (~scanf("%d %d",&n, &m))
    {
        for (int i = 1; i <= n; i++)
            G[i].clear();
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d",&u, &v);
            G[u].push_back(v);
        }
        find_scc(n);

        for (int i = 1; i <= n; i++)
        {
            ans[sccno[i]]++;
        }
        int cnt = 0;
        for (int i = 0; i <= scc_cnt; i++)
        {
            if (ans[i] > 1)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}