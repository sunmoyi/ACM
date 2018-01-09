//
// Created by 孙启龙 on 2017/10/27.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100005;

struct Edge {
    int u, v, w, nxt;

    Edge() {
    }

    Edge(int a, int b, int c, int d) : u(a), v(b), w(c), nxt(d) {
    }
} e[N << 1];

int size[N], top[N], son[N], fa[N], dep[N], id[N];
int n, q, s, head[N], cnt, tot, tree[N << 2];

void AddEdge(int u, int v, int w) {
    e[cnt] = Edge(u, v, w, head[u]);
    head[u] = cnt++;
    e[cnt] = Edge(v, u, w, head[v]);
    head[v] = cnt++;
}

void dfs2(int u, int tp) {
    top[u] = tp;
    id[u] = ++tot;
    if (son[u])
        dfs2(son[u], tp);
    for (int i = head[u]; i + 1; i = e[i].nxt) {
        int v = e[i].v;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

void dfs1(int u, int f, int depth) {
    son[u] = 0, size[u] = 1, fa[u] = f, dep[u] = depth;
    for (int i = head[u]; i + 1; i = e[i].nxt) {
        int v = e[i].v;
        if (v == f)
            continue;
        dfs1(v, u, depth + 1);
        size[u] += size[v];
        if (size[son[u]] < size[v])
            son[u] = v;
    }
}

void pushup(int k) {
    tree[k] = tree[k * 2] + tree[k * 2 + 1];
}

void modify(int k, int left, int right, int pos, int v) {
    if (left == right) {
        tree[k] = v;
        return;
    }
    int mid = (left + right) / 2;
    if (pos <= mid)
        modify(k * 2, left, mid, pos, v);
    else
        modify(k * 2 + 1, mid + 1, right, pos, v);
    pushup(k);
}

int query(int k, int left, int right, int l, int r) {
    if (l <= left && right <= r)
        return tree[k];
    int mid = (left + right) / 2, res = 0;
    if (l <= mid)
        res += query(k * 2, left, mid, l, r);
    if (r > mid)
        res += query(k * 2 + 1, mid + 1, right, l, r);
    return res;
}

void solve(int u, int v) {
    int tp1 = top[u], tp2 = top[v];
    int res = 0;
    while (tp1 != tp2) {
        if (dep[tp1] < dep[tp2]) {
            swap(tp1, tp2);
            swap(u, v);
        }
        res += query(1, 1, tot, id[tp1], id[u]);
        u = fa[tp1];
        tp1 = top[u];
    }
    if (u != v) {
        if (dep[u] > dep[v])
            swap(u, v);
        res += query(1, 1, tot, id[son[u]], id[v]);
    }
    printf("%d\n", res);
}

int main() {
    while (scanf("%d%d%d", &n, &q, &s) == 3) {
        int u, v, w;
        memset(head, -1, sizeof(head));
        memset(tree, 0, sizeof(tree));
        cnt = tot = 0;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d%d", &u, &v, &w);
            AddEdge(u, v, w);
        }
        dfs1(1, 0, 1);
        dfs2(1, 1);
        for (int i = 0; i < cnt; i += 2) {
            u = e[i].u, v = e[i].v;
            if (dep[u] < dep[v])
                swap(u, v);
            modify(1, 1, tot, id[u], e[i].w);
        }
        int op, a, b;
        while (q--) {
            scanf("%d%d", &op, &a);
            if (op == 0) {
                solve(s, a);
                s = a;
            } else {
                scanf("%d", &b);
                u = e[a - 1 << 1].u;
                v = e[a - 1 << 1].v;
                if (dep[u] < dep[v])
                    swap(u, v);
                modify(1, 1, tot, id[u], b);
            }
        }
    }
    return 0;
}