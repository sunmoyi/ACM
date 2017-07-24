//
// Created by 孙启龙 on 2017/4/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int n, q;
int a[maxn];
int maxx[maxn << 2];
int L[maxn], R[maxn];

void build(int l, int r, int root)
{
    if(l == r)
    {
        maxx[root] = L[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1 | 1);
    maxx[root] = max(maxx[root << 1], maxx[root << 1 | 1]);
}

int query(int _L, int _R, int l, int r, int root)
{
    if(_L <= l && r <= _R)
        return maxx[root];

    int mid = (l + r) >> 1;
    int ans = 0;
    if(mid >= _L)
        ans = max(query(_L, _R, l, mid, root << 1), ans);
    if(mid < _R)
        ans = max(ans, query(_L, _R, mid + 1, r, root << 1 | 1));
    return ans;
}

int main (void)
{
    int n, q;
    while(scanf("%d", &n) != EOF && n)
    {
        scanf("%d", &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", a + i);
        L[n] = 1;
        for(int i = n - 1; i >= 1; i--)
        {
            if(a[i] == a[i + 1])
                L[i] = L[i + 1] + 1;
            else
                L[i] = 1;
        }
        R[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            if(a[i] == a[i - 1])
                R[i] = R[i - 1] + 1;
            else
                R[i] = 1;
        }
        build(1, n, 1);
        while(q--)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            int ans = max(min(L[u], v - u + 1), min(R[v], v - u + 1));
            int l = u + L[u];
            int r = v - R[v];

            if(l <= r)
                ans = max(query(l, r, 1, n, 1), ans);
            printf("%d\n", ans);
        }
    }
    return 0;
}