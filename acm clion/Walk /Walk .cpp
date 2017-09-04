//
// Created by 孙启龙 on 2017/8/5.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 55
#define maxm 10005

using namespace std;

int T, n, u, v, m, d;
double dp[maxm][maxn];
vector<int>g[maxm];

void init()
{
    scanf("%d %d %d", &n, &m, &d);
    for(int i = 0; i <= n; i++)
        g[i].clear();
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

double solve(int u)
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    double ans = 0.00;
    for(int i = 0; i <= d; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(j == u || g[j].size() == 0)
                continue;
            double rate = 1.00 / g[j].size();
            for(int k = 0; k < g[j].size(); k++)
            {
                int v = g[j][k];
                dp[i + 1][v] += (dp[i][j] * rate);
            }
        }
        ans += dp[i + 1][u];
    }
    return 1.0 - ans;
}

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        init();
        for(int i = 1; i <= n; i++)
            g[0].push_back(i);
        for(int i = 1; i <= n; i++)
            printf("%.10lf\n", solve(i));
    }
    return 0;
}