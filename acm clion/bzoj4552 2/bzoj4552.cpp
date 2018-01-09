//
// Created by 孙启龙 on 2017/8/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int n, m;
int total, pos;
int num[maxn], map[maxn];

struct Update{
    int k, l, r;
}upda[maxn];

struct Node{
    int sum, tag;
}tree[maxn << 2];

void change(int root, int l, int r, int L, int R, int k);
inline void pushup(int root)
{
    tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
}

inline void pushdown(int root, int l, int r, int mid)
{
    if (tree[root].tag != -1)
    {
        tree[root << 1].tag = tree[root << 1 | 1].tag = tree[root].tag;
        tree[root << 1].sum = tree[root].tag * (mid - l + 1);
        tree[root << 1 | 1].sum = tree[root].tag * (r - mid);
        tree[root].tag = -1;
    }
}

void build(int root, int l, int r, int k)
{
    tree[root].tag = -1;

    if(l == r)
    {
        tree[root].sum = num[l] > k;
        return ;
    }

    int mid = (l + r) >> 1;
    build(root << 1, l, mid, k);
    build(root << 1 | 1, mid + 1, r, k);
    pushup(root);
}

void change(int root, int l, int r, int L, int R, int k)
{
    if (l > r)
        return;

    if (l == L && r == R)
    {
        tree[root].sum = (r - l + 1) * k, tree[root].tag = k;
        return ;
    }

    int mid = (L + R) >> 1;

    pushdown(root, L, R, mid);

    if (r <= mid)
        change(root << 1, l, r, L, mid, k);
    else if (l > mid)
        change(root << 1 | 1, l, r, mid + 1, R, k);
    else
        change(root << 1, l, mid, L, mid, k), change(root << 1 | 1, mid + 1, r, mid + 1, R, k);

    pushup(root);
}

int query(int root, int l, int r, int L, int R)
{
    if(L == l && R == r)
        return tree[root].sum;

    int mid = (L + R) >> 1;

    pushdown(root, L, R, mid);

    if(r <= mid)
        return query(root << 1, l, r, L, mid);
    else if (l > mid)
        return query(root << 1 | 1, l, r, mid + 1, R);
    else
        return query(root << 1, l, mid, L, mid) + query(root << 1 | 1, mid + 1, r, mid + 1, R);
}

int check(int mid)
{
    build(1, 1, n, mid);

    for(int i = 1; i <= m; i++)
    {

        int q = query(1, upda[i].l, upda[i].r, 1, n);

        if(upda[i].k)
        {
            change(1, upda[i].l, upda[i].l + q - 1, 1, n,1);
            change(1, upda[i].l + q, upda[i].r, 1, n, 0);
        }
        else
        {
            change(1, upda[i].l, upda[i].r - q, 1, n, 0);
            change(1, upda[i].r - q + 1, upda[i].r, 1, n, 1);
        }
    }
    return query(1, pos, pos, 1, n);
}

int main (void)
{
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &num[i]), map[i] = num[i];
    for(int i = 1; i <= m; i++)
        scanf("%d %d %d", &upda[i].k, &upda[i].l, &upda[i].r);

    scanf("%d", &pos);
    sort(map + 1, map + n + 1);
    total = (int)(unique(map + 1, map + n + 1) - map);

    int l = 1, r = total, mid, ans = total;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(check(mid))
            l = mid + 1;
        else
            r = mid - 1, ans = mid;
    }
    printf("%d\n", ans);
    return 0;
}