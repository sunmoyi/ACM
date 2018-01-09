//
// Created by 孙启龙 on 2017/8/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

const long long mod = 1e9 + 7;
using namespace std;

const int N = 1e5 + 10;
vector<int> pr;
int mu[N];
bool Np[N];

inline void init() {
    mu[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!Np[i]) {
            pr.emplace_back(i);
            mu[i] = -1;
        }
        for (int j = 0, k = pr[j] * i; k < N; k = pr[++j] * i) {
            Np[k] = true;
            if (i % pr[j] == 0) {
                mu[k] = 0;
                break;
            }
            mu[k] = -mu[i];
        }
    }

}

int n, ed, mi;
int A[N];

long long qpow(long long x, long long y) {
    if (x <= 1)
        return 1;
    long long res = 1;
    while (y) {
        if (y & 1)
            res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}

long long work() {
    for (int i = 2; i <= ed; i++) {
        A[i] += A[i - 1];
    }
    long long res = 0;
    for (int i = 2; i <= mi; i++)
        if (mu[i]) {
            long long cnt = -mu[i];
            int m = ed / i;
            for (int j = 1; j <= m; j++) {
                int l = i * j, r = min(ed, i * j + i - 1);
                cnt = cnt * qpow(j, A[r] - A[l - 1]) % mod;
            }
            res += cnt;
        }
    return (res % mod + mod) % mod;
}

int main() {
    init();
    int T, cas = 0;
    scanf("%d", &T);
    while (T--) {
        ed = 0;
        mi = 1e5;
        memset(A, 0, sizeof(A));
        scanf("%d", &n);
        for (int i = 0, x; i < n; i++) {
            scanf("%d", &x);
            ed = max(ed, x);
            mi = min(mi, x);
            A[x]++;
        }
        printf("Case #%d: %I64d\n", ++cas, work());
    }
    return 0;
}