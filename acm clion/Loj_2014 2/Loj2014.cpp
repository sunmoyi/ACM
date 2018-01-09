//
// Created by 孙启龙 on 2017/8/8.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 100011
#define MOD 1000000007

using namespace std;

int n, m, belong[MAXN], f[18][MAXN], scnt, cnt[MAXN], Log;
long long ans;

inline int find(int f[], int x) {
    if (f[x] != x)
        f[x] = find(f, f[x]);
    return f[x];
}

inline void Union(int f[], int x, int y) {
    int r1 = find(f, x), r2 = find(f, y);
    if (r1 != r2)
        f[r1] = r2;
}

inline void work() {
    scanf("%d %d", &n, &m);
    int l1, r1, l2, r2, t = 1, len;
    for (int i = 2; i <= n; i++)
        belong[i] = belong[i >> 1] + 1;
    Log = belong[n];
    for (int j = 0; j <= Log; j++, t <<= 1)
        for (int i = 1; i + t <= n; i++)
            f[j][i] = i;

    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        len = r1 - l1 + 1;
        t = (1 << belong[len]);
        Union(f[belong[len]], l1, l2);
        Union(f[belong[len]], r1 - t + 1, r2 - t + 1);
    }

    for (int j = Log, t = (1 << Log); j >= 1; j--, t >>= 1)
        for (int i = 1; i + t <= n; i++)
            if (find(f[j], i) != i) {
                Union(f[j - 1], i, find(f[j], i));
                Union(f[j - 1], i + (1 << (j - 1)), find(f[j], i) + (1 << (j - 1)));
            }
    for (int i = 1; i <= n; i++) {
        t = find(f[0], i);
        if (cnt[t] == 0)
            scnt++;
        cnt[t]++;
    }
    ans = 9;
    for (int i = 1; i < scnt; i++)
        ans *= 10, ans %= MOD;
    printf("%lld", ans);
}

int main() {
    work();
    return 0;
}