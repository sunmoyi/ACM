//
// Created by 孙启龙 on 2017/8/28.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define rep(i, m, n) for(i=m;i<=(int)n;i++)

const int maxn = 2e5 + 10;

using namespace std;

int n, m, k, t, a[maxn], d[maxn], b[maxn], cnt, c[maxn];

void add(int x, int y) {
    while (x <= cnt)
        d[x] = max(d[x], y), x += x & (-x);
}

int get(int x) {
    int ret = 0;
    while (x)
        ret = max(ret, d[x]), x -= x & (-x);
    return ret;
}

int main() {
    int i, j;
    scanf("%d%d", &n, &m);
    b[++cnt] = m;
    rep(i, 1, n)
        scanf("%d", &a[i]), b[++cnt] = a[i], b[++cnt] = 2 * a[i];
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    m = lower_bound(b + 1, b + cnt + 1, m) - b;
    rep(i, 1, n)
        c[i] = lower_bound(b + 1, b + cnt + 1, 2 * a[i]) - b, a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    int ret = 0;
    rep(i, 1, n) {
        int ok1, ok2;
        if (a[i] >= m)
            ok1 = get(a[i]);
            ret = max(ret, ok1 + 1);
        if (c[i] >= m)
            ok2 = get(c[i]);
            ret = max(ret, ok2 + 1);
        if (a[i] >= m)
            add(a[i], ok1 + 1);
        if (c[i] >= m)
            add(c[i], ok2 + 1);
    }
    printf("%d\n", ret);
    return 0;
}