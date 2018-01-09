//
// Created by 孙启龙 on 2017/8/31.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;
const LL MOD = 998244353;
const int N = 2e3 + 5;

int b[N], a[N];
LL sum[N][2], dp[N][2];

int main() {
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]);
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            LL cnt1 = 1, cnt0 = 0;
            for (int j = 1; j <= m; j++) {
                dp[j][0] = dp[j][1] = 0;
                if (a[i] == b[j]) {
                    dp[j][0] = cnt1;
                    dp[j][1] = cnt0;
                    ans = (ans + cnt1 + cnt0) % MOD;
                } else if (b[j] < a[i])
                    (cnt0 += sum[j][0]) %= MOD;
                else
                    (cnt1 += sum[j][1]) %= MOD;
            }
            for (int j = 1; j <= m; j++) {
                if (b[j] == a[i]) {
                    (sum[j][0] += dp[j][0]) %= MOD;
                    (sum[j][1] += dp[j][1]) %= MOD;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}