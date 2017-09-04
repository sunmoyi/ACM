//
// Created by 孙启龙 on 2017/8/5.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2005;
const int mod = 1e9 + 7;

int N, M, T[maxn], dp[maxn];

int solve(int n) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int s = n; s > 0; s--) {
            for (int j = 1; j <= T[i] && j <= s; j++)
                dp[s] = (dp[s] + dp[s - j]) % mod;
        }
    }
    return dp[n];
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        M = 0;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &T[i]);
            M += T[i];
        }
        printf("%d\n", solve(M / 2));
    }
    return 0;
}
