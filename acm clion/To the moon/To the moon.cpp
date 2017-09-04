//
// Created by 孙启龙 on 2017/8/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int tree[maxn], tot;
int ls[maxn * 30], rs[maxn * 30], add[maxn * 30];
long long sum[maxn * 30];

int n, m;

int buildtree(int l, int r)
{
    int k = tot++;
    add[k] = 0;
    if(l == r)
    {
        scanf("%lld", &sum[k]);
        return k;
    }

    int mid = (l + r) >> 1;
    ls[k] = buildtree(l, mid);
    rs[k] = buildtree(mid + 1, r);

    sum[k] = sum[ls[k]] + sum[rs[k]];
    return k;
}

int update(int root, int L, int R, int x, int l, int r)
{
    int k = tot++;
    ls[k] = ls[root], rs[k] = rs[root], add[k] = add[root], sum[k] = sum[root];
    sum[k] += (long long)x * (R - L + 1);

    if(L == l && R == r)
    {
        add[k] += x;
        return k;
    }

    int mid = (l + r) >> 1;
    if(R <= mid)
        ls[k] = update(ls[k], L, R, x, l, mid);
    else if (L > mid)
        rs[k] = update(rs[k], L, R, x, mid + 1, r);
    else
    {
        ls[k] = update(ls[k], L, mid, x, l, mid);
        rs[k] = update(rs[k], mid + 1, R, x, mid + 1, r);
    }
    return k;
}

long long query(int root, int L, int R, int l, int r)
{
    if(L == l && R == r)
        return sum[root];

    int mid = (l + r) >> 1;
    long long ret = (long long)add[root] * (R - L + 1);

    if(R <= mid)
        return ret + query(ls[root], L, R, l, mid);
    else if (L > mid)
        return ret + query(rs[root], L, R, mid + 1, r);
    else
        return ret + query(ls[root], L, mid, l, mid) + query(rs[root], mid + 1, R, mid + 1, r);
}

int main(void)
{
    int x, l, r;
    int now;
    char ch[3];
    bool flag = false;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        if(flag)
            printf("\n");
        flag = true;

        tot = 0;
        tree[0] = buildtree(1, n);
        now = 0;
        while(m--)
        {
            scanf("%s", ch);
            if(ch[0] == 'C')
            {
                scanf("%d %d %d", &l, &r, &x);
                now++;
                tree[now] = update(tree[now - 1], l, r, x, 1, n);
            }
            else if (ch[0] == 'Q')
            {
                scanf("%d %d", &l, &r);
                printf("%lld\n", query(tree[now], l, r, 1, n));
            }
            else if (ch[0] == 'H')
            {
                scanf("%d %d %d", &l ,&r, &x);
                printf("%lld\n", query(tree[x], l, r, 1, n));
            }
            else if (ch[0] == 'B')
            {
                scanf("%d", &now);
            }
        }
    }
    return 0;
}