//
// Created by 孙启龙 on 2017/8/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <map>

#define maxn 100010

using namespace std;

int n, m, a[maxn], b[maxn];
map<int, int>mat;

struct Tree{
    int ls, rs, sum;
}tree[maxn  * 20];

int rt[maxn], tot;

int build(int l, int r)
{
    int root = tot++;
    tree[root].sum = 0;
    if(l == r)
        return root;

    int mid = (l + r) >> 1;
    tree[root].ls = build(l, mid);
    tree[root].rs = build(mid + 1, r);
    return root;
}

int update(int x, int l, int r, int lt)
{
    int root = tot++;
    tree[root] = tree[lt];
    tree[root].sum++;
    if(l == r)
        return root;

    int mid = (l + r) >> 1;
    if(x <= mid)
        tree[root].ls = update(x, l, mid, tree[lt].ls);
    else
        tree[root].rs = update(x, mid + 1, r, tree[lt].rs);

    return root;
}

int query(int i, int j, int x, int l, int r)
{
    if(l == r)
        return tree[i].sum - tree[j].sum;
    int mid = (l + r) >> 1, ret = 0;
    if(x <= mid)
        ret += query(tree[i].ls, tree[j].ls, x, l, mid);
    else
    {
        ret += tree[tree[i].ls].sum - tree[tree[j].ls].sum;
        ret += query(tree[i].rs, tree[j].rs, x, mid + 1, r);
    }
    return ret;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case  = 1; Case <= T; Case++)
    {
        printf("Case %d:\n", Case);
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]), b[i] = a[i];
        sort(b + 1, b + n + 1);

        int sz = unique(b + 1, b + n + 1) - b - 1;
        for(int i = 1; i <= sz; i++)
            mat[b[i]] = i;
        tot = 0;
        rt[0] = build(1, sz);
        for(int i = 1; i <= n; i++)
            rt[i] = update(mat[a[i]], 1, sz, rt[i - 1]);
        for(int i = 1; i <= m; i++)
        {
            int l, r, h;
            scanf("%d %d %d", &l, &r, &h);
            r++, l++;
            int k = upper_bound(b + 1, b + sz + 1, h) - b - 1;
            if(k)
                printf("%d\n", query(rt[r], rt[l - 1], k, 1, sz));
            else
                printf("0\n");
        }
    }
    return 0;
}