//
// Created by 孙启龙 on 2017/7/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

long long mod;
long long tree[maxn << 2];
long long p;
long long add;

void build(int l, int r, int root)
{
    if(l == r)
    {
        tree[root] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1 | 1);
    tree[root] = 1;
}

void update(int l, int r, int root, long long pos, long long val)
{
    if(l == r)
    {
        tree[root] = val;
        return;
    }

    int mid = (l + r) >> 1;
    if(pos <= mid)
        update(l, mid, root << 1, pos, val);
    else
        update(mid + 1, r, root << 1 | 1, pos, val);
    tree[root] = (tree[root << 1] * tree[root << 1 | 1]) % mod;
}

int main (void)
{
    int T, Q;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        scanf("%d %lld", &Q, &mod);
        printf("Case #%d:\n", Case);
        build(1, Q, 1);
        for(int i = 1; i <= Q; i++)
        {
            int x;
            long long y;
            scanf("%d %lld", &x, &y);
            if(x == 1)
                p = i, add = y;
            else
                p = y, add = 1;
            update(1, Q, 1, p, add);
            printf("%lld\n", tree[1]);
        }
    }
    return 0;
}