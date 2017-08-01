//
// Created by 孙启龙 on 2017/7/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <iostream>

#define maxn 100010

using namespace std;

int n, m, tot, lenx, leny, mpx[maxn << 2], mpy[maxn << 2];
long long ans, tr[maxn << 2];

struct M{
    int x, y, id, val;
    long long ans;
}q[maxn << 2], node[maxn];

inline bool cmp1(M a, M b)
{
    return a.x < b.x;
}

inline void insert(int x, int y)
{
    for(;x <= leny; x += x & (-x))
        tr[x] += y;
}

inline long long query(int x)
{
    long long res = 0;
    for(;x >= 1; x -= x & (-x))
        res += tr[x];
    return res;
}

inline bool cmp2(M a, M b)
{
    return a.id < b.id;
}

int main (void)
{
    scanf("%d %d", &n, &m);
    lenx = leny = n;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &node[i].x, &node[i].y, &node[i].val);
        mpx[i] = node[i].x, mpy[i] = node[i].y;
    }
    for(int i = 1, x1, x2, y1, y2; i <= m; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        mpx[++lenx] = x1, mpx[++lenx] = x2, mpy[++leny] = y1, mpy[++leny] = y2;
        mpx[++lenx] = x1 - 1, mpy[++leny] = y1 - 1;
        q[++tot].x = x1 - 1, q[tot].y = y1 - 1, q[tot].id = i, q[tot].val = 1;
        q[++tot].x = x1 - 1, q[tot].y = y2, q[tot].id = i, q[tot].val = -1;
        q[++tot].x = x2, q[tot].y = y1 - 1, q[tot].id = i, q[tot].val = -1;
        q[++tot].x = x2, q[tot].y = y2, q[tot].id = i, q[tot].val = 1;
    }
    sort(mpx + 1, mpx + lenx + 1);
    sort(mpy + 1, mpy + leny + 1);
    lenx = unique(mpx + 1, mpx + lenx + 1) - mpx - 1;
    leny = unique(mpy + 1, mpy + leny + 1) - mpy - 1;
    for (int i = 1; i <= n; i++)
    {
        node[i].x = lower_bound(mpx + 1, mpx + lenx + 1, node[i].x) - mpx;
        node[i].y = lower_bound(mpy + 1, mpy + leny + 1, node[i].y) - mpy;
    }

    for (int i = 1; i <= tot; i++)
    {
        q[i].x = lower_bound(mpx + 1, mpx + lenx + 1, q[i].x) - mpx;
        q[i].y = lower_bound(mpy + 1, mpy + leny + 1, q[i].y) - mpy;
    }

    sort(q + 1, q + tot + 1, cmp1);
    sort(node + 1, node + n + 1, cmp1);
    for (int i = 1, j = 1; i <= tot; i++) {
        for (; j <= n && node[j].x <= q[i].x; j++)
            insert(node[j].y, node[j].val);
        q[i].ans = query(q[i].y);
    }

    sort(q + 1, q + tot + 1, cmp2);
    tot = 0;
    for (int i = 1; i <= m; i++) {
        ans = 0;
        tot++;
        ans += q[tot].val * q[tot].ans;
        tot++;
        ans += q[tot].val * q[tot].ans;
        tot++;
        ans += q[tot].val * q[tot].ans;
        tot++;
        ans += q[tot].val * q[tot].ans;
        printf("%lld\n", ans);
    }
    return 0;
}