//
// Created by 孙启龙 on 2017/3/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

using namespace std;

long long add[maxn << 2];
long long sum[maxn << 2];

void pushup(long long rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(long long rt, long long len)
{
    if(add[rt])
    {
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];

        sum[rt << 1] += add[rt] * (len - (len >> 1));
        sum[rt << 1 | 1] += add[rt] * (len >> 1);
        add[rt] = 0;
    }
}

void build(long long l, long long r, long long rt)
{
    add[rt] = 0;
    if(l == r)
    {
        sum[rt] = 0;
        return;
    }

    long long mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(long long L, long long R, long long c, long long l, long long r, long long rt)
{
    if(L <= l && r <= R)
    {
        add[rt] += c;
        sum[rt] += (long long)c * (r - l + 1);
        return;
    }

    pushdown(rt, r - l + 1);
    long long mid = (l + r) >> 1;
    if(L <= mid)
        update(L, R, c, lson);
    if(R >= mid + 1)
        update(L, R, c, rson);
    pushup(rt);
}

long long query(long long L, long long R, long long l, long long r, long long rt)
{
    if(L <= l && r <= R)
    {
        return sum[rt];
    }
    pushdown(rt, r - l + 1);
    long long mid = (l + r) >> 1;
    long long ret = 0;
    if(L <= mid)
        ret += query(L, R, lson);
    if(mid < R)
        ret += query(L, R, rson);
    return ret;
}

int main (void)
{
    long long N, Q;
    long long t;
    long long Case = 0;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &N, &Q);
        build(1, N, 1);
        printf("Case %lld:\n", ++Case);
        while(Q--)
        {
            long long op, a, b, c;
            scanf("%lld", &op);
            if(op == 1)
            {
                scanf("%lld %lld", &a, &b);
                printf("%lld\n", query(a + 1, b + 1, 1, N, 1));
            }
            else if (op == 0)
            {
                scanf("%lld %lld %lld", &a, &b, &c);
                update(a + 1, b + 1, c, 1, N, 1);
            }
        }
    }
    return 0;
}