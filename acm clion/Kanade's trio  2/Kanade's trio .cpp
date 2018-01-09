//
// Created by 孙启龙 on 2017/8/30.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

const int M = 5e5 + 55;
const int N = 33;
const int infn = 30;

struct Node {
    int nxt[2], gcnt;
    ll ng;
} tree[M * N];

int n, tnum;
ll ans;
int s[N], tol[N][2];

void insert() {
    int rt = 0, i, j, chil, xchil;
    for (i = infn - 1; i >= 0; i--) {
        if (tree[rt].nxt[s[i]] == 0)
            tree[rt].nxt[s[i]] = ++tnum;
        chil = tree[rt].nxt[s[i]];    //children for s[i]
        xchil = tree[rt].nxt[1 - s[i]]; //another children
        if (xchil)
            ans += 1ll * (tree[xchil].gcnt - 1) * tree[xchil].gcnt / 2 +
                   1ll * tree[xchil].gcnt * (tol[i][1 - s[i]] - tree[xchil].gcnt) - tree[xchil].ng;
        tree[chil].ng += tol[i][s[i]] - tree[chil].gcnt;
        tree[chil].gcnt++;
        tol[i][s[i]]++;
        rt = chil;
    }
}

void init() {
    memset(tree, 0, (n + 4) * N * sizeof(Node));
    memset(tol, 0, sizeof(tol));
    tnum = 0;
    ans = 0;
}

void solve() {
    int i, j, now;
    for (i = 1; i <= n; i++) {
        scanf("%d", &now);
        for (j = 0; j < infn; j++) {
            s[j] = now & 1;
            now >>= 1;
        }
        insert();
    }
}

int main() {
    int T, now;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init();
        solve();
        printf("%lld\n", ans);
    }
    return 0;
}