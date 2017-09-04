//
// Created by 孙启龙 on 2017/8/8.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
const int N = 100005;
const int M = 20;

int __pow[M];
int head[N], tot;
struct edge {
    int u, v, w, next;
} e[2 * N];
int dep[N], first[N], dir[N], vis[N], ver[2 * N], R[2 * N];
int dp[2 * N][M];

inline void add(int u, int v, int w) {
    e[tot].u = u;
    e[tot].v = v;
    e[tot].w = w;
    e[tot].next = head[u];
    head[u] = tot++;
}

void dfs(int u, int d) {
    tot++;
    vis[u] = 1;
    dep[u] = d;
    first[u] = tot;
    ver[tot] = u;
    R[tot] = d;
    for (int k = head[u]; k != -1; k = e[k].next)
        if (!vis[e[k].v]) {
            int v = e[k].v, w = e[k].w;
            dir[v] = dir[u] + w;
            dfs(v, d + 1);
            tot++;
            ver[tot] = u;
            R[tot] = d;
        }
}

void ST(int n) {
    int K = (int) (log((double) n) / log(2.0));
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int j = 1; j <= K; j++)
        for (int i = 1; i + __pow[j] - 1 <= n; i++) {
            int a = dp[i][j - 1], b = dp[i + __pow[j - 1]][j - 1];
            if (R[a] < R[b])
                dp[i][j] = a;
            else
                dp[i][j] = b;
        }
}

inline int RMQ(int x, int y) {
    int K = (int) (log((double) (y - x + 1)) / log(2.0));
    int a = dp[x][K], b = dp[y - __pow[K] + 1][K];
    if (R[a] < R[b])
        return a;
    else
        return b;
}

int LCA(int u, int v) {
    int x = first[u], y = first[v];
    if (x > y)
        swap(x, y);
    int index = RMQ(x, y);
    return ver[index];
}

void travel(int u, int par, int delta) {
    dir[u] += delta;
    for (int k = head[u]; k != -1; k = e[k].next)
        if (e[k].v != par) {
            int v = e[k].v;
            travel(v, u, delta);
        }
}

int main() {
    int n, q, sp;
    for (int i = 0; i < M; i++)
        __pow[i] = (1 << i);
    while (scanf("%d%d%d", &n, &q, &sp) != EOF) {
        tot = 0;
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        tot = dir[1] = 0;
        dfs(1, 1);
        ST(2 * n - 1);
        while (q--) {
            int c;
            scanf("%d", &c);
            if (c == 0) {
                int v;
                scanf("%d", &v);
                int lca = LCA(sp, v);
                printf("%d\n", dir[sp] + dir[v] - 2 * dir[lca]);
                sp = v;
            } else {
                int k, w, delta, u, v;
                scanf("%d%d", &k, &w);
                k = (k - 1) << 1;
                u = e[k].u;
                v = e[k].v;
                delta = w - e[k].w;
                e[k].w = e[k ^ 1].w = w;
                int x = dep[u] > dep[v] ? u : v;
                int y = dep[u] < dep[v] ? u : v;
                travel(x, y, delta);
            }
        }
    }
    return 0;
}