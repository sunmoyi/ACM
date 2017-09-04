//
// Created by 孙启龙 on 2017/8/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

#define maxn 40000
#define maxm 16

using namespace std;

struct edge {
    int to, weight;

    edge(int to = 0, int weight = 0) : to(to), weight(weight) {
    }
};

vector<edge> G[maxn];
int vis[maxn << 1];
int depth[maxn << 1];
int id[maxn];
int dist[maxn];
int dp[maxn << 1][maxm];

void add_edge(int from, int to, int weight) {
    G[from].push_back(edge(to, weight));
}

void dfs(int v, int fa, int d, int &k) {
    id[v] = k;
    vis[k] = v;
    depth[k++] = d;
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i].to != fa) {
            dist[G[v][i].to] = dist[v] + G[v][i].weight;
            dfs(G[v][i].to, v, d + 1, k);
            vis[k] = v;
            depth[k++] = d;
        }
    }
}

void rmq_init(int n) {
    for (int i = 0; i < n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            if (depth[dp[i][j - 1]] <= depth[dp[i + (1 << (j - 1))][j - 1]]) {
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = dp[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

int query(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) < r - l + 1)
        k++;
    if (depth[dp[l][k]] <= depth[dp[r - (1 << k)][k]]) {
        return dp[l][k];
    } else {
        return dp[r - (1 << k)][k];
    }
}

void init(int V) {
    int k = 0, root = 0;
    dfs(root, -1, 0, k);
    rmq_init(V * 2 - 1);
}

int lca(int u, int v) {
    return vis[query(min(id[u], id[v]), max(id[u], id[v]) + 1)];
}

int main(void) {
    int V, E;
    while (scanf("%d %d", &V, &E) != EOF) {
        int u, v, w;
        char r;

        for (int i = 0; i < E; i++) {
            scanf("%d %d %d %c", &u, &v, &w, &r);
            --u, --v;
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        init(V);
        int K;
        scanf("%d", &K);
        for (int i = 0; i < K; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u, --v;
            int t = lca(u, v);
            int ans = dist[u] - dist[t] + dist[v] - dist[t];
            printf("%d\n", ans);
        }
    }
    return 0;
}