//
// Created by 孙启龙 on 2017/10/31.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define mod 1000000007

using namespace std;

struct node{
    int l, r, lc, rc, d;
    long long L[2], R[2], s[2];
}t[32][2 * maxn];
char c[32];
int n, m, tl, a[maxn][10];
long long bit[15];

node pushup(int ind, int temp, node lc, node rc) {
    int dl = lc.d, dr = rc.d;
    node x;
    if (temp != 0)
        x = t[ind][temp];
    x.d = lc.d ^ rc.d;
    x.L[0] = (lc.L[0] + rc.L[(dl == 0) ? 0 : 1]) % mod;
    x.L[1] = (lc.L[1] + rc.L[(dl == 0) ? 1 : 0]) % mod;
    x.R[0] = (rc.R[0] + lc.R[(dr == 0) ? 0 : 1]) % mod;
    x.R[1] = (rc.R[1] + lc.R[(dr == 0) ? 1 : 0]) % mod;
    x.s[0] = (lc.s[0] + rc.s[0] + (lc.R[0] * rc.L[0]) % mod + (lc.R[1] * rc.L[1]) % mod) % mod;
    x.s[1] = (lc.s[1] + rc.s[1] + (lc.R[0] * rc.L[1]) % mod + (lc.R[1] * rc.L[0]) % mod) % mod;
    return x;
}

int build(int ind, int l, int r)
{
    int x = ++tl;
    memset(&t[ind][x], 0, sizeof(node));
    t[ind][x].l = l, t[ind][x].r = r;
    if(l < r)
    {
        int mid = (l + r) >> 1;
        t[ind][x].lc = build(ind, l, mid);
        t[ind][x].rc = build(ind, mid + 1, r);
        int lc = t[ind][x].lc, rc = t[ind][x].rc;
        t[ind][x] = pushup(ind, x, t[ind][lc], t[ind][rc]);
    }
    else
    {
        int d = a[l][ind];
        t[ind][x].d = d;
        t[ind][x].L[d] = t[ind][x].R[d] = t[ind][x].s[d] = 1;
    }
    return x;
}

void update(int ind, int root, int p, int d)
{
    if(t[ind][root].l == t[ind][root].r)
    {
        t[ind][root].d = d;
        t[ind][root].L[d] = t[ind][root].R[d] = t[ind][root].s[d] = 1;
        t[ind][root].L[d ^ 1] = t[ind][root].R[d ^ 1] = t[ind][root].s[d ^ 1] = 0;
        return;
    }
    int lc = t[ind][root].lc, rc = t[ind][root].rc, mid = (t[ind][root].l + t[ind][root].r) >> 1;
    if(p <= mid)
        update(ind, lc, p, d);
    else if (p > mid)
        update(ind, rc, p, d);
    t[ind][root] = pushup(ind, root, t[ind][lc], t[ind][rc]);
}

node query(int ind, int x, int l, int r)
{
    if(t[ind][x].l == l && t[ind][x].r == r)
        return t[ind][x];
    int lc = t[ind][x].lc, rc = t[ind][x].rc, mid = (t[ind][x].l + t[ind][x].r) >> 1;
    if(r <= mid)
        return query(ind, lc, l, r);
    else if (l > mid)
        return query(ind, rc, l, r);
    else
    {
        node ans0 = query(ind, lc, l, mid);
        node ans1 = query(ind, rc, mid + 1, r);
        return pushup(0, 0, ans0, ans1);
    }
}

int main (void)
{
    int x, ind;
    node now;
    scanf("%d", &n);
    bit[0] = 1;
    for(int i = 1; i <= 30; i++)
        bit[i] = bit[i - 1] << 1;
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        ind = 0;
        while(x)
        {
            a[i][ind] = x % 2;
            x >>= 1;
            ind++;
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < 31; i++)
    {
        tl = 0;
        build(i, 1, n);
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%s", c);
        if(c[0] == 'Q')
        {
            int l, r;
            long long ans = 0;
            scanf("%d %d", &l, &r);
            for(int j = 0; i < 31; i++)
            {
                now = query(j, 1, l, r);
                ans = (ans + (bit[j] * now.s[1]) % mod) % mod;
            }
            printf("%lld\n", ans);
        }
        else
        {
            int ind = 0, p, d;
            scanf("%d %d", &p, &d);
            while(d)
            {
                update(ind, 1, p, d % 2);
                d /= 2;
                ind++;
            }
            for(int j = ind; j < 31; i++)
                update(j, 1, p, 0);
        }
    }
    return 0;
}