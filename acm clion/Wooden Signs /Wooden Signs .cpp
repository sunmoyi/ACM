//
// Created by 孙启龙 on 2017/8/10.
//

#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int a[2010];
long long dp[2010][2010];
#define mod 2147483647

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i <= n; i++)
            scanf("%lld", &a[i]);
        memset(dp, 0, sizeof(dp));
        dp[1][a[0]] = 1;

        int left, right;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= n + 1; j++) {
                left = min(j, a[i - 1]);
                right = max(j, a[i - 1]);

                if (a[i] > left)
                    dp[i][left] = (dp[i][left] + dp[i - 1][j]) % mod;
                if (a[i] < right)
                    dp[i][right] = (dp[i][right] + dp[i - 1][j]) % mod;
            }
        }

        long long ans = 0;
        for (int i = 1; i <= n + 1; i++)
            ans = (ans + dp[n][i]) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}