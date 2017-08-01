//
// Created by 孙启龙 on 2017/7/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxn 20010

using namespace std;

int fa[maxn], num[maxn], t, n, m, q, pp[maxn];

struct query {
    int x, id;

    bool operator<(const query &a) const {
        return x < a.x;
    }
} a[maxn];

struct Edge {
    int u, v, w;

    bool operator<(const Edge &a) const {
        return w < a.w;
    }
} edge[maxn * 5];

void init() {
    for (int i = 1; i <= n; i++) {
        num[i] = 1;
        fa[i] = i;
    }
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void nuion(int x, int y) {
    x = find(x);
    y = find(y);
    if (y < x)
        swap(x, y);
    fa[y] = x;
    num[x] += num[y];
}

int main(void) {
    scanf("%d", &t);
    while (t--) {
        int ans = 0;
        scanf("%d %d %d", &n, &m, &q);
        init();
        for (int i = 0; i < m; i++)
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        sort(edge, edge + m);
        int j = 0;
        for (int i = 0; i < q; i++) {
            a[i].id = i;
            scanf("%d", &a[i].x);
        }
        sort(a, a + q);
        for (int i = 0; i < q; i++) {
            while (j < m && edge[j].w <= a[i].x) {
                int u = find(edge[j].u);
                int v = find(edge[j].v);
                j++;
                if (u == v)
                    continue;
                ans += (num[u] + num[v]) * (num[u] + num[v] - 1) -
                       num[u] * (num[u] - 1) - num[v] * (num[v] - 1);
                nuion(u, v);
            }
            pp[a[i].id] = ans;
        }
        for (int i = 0; i < q; i++)
            printf("%d\n", pp[i]);
    }
    return 0;
}