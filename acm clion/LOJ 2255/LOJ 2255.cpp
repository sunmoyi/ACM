//
// Created by 孙启龙 on 2017/7/31.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500010
#define mod 1000000007

using namespace std;

struct p {
    int n;
    long long pos, ra;
    p(long long pos = 0, long long ra = 0) : pos(pos), ra(ra) {}
}pp[maxn];
long long pos[maxn], lpos[maxn], rpos[maxn];
int now;

bool cmppos(p A, p B){
    return A.pos < B.pos;
}

struct node{
    long long l, r;
    node(long long l = 0, long long r = 0): l(l), r(r) {}
};
node T[maxn << 2];

void pushup(int root)
{
    T[root].l = min(T[root << 1].l, T[root << 1 | 1].l);
    T[root].r = max(T[root << 1].r, T[root << 1 | 1].r);
}

void maxx(node &x, node y)
{
    if(x.l > y.l)
        x.l = y.l;
    if(x.r < y.r)
        x.r = y.r;
}

void update(int x, node y, int l, int r, int root)
{
    if(x == l && x == r)
    {
        T[root] = y;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid)
        update(x, y, l, mid, root << 1);
    else
        update(x, y, mid + 1, r, root << 1 | 1);
    pushup(root);
}

void build(int l, int r, int root)
{
    if(l == r)
    {
        T[root].l = lpos[now];
        T[root].r = rpos[now];
        now++;
        return;
    }

    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1 | 1);
    pushup(root);
}

void query(node &ans, int L, int R, int l, int r, int root)
{
    if(L <= l && r <= R)
    {
        maxx(ans, T[root]);
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid)
        query(ans, L, R, l, mid, root << 1);
    if(R > mid)
        query(ans, L, R, mid + 1, r, root << 1 | 1);
}

int ans[maxn];

int main (void)
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        pp[i].n = i;
        scanf("%lld %lld", &pp[i].pos, &pp[i].ra);
        pos[i] = pp[i].pos;
    }

    for(int i = 1; i <= n; i++)
        lpos[i] = pp[i].pos - pp[i].ra, rpos[i] = pp[i].pos + pp[i].ra;

    now = 1;
    build(1, n, 1);

    bool tag = true;
    while(tag)
    {
        tag = false;
        for(int i = 1; i <= n; i++)
        {
            int lcan = lower_bound(pos + 1, pos + n + 1, lpos[i]) - pos;
            int rcan = upper_bound(pos + 1, pos + n + 1, rpos[i]) - pos - 1;
            ans[pp[i].n] = rcan - lcan + 1;
            node ret = node(3e18, -3e18);
            query(ret, lcan, rcan, 1, n, 1);
            if(lpos[i] > ret.l || rpos[i] < ret.r)
            {
                tag = true;
                if(lpos[i] > ret.l)
                    lpos[i] = ret.l;
                if(rpos[i] < ret.r)
                    rpos[i] = ret.r;
                update(i, ret, 1, n, 1);
            }
        }
    }
    long long ret = 0;
    for(int i = 1; i <= n; i++)
        (ret += (long long)ans[i] * i % mod) %= mod;
    printf("%lld\n", ret);
    return 0;
}