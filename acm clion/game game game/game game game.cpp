//
// Created by 孙启龙 on 2017/9/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <cmath>

#define mod 255

using namespace std;

int T;
int dp[2][300][300];
int n;
int s[21001], pre[21001];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &s[i]);
            pre[i] = pre[i - 1] + s[i];
        }
        int size = sqrt(n * 2) + 1;
        for (int i = n; i >= 1; i--) {
            for (int j = size; j >= 1; j--) {
                if (i + j <= n) {
                    dp[0][i & mod][j] = pre[(i + j - 1)] - pre[i - 1] +
                                        max(dp[1][(i + j) & mod][j], dp[1][(i + j + 1) & mod][j + 1] + s[i + j]);
                    dp[1][i & mod][j] = -pre[i + j - 1] + pre[i - 1] +
                                        min(dp[0][(i + j) & mod][j], dp[0][(i + j + 1) & mod][j + 1] - s[i + j]);
                } else if (i + j == n + 1) {
                    dp[0][i & mod][j] = pre[i + j - 1] - pre[i - 1];
                    dp[1][i & mod][j] = pre[i - 1] - pre[i + j - 1];
                }
            }
        }
        printf("%d\n", dp[0][1][1]);
    }


}