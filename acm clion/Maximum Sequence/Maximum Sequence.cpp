//
// Created by 孙启龙 on 2017/7/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500010
#define mod 1000000007

using namespace std;

struct node{
    int l, r, maxx;
    long long sum;
}tree[maxn * 4];
int n;
int a[maxn], b[maxn];

void pushup(int root)
{
    tree[root].sum = (tree[root << 1].sum + tree[root << 1 | 1].sum) % mod;
    tree[root].maxx = max(tree[root << 1].maxx, tree[root << 1 | 1].maxx);
}

void build(int l, int r, int root) {
    tree[root].l = l;
    tree[root].r = r;
    if (tree[root].l == tree[root].r)
    {
        if(l > n)
            tree[root].sum = 0, tree[root].maxx = 0;
        else
            tree[root].sum = a[l], tree[root].maxx = a[l] - l;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1 | 1);
    pushup(root);
}

void update(long long v, int x, int root)
{
    if(tree[root].l == tree[root].r)
    {
        tree[root].sum = v;
        tree[root].maxx = v - x;
        return;
    }
    int mid = (tree[root].l + tree[root].r) >> 1;
    if(x <= mid)
        update(v, x, root << 1);
    else
        update(v, x, root << 1 | 1);
    pushup(root);
}

int query(int l, int r, int root)
{
    if(tree[root].l == l && tree[root].r == r)
        return tree[root].maxx;
    int mid = (tree[root].l + tree[root].r) >> 1;
    if(r <= mid)
        return query(l, r, root << 1);
    else if (l > mid)
        return query(l, r, root << 1 | 1);
    else
        return max(query(l, mid, root << 1), query(mid + 1, r, root << 1 | 1));
}

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        int pre = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int j = 0; j < n; j++)
            scanf("%d", &b[j]);
        build(1, 2 * n, 1);
        sort(b, b + n);
        for(int i = n + 1; i <= 2 * n; i++)
        {
            int x, y;
            int bg, ed = i - 1;
            x = bg = b[pre++];
            y = query(bg, ed, 1);
            a[i] = max(x, y);
            update(a[i], i, 1);
        }
        printf("%lld\n", tree[3].sum);
    }
    return 0;
}