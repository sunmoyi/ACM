//
// Created by 孙启龙 on 2017/3/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define INF 1000010

using namespace std;

struct Edge{
    int to, next;
    int cap;
}edge[maxn << 1];

int n, m, cnt, head[maxn];
int dp[maxn], vis[maxn];

void addedge(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].cap = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void DP(int u, int pre, int lim)
{
    int flag = 0;
    dp[u] = 0;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != pre)
        {
            flag = 1;
            DP(v, u, lim);
            if(edge[i].cap <= lim)
                dp[u] += min(dp[v], edge[i].cap);
            else
                dp[u] += dp[v];
        }
    }
    if(!flag)
        dp[u] = INF;
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        if(n == 0 && m == 0)
            break;
        cnt = 0;
        memset(head, -1, sizeof(head));
        int maxx = 0;
        int u, v, w;
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
            if(w > maxx)
                maxx = w;
        }
        int l = 1, r = maxx, ans = -1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            DP(1, -1, mid);
            if(dp[1] <= m)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}