//
// Created by 孙启龙 on 2017/9/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int cnt;
int f[maxn];
int id[maxn], Rank[maxn];
int ls[maxn * 18], rs[maxn *  18], sum[maxn * 18], root[maxn];

int find(int x)
{
    return f[x] == x? x: f[x] = find(f[x]);
}

void pushup(int k)
{
    sum[k] = sum[ls[k]] + sum[rs[k]];
}

void update(int &k, int l, int r, int rk)
{
    if(k == 0)
        k = ++cnt;
    if(l == r)
    {
        sum[k] = 1;
        return;
    }
    int m = (l + r) >> 1;
    if(rk <= m)
        update(ls[k], l, m, rk);
    else
        update(rs[k], m + 1, r, rk);
    pushup(k);
}

int query(int k, int l, int r, int rk)
{
    if(l == r)
        return l;
    int res;
    int m = (l + r) >> 1;
    if(sum[ls[k]] >= rk)
        res = query(ls[k], l, m, rk);
    else
        res = query(rs[k], m + 1, r, rk - sum[ls[k]]);
    return res;
}

int merge(int x, int y)
{
    if(x == 0)
        return y;
    if(y == 0)
        return x;
    ls[x] = merge(ls[x], ls[y]);
    rs[x] = merge(rs[x], rs[y]);

    sum[x] = sum[ls[x]] + sum[rs[x]];
    return x;
}

void init()
{
    cnt = 0;
    memset(sum, 0, sizeof(sum));
    memset(root, 0, sizeof(root));
    memset(ls, 0, sizeof(ls));
    memset(rs, 0, sizeof(rs));
}

int main (void)
{
    int n, m, q;
    while(scanf("%d %d", &n, &m) == 2)
    {
        init();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &Rank[i]);
            id[Rank[i]] = i;
        }
        for(int i = 1; i <= n; i++)
            f[i] = i;
        for(int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            int tx = find(x);
            int ty = find(y);
            if(tx != ty)
                f[tx] = ty;
        }
        for(int i = 1; i <= n; i++)
            update(root[find(i)], 1, n, Rank[i]);

        scanf("%d", &q);
        while(q--) {
            int x, k;
            char op[5];
            scanf("%s%d%d", op, &x, &k);
            if (op[0] == 'B')
            {
                int tx = find(x);
                int ty = find(k);
                if(tx != ty)
                {
                    root[tx] = merge(root[tx], root[ty]);
                    f[ty] = tx;
                }
            }
            else
            {
                int tx = find(x);
                if(sum[root[tx]] < k)
                    printf("-1\n");
                else
                    printf("%d\n", id[query(root[tx], 1, n, k)]);
            }
        }
    }
    return 0;
}