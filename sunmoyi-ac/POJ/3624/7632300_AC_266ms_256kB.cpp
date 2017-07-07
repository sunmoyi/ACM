//
// Created by 孙启龙 on 2016/11/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int w[10000], p[10000], dp[200000];
int n, m;

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &w[i], &p[i]);
        memset(dp, 0, sizeof(0));
        for(int i = 1; i <= n; i++)
        {
            for(int j = m; j >= w[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}