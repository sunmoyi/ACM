//
// Created by 孙启龙 on 2017/8/9.
//

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;
#define N 100005

int n, m, l, r, LSH, sz, ans;
int a[N], lsh[N], root[N], sum[N * 20], ls[N * 20], rs[N * 20];

void insert(int &now, int l, int r, int x, int val) {
    int mid = (l + r) >> 1;
    sum[++sz] = sum[now] + val;
    ls[sz] = ls[now];
    rs[sz] = rs[now];
    now = sz;
    if (l == r)
        return;
    if (x <= mid)
        insert(ls[now], l, mid, x, val);
    else
        insert(rs[now], mid + 1, r, x, val);
}

int query(int L, int R, int l, int r, int lr, int rr) {
    int mid = (l + r) >> 1;
    int ans = 0;
    if (lr <= l && r <= rr)
        return sum[R] - sum[L];
    if (lr <= mid)
        ans += query(ls[L], ls[R], l, mid, lr, rr);
    if (mid + 1 <= rr)
        ans += query(rs[L], rs[R], mid + 1, r, lr, rr);
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), lsh[++LSH] = a[i];
    sort(lsh + 1, lsh + LSH + 1);
    LSH = unique(lsh + 1, lsh + LSH + 1) - lsh - 1;
    for (int i = 1; i <= n; ++i) {
        int t = lower_bound(lsh + 1, lsh + LSH + 1, a[i]) - lsh;
        root[i] = root[i - 1];
        insert(root[i], 1, LSH, t, a[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &l, &r);
        ans = 1;
        while (1) {
            int t = upper_bound(lsh + 1, lsh + LSH + 1, ans) - lsh - 1;
            int sum = query(root[l - 1], root[r], 1, LSH, 1, t);
            if (sum >= ans)
                ans = sum + 1;
            else
                break;
        }
        printf("%d\n", ans);
    }
}