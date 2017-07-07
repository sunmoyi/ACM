//
// Created by 孙启龙 on 2017/4/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int dp[maxn];
int sum[maxn];
int v[105], c[105];

int main (void)
{
    int n, m;
    while(scanf("%d %d", &n, &m), n + m)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &v[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            memset(sum , 0, sizeof(sum));
            for(int j = v[i]; j <= m; j++)
            {
                if(!dp[j] && dp[j - v[i]] && sum[j - v[i]] < c[i])
                {
                    dp[j] = 1;
                    sum[j] = sum[j - v[i]] + 1;
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}