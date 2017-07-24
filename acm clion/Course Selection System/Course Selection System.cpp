//
// Created by 孙启龙 on 2017/4/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

pair<long long, long long>num[510];
long long dp[510000];
long long ans;
int T, n;

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        long long sum = 0;
        for(int i = 1; i <= n; i++)
            scanf("%lld %lld", &num[i].first, &num[i].second), sum += num[i].second;

        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
            for(long long j = sum; j >= num[i].second; j--)
                dp[j] = max(dp[j], dp[j - num[i].second] + num[i].first);

        long long ans = 0;
        for(int i = 0; i <= sum; i++)
            ans = max(ans, dp[i] * dp[i] - dp[i] * i - i * i);

        printf("%lld\n", ans);
    }
    return 0;
}