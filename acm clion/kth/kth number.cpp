//
// Created by 孙启龙 on 2017/8/14.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<cstring>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>

#define ll long long
#define LL unsigned long long
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 0.0000000001;
const int N = 100000 + 10;
struct node {
    int left, right;
    int val;
} tree[N * 40];
int cnt;
int a[N], b[N];
int root[N];

int build(int l, int r) {
    int pos = ++cnt;
    tree[pos].val = 0;
    if (l == r)
        return pos;
    int mid = (l + r) >> 1;
    tree[pos].left = build(l, mid);
    tree[pos].right = build(mid + 1, r);
    return pos;
}

void update(int pre, int &now, int x, int l, int r)
{
    tree[++cnt] = tree[pre];
    now = cnt;
    tree[now].val++;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (x <= mid) {
        update(tree[pre].left, tree[now].left, x, l, mid);
    } else {
        update(tree[pre].right, tree[now].right, x, mid + 1, r);
    }

}

int query(int L, int R, int k, int l, int r) {
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int sum = tree[tree[R].left].val - tree[tree[L].left].val;
    if (k <= sum) {
        return query(tree[L].left, tree[R].left, k, l, mid);
    } else {
        return query(tree[L].right, tree[R].right, k - sum, mid + 1, r);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(root, 0, sizeof(root));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int n, m;
        scanf("%d%d", &n, &m);
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        int tt = unique(b + 1, b + 1 + n) - b - 1;
        root[0] = build(1, tt);
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(b + 1, b + 1 + tt, a[i]) - b;//二分找到a[i]的位置
            update(root[i - 1], root[i], a[i], 1, tt);//root[i-1]表示上一个版本的线段树
        }
        for (int i = 1; i <= m; i++) {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            int ans = query(root[l - 1], root[r], k, 1, tt);
            printf("%d\n", b[ans]);
        }
    }
    return 0;
}
