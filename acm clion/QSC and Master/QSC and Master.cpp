//
// Created by 孙启龙 on 2017/7/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 310
using namespace std;

long long key[maxn], value[maxn], sum[maxn];
long long dp[maxn][maxn];

long long gcd(long long a, long long b)
{
    return b == 0? (a):(gcd(b, a % b));
}

int main (void)
{
    int Case;
    scanf("%d", &Case);
    while(Case--)
    {
        int n;
        scanf("%d", &n);
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; i++)
            scanf("%lld", &key[i]);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &value[i]);
            sum[i] = sum[i - 1] + value[i];
        }

        memset(dp, 0, sizeof(dp));
        for(int len = 2; len <= n; len++)
        {
            for(int i = 1; i + len - 1 <= n; i++)
            {
                int r = i + len - 1;
                if(sum[r - 1] - sum[i] == dp[i + 1][r - 1] && gcd(key[r], key[i]) > 1)
                    dp[i][r] = dp[i + 1][r - 1] + value[i] + value[r];
                for(int k = i; k < r; k++)
                    dp[i][r] = max(dp[i][r], dp[i][k] + dp[k + 1][r]);
            }
        }
        printf("%lld\n", dp[1][n]);
    }
    return 0;
}