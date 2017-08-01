//
// Created by 孙启龙 on 2017/7/29.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100010
#define ll unsigned long long

using namespace std;

ll n, m;
ll a[MAXN], b[MAXN];
ll now;
ll A, B, C;
ll ans = 1e18;
ll c[MAXN];

ll OK(ll x) {
    ll i;
    ll re = 0;
    for (i = 1; i <= n; i++) {
        if (a[i] < x) {
            re += (x - a[i]) * C;
        }
    }

    if (A < B) {
        ll rem = 0;
        for (i = 1; i <= m; i++) {
            if (b[i] < x) {
                rem += x - b[i];
            }
        }
        for (i = 1; i <= m; i++) {
            if (b[i] > x) {
                ll t = min(rem, b[i] - x);
                re += A * t;
                re += B * (b[i] - x - t);
                rem -= t;
            }
        }
    }
    else
    {
        for (i = 1; i <= m; i++) {
            if (b[i] > x) {
                re += (b[i] - x) * B;
            }
        }
    }
    return re;
}

int main() {
    ll i;
    scanf("%llu%llu%llu%llu%llu", &A, &B, &C, &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%llu", &a[i]);
    }
    for (i = 1; i <= m; i++) {
        scanf("%llu", &b[i]);
        now = max(now, b[i]);
    }
    ll l = 1, r = now;
    //*
    while (r - l + 1 >= 4)
    {
        ll l1 = l + (r - l + 1) / 3, l2 = l + 2 * (r - l + 1) / 3;
        ll t1 = OK(l1), t2 = OK(l2);
        if (t1 <= t2) {
            r = l2;
        } else {
            l = l1;
        }
    }

    for (i = l; i <= r; i++) {
        ans = min(ans, OK(i));
    }
    printf("%llu\n", ans);
    return 0;
}