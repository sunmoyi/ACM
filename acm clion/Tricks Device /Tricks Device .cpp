//
// Created by 孙启龙 on 2017/10/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>
#include <queue>

#define maxn 2010
#define maxm 120010
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
struct Edge {
    int to, w, next;
} edge[maxm];
int tot, head[maxn];
int dis[maxn], vis[maxn];
int minb[maxn];

void addedge(int u, int v, int w) {
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;

    edge[tot].to = u;
    edge[tot].w = w;
    edge[tot].next = head[v];
    head[v] = tot++;
}

int spfa(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(minb, 0x3f, sizeof(minb));

    queue<int> Q;
    dis[s] = 0;
    minb[s] = 0;
    vis[s] = 1;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = 0;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to, w = edge[i].w;
            if (dis[v] == dis[u] + w) {
                minb[v] = min(minb[v], minb[u] + 1);
                if (!vis[v])
                    vis[v] = 1, Q.push(v);
            }
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                minb[v] = minb[u] + 1;
                if (!vis[v])
                    vis[v] = 1, Q.push(v);
            }
        }
    }
}

struct Eg {
    int u, cap, rev;

    Eg(int u = 0, int cap = 0, int rev = 0) : u(u), cap(cap), rev(rev) {
    }
};

vector<Eg> G[maxn];
bool used[maxn];

void add(int u, int v, int cap) {
    G[u].push_back(Eg(v, cap, G[v].size()));
    G[v].push_back(Eg(u, 0, G[u].size() - 1));
}

void build() {
    for (int i = 1; i <= n; ++i) {
        for (int j = head[i]; j != -1; j = edge[j].next) {
            int v = edge[j].to, w = edge[j].w;
            if (dis[v] - dis[i] == w)
                add(i, v, 1);
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t)
        return f;
    used[v] = true;
    for (int i = 0; i < G[v].size(); ++i) {
        Eg &e = G[v][i];
        if (!used[e.u] && e.cap > 0) {
            int d = dfs(e.u, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.u][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (1) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0)
            return flow;
        flow += f;
    }
}

void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i <= n; i++)
        G[i].clear();
}

int main(void) {
    while (scanf("%d %d", &n, &m) != EOF) {
        init();
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
        }
        spfa(1);
        build();
        int ans = max_flow(1, n);
        printf("%d %d\n", ans, m - minb[n]);
    }
    return 0;
}