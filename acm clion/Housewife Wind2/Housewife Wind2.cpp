//
// Created by 孙启龙 on 2017/10/25.
//

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 0x0fffffff;

const int MAXN = 400022;

int n, m, k;

struct Edge {
    int t, next, len;
} edge[MAXN << 1];

int head[MAXN], tot;

void add_edge(int s, int t, int len) {
    edge[tot].len = len;
    edge[tot].t = t;
    edge[tot].next = head[s];
    head[s] = tot++;
}

bool is_black[MAXN], getted[MAXN];

int num[MAXN], maxv[MAXN];

int father[MAXN];

void dfs1(int u, int fa) {
    father[u] = fa;
    num[u] = 1;
    maxv[u] = 0;
    for (int e = head[u]; e != -1; e = edge[e].next) {
        int v = edge[e].t;
        if (getted[v] || v == fa)
            continue;
        dfs1(v, u);
        num[u] += num[v];
        maxv[u] = max(maxv[u], num[v]);
    }
}

int minn;

void dfs2(int u, int sum, int &root) {
    for (int e = head[u]; e != -1; e = edge[e].next) {
        int v = edge[e].t;
        if (getted[v] || v == father[u])
            continue;
        dfs2(v, sum, root);
    }
    int tmp = max(sum - num[u], maxv[u]);
    if (tmp < minn) {
        minn = tmp;
        root = u;
    }
}

int get_root(int x) {
    dfs1(x, 0);
    minn = INF;
    int sum_node = num[x];
    int root;
    dfs2(x, sum_node, root);
    return root;
}

int dep[MAXN];

void get_dep(int u, int fa) {
    dep[u] = is_black[u];
    for (int e = head[u]; e != -1; e = edge[e].next) {
        int v = edge[e].t;
        if (getted[v] || v == fa)
            continue;
        get_dep(v, u);
        dep[u] = max(dep[u], is_black[u] + dep[v]);
    }
}

int g[MAXN];

void get_g(int u, int fa, int s, int c) {
    g[c] = max(g[c], s);
    for (int e = head[u]; e != -1; e = edge[e].next) {
        int v = edge[e].t;
        int len = edge[e].len;
        if (getted[v] || v == fa)
            continue;
        get_g(v, u, s + len, c + is_black[v]);
    }
}

int id[MAXN];

bool cmp(int a, int b) {
    return dep[edge[a].t] < dep[edge[b].t];
}

int ans;

int f[MAXN];

void solve(int x) {
    int root = get_root(x);
    getted[root] = 1;
    for (int e = head[root]; e != -1; e = edge[e].next) {
        int v = edge[e].t;
        if (getted[v])
            continue;
        solve(v);
    }
    int cc = 0;
    for (int e = head[root]; e != -1; e = edge[e].next) {
        int v = edge[e].t;
        if (getted[v])
            continue;
        get_dep(v, root);
        id[cc++] = e;
    }
    sort(id, id + cc, cmp);
    for (int i = 0; i <= dep[edge[id[cc - 1]].t]; i++)
        f[i] = -INF;
    for (int i = 0; i < cc; i++) {
        int cur = edge[id[i]].t;
        int len = edge[id[i]].len;
        for (int j = 0; j <= dep[cur]; j++)
            g[j] = -INF;
        get_g(cur, root, len, is_black[cur]);
        if (i > 0) {
            int end = min(k - is_black[root], dep[cur]);
            for (int j = 0; j <= end; j++) {
                int p = min(dep[edge[id[i - 1]].t], k - j - is_black[root]);
                if (f[p] == -INF)
                    break;
                if (g[j] != -INF)
                    ans = max(ans, g[j] + f[p]);
            }
        }
        for (int j = 0; j <= dep[cur]; j++) {
            f[j] = max(f[j], g[j]);
            if (j > 0)
                f[j] = max(f[j], f[j - 1]);
            if (i == 0 && j + is_black[root] <= k)
                ans = max(ans, f[j]);
        }
    }
    getted[root] = 0;
}

int main() {
    while (~scanf("%d%d%d", &n, &k, &m)) {
        memset(is_black, 0, sizeof(is_black));
        int pos;
        for (int i = 0; i < m; i++) {
            scanf("%d", &pos);
            is_black[pos] = 1;
        }
        memset(head, -1, sizeof(head));
        tot = 0;
        int a, b, c;
        for (int i = 1; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            add_edge(a, b, c);
            add_edge(b, a, c);
        }
        ans = 0;
        memset(getted, 0, sizeof(getted));
        solve(1);
        printf("%d\n", ans);
    }
    return 0;
}