//
// Created by 孙启龙 on 2017/7/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxn 100010

using namespace std;

struct node {
    int l, r, val;
} tree[maxn];
int tot = 1;
int T, a[maxn], b[maxn], q, x, n;

void init(int tot) {
    tree[tot].l = tree[tot].r = 0;
}

void insert(int x, int val) {
    if (tree[x].l && val < tree[x].val)
        insert(tree[x].l, val);
    else if (tree[x].r && val > tree[x].val)
        insert(tree[x].r, val);
    else {
        init(tot);
        tree[tot].val = val;
        if (tree[x].val > val)
            tree[x].l = tot;
        else
            tree[x].r = tot;
        tot++;
    }
}

void query(int x, int val) {
    if (val == tree[x].val) {
        printf("\n");
        return;
    }
    if (tree[x].val > val) {
        printf("E");
        query(tree[x].l, val);
    } else {
        printf("W");
        query(tree[x].r, val);
    }
}

int main(void) {
    scanf("%d", &T);
    while (T--) {
        tot = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (i == 1) {
                init(tot);
                tree[tot].val = a[i];
                tot++;
            } else
                insert(1, a[i]);
        }
        scanf("%d", &q);
        while (q--) {
            scanf("%d", &x);
            query(1, x);
        }
    }
    return 0;
}