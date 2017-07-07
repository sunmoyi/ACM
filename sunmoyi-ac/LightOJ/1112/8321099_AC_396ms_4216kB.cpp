//
// Created by 孙启龙 on 2017/3/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

long long tree[maxn << 2];

void pushup(int root)
{
    tree[root] = tree[root << 1] + tree[root << 1 | 1];
}

void build(int l, int r, int root)
{
    if(l == r)
    {
        scanf("%lld", &tree[root]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1 | 1);
    pushup(root);
}

void update(int l, int r, int root, int L, int R, long long add)
{
    if(L <= l && r <= R)
    {
        tree[root] += add;
        return;
    }

    int mid = (l + r) >> 1;
    if(L <= mid)
        update(l, mid, root << 1, L, R, add);
    if(R >= mid + 1)
        update(mid + 1, r, root << 1 | 1, L, R, add);
    pushup(root);
}

long long query(int l, int r, int root, int L, int R)
{
    if(L <= l && r <= R)
    {
        return tree[root];
    }

    long long ans = 0;
    int mid = (l + r) >> 1;
    if(L <= mid)
        ans += query(l, mid, root << 1, L, R);
    if (R >= mid + 1)
        ans += query(mid + 1, r, root << 1 | 1, L, R);

    return ans;
}

int main (void)
{
    int Case = 1, T;
    scanf("%d", &T);
    for(Case = 1; Case <= T; Case++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        memset(tree, 0, sizeof(tree));
        build(1, n, 1);
        printf("Case %d:\n", Case);
        while(m--)
        {
            int op, x, y;
            scanf("%d", &op);
            if(op == 1)
            {
                scanf("%d", &x);
                x++;
                printf("%lld\n", query(1, n, 1, x, x));
                update(1, n, 1, x, x, -query(1, n, 1, x, x));
            }
            else if (op == 2)
            {
                scanf("%d %d", &x, &y);
                x++;
                update(1, n, 1, x, x, y);
            }
            else if (op == 3)
            {
                scanf("%d %d", &x, &y);
                x++; y++;
                printf("%lld\n", query(1, n, 1, x, y));
            }
        }
    }
    return 0;
}