//
// Created by 孙启龙 on 2017/8/31.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxn 1100000
#define mod 998244353ll

using namespace std;

int T, n, prime[maxn], primesize;
bool isprime[maxn];
long long l, r, k;

void getlist(int listsize) {
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i <= listsize; i++) {
        if (isprime[i])
            prime[++primesize] = i;
        for (int j = 1; j <= primesize && i * prime[j] <= listsize; j++) {
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

long long num[maxn], ans[maxn];

void solve() {
    long long n = r - l + 1;
    for (int i = 0; i < n; i++) {
        num[i] = i + l;
        ans[i] = 1;
    }
    for (int i = 1; (long long) prime[i] * prime[i] <= r; i++) {
        for (long long j = prime[i] * (l / prime[i]); j <= r; j += prime[i]) {
            if (j < l)
                continue;
            long long cnt = 0;
            while (num[j - l] % prime[i] == 0) {
                cnt++;
                num[j - l] /= prime[i];
            }
            ans[j - l] = (ans[j - l] * (1ll + cnt * k)) % mod;
        }
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (num[i] > 1) {
            ans[i] = (ans[i] * (1ll + k)) % mod;
        }
        res = (res + ans[i]) % mod;
    }
    printf("%lld\n", res);
}

int main(int agrc, char *agrv[]) {
    getlist(1000005);
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld %lld", &l, &r, &k);
        solve();
    }
    return 0;
}