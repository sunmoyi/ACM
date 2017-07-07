//
// Created by 孙启龙 on 2016/11/23.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, k;
int num[2010];
long long dp[2010][1010];

int main (void)
{
    while(scanf("%d %d", &n, &k) != EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &num[i]);

        sort(num + 1, num + n + 1);
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 0x3f3f3f3f;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i / 2; j++)
            {
                if(i == j * 2)
                    dp[i][j] = dp[i - 2][j - 1] + (num[i] - num[i - 1]) * (num[i] - num[i - 1]);
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (num[i] - num[i - 1]) * (num[i] - num[i - 1]));
            }
        }
        printf("%lld\n", dp[n][k]);
    }
    return 0;
}