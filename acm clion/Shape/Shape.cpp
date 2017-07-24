//
// Created by 孙启龙 on 2017/7/21.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2 * 1e4;

int fac[maxn + 5], inv[maxn + 5];

int pow_mod(ll x, int n) {
    ll ret = 1;
    while (n) {
        if (n&1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

int C(int k, int n) {
    if (k > n) return 0;
    k = min(k, n-k);
    int ret = 1;
    for (int i = 0; i < k; i++)
        ret = 1LL * ret * (n-i) % mod * inv[(i+1)] % mod;
    return ret;
}

int main () {

    inv[0] = 1;
    for (int i = 1; i <= maxn; i++) inv[i] = pow_mod(i, mod-2);

    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        int b, q, a, d, n, m, ans = 0;
        scanf("%d%d%d%d%d%d", &b, &q, &a, &d, &n, &m);
        a %= mod, b %= mod, d %= mod, q %= mod;

        int cnt = C(n-1, n+m-2);
        int bw = 0, b1 = b, del = 0, invq = pow_mod(q-1, mod-2);

        for (int i = 1; i <= n; i++) {
            // 等差
            ans = (ans + 1LL * cnt * a % mod) % mod;
            a = (a + d) % mod;

            // 等比
            bw = 1LL * b1 * invq % mod;
            b1 = (b1 + bw) % mod;
            ans = (ans - 1LL * cnt * bw % mod + mod) % mod;

            // 组合数
            cnt = 1LL * cnt * (n-i) % mod * pow_mod(n+m-1-i, mod-2) % mod;
        }
        ans = (ans + 1LL * b1 * pow_mod(q, m-1) % mod) % mod;

        printf("Case #%d: %d\n", kcas, ans);
    }
    return 0;
}