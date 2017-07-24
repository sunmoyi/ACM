//
// Created by 孙启龙 on 2017/4/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50010
#define INF 0x3f3f3f3f

using namespace std;

int trees[maxn << 2];
int n, m, a, b;

void build(int l, int r, int root)
{
    trees[root] = INF;
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1 | 1);
}

void update(int R, int val, int l, int r, int root)
{
    trees[root] = min(trees[root], val);
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    if(R <= mid)
        update(R, val, l, mid, root << 1);
    else
        update(R, val, mid + 1, r, root << 1 | 1);
}

int query(int L, int R, int l, int r, int root)
{
    if(L <= l && r <= R)
        return trees[root];
    int mid = (l + r) >> 1;
    if(R <= mid)
        return query(L, R, l, mid, root << 1);
    else if (L > mid)
        return query(L, R, mid + 1, r, root << 1 | 1);
    else
    {
        int ans1 = query(L, R, l, mid, root << 1);
        int ans2 = query(L, R, mid + 1, r, root << 1 | 1);
        return min(ans1, ans2);
    }
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        build(1, n, 1);
        update(1, 0, 1, n, 1);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            if(a < b)
            {
                int x = query(a, b - 1, 1, n, 1);
                update(b, x + 1, 1, n, 1);
            }
        }
        printf("%d\n", query(n, n, 1, n, 1));
    }
    return 0;
}