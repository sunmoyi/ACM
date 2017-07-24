//
// Created by 孙启龙 on 2017/4/29.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define MOD 9223372034707292160ll

using namespace std;

unsigned long long trees[maxn << 2];
bool cover[maxn << 2];
int n, q;
int ql, qr;

unsigned long long modmul(unsigned long long a, unsigned long long k)
{
    unsigned long long c = 0;
    while(k)
    {
        if(k & 1)
            c = (c + a) % MOD;
        a = (a + a) % MOD;
        k >>= 1;
    }
    return c;
}

void build(int root, int l, int r)
{
    trees[root] = 0;
    cover[root] = false;
    if(l == r)
    {
        scanf("%llu", &trees[root]);
        return;
    }
    int mid = (l + r) >> 1;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
    trees[root] = (trees[root << 1] + trees[root << 1 | 1]) % MOD;
}

unsigned long long query(int root, int l, int r)
{
    if(ql <= l && r <= qr)
        return trees[root];

    int mid = (l + r) >> 1;
    unsigned long long ans = 0;
    if(ql <= mid)
        ans = (ans + query(root << 1, l, mid)) % MOD;
    if(qr > mid)
        ans = (ans + query(root << 1 | 1, mid + 1, r)) % MOD;
    return ans;
}

void modify(int root, int l, int r)
{
    if(cover[root] && ql <= l && r <= qr)
        return;
    if(l == r)
    {
        unsigned long long temp = modmul(trees[root], trees[root]);
        if(temp == trees[root])
            cover[root] = true;
        trees[root] = temp;
        return;
    }

    int mid = (l + r) >> 1;
    if(ql <= mid)
        modify(root << 1, l, mid);
    if(qr > mid)
        modify(root << 1 | 1, mid + 1, r);
    cover[root] = cover[root << 1] & cover[root << 1 | 1];
    trees[root] = (trees[root << 1] + trees[root << 1 | 1]) % MOD;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        scanf("%d %d", &n, &q);
        build(1, 1, n);
        printf("Case #%d:\n", Case);
        unsigned long long ans = 0;
        while(q--)
        {
            scanf("%d %d", &ql, &qr);
            ans = (ans + query(1, 1, n)) % MOD;
            printf("%llu\n", ans);
            modify(1, 1, n);
        }
    }
    return 0;
}