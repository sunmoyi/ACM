//
// Created by 孙启龙 on 2017/7/29.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>
#include <queue>

#define maxn 200100

using namespace std;

long long a[maxn], ans;
int n, m, T, cnt, ok[maxn], vis[maxn], pre[maxn], nextt[maxn], to[maxn], tot[maxn], col;
vector<int>s[maxn];
queue<int>q;

void dfs(int x, int fa)
{
    s[col].push_back(x);
    ok[x] = 0;
    for(int p = pre[x]; p != -1; p = nextt[p])
    {
        if((!vis[p]) || (!ok[to[p]]))
            continue;
        if(p == (fa ^ 1))
            continue;
        dfs(to[p], p);
    }
}

void addedge2(int x, int y)
{
    to[cnt] = y;
    nextt[cnt] = pre[x];
    pre[x] = cnt++;
}

void addedge(int x, int y)
{
    addedge2(x, y);
    addedge2(y, x);
}

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        memset(tot, 0, sizeof(tot));
        memset(pre, -1, sizeof(pre));
        memset(ok, -1, sizeof(pre));
        memset(vis, 1, sizeof(vis));
        ans = 0LL, cnt = 0;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for(int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            tot[x]++;
            tot[y]++;
            addedge(x, y);
        }
        while(!q.empty())
            q.pop();
        for(int i = 1; i <= n; i++)
            if(tot[i] < 2)
                q.push(i);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            ok[x] = 0;
            for(int p = pre[x]; p != -1; p = nextt[p])
            {
                vis[p] = 0;
                tot[x]--;
                tot[to[p]]--;
                if(ok[to[p]] && tot[to[p]] < 2)
                    q.push(to[p]);
            }
        }
        col = 0;
        for(int i = 1; i <= n; i++)
        {
            col++;
            s[col].clear();
            if(ok[i])
            {
                dfs(i, cnt + 10);
                if(s[col].size() % 2 == 1)
                {
                    for(int j = 0; j < s[col].size(); j++)
                    {
                        ans += a[s[col][j]];
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}