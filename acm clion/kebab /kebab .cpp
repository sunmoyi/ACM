//
// Created by 孙启龙 on 2017/10/20.
//

#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>

#define INF 1e9
using namespace std;
const int maxn = 600 + 5;

struct Edge {
    int from, to, cap, flow;

    Edge() {
    }

    Edge(int f, int t, int c, int fl) : from(f), to(t), cap(c), flow(fl) {
    }
};

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int d[maxn];
    int cur[maxn];
    bool vis[maxn];

    void init(int n, int s, int t) {
        this->n = n, this->s = s, this->t = t;
        edges.clear();
        for (int i = 0; i < n; ++i)
            G[i].clear();
    }

    void AddEdge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS() {
        queue<int> Q;
        memset(vis, 0, sizeof(vis));
        vis[s] = true;
        d[s] = 0;
        Q.push(s);
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); ++i) {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = true;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x, int a) {
        if (x == t || a == 0)
            return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); ++i) {
            Edge &e = edges[G[x][i]];
            if (d[e.to] == d[x] + 1 && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }

    int max_flow() {
        int ans = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            ans += DFS(s, INF);
        }
        return ans;
    }
} DC;

int N, M;
int s[maxn], n[maxn], e[maxn], t[maxn];
int timee[maxn];
int full_flow;

int main() {
    while (scanf("%d%d", &N, &M) == 2) {
        full_flow = 0;
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            scanf("%d%d%d%d", &s[i], &n[i], &e[i], &t[i]);
            timee[cnt++] = s[i];
            timee[cnt++] = e[i];
            full_flow += n[i] * t[i];
        }
        sort(timee, timee + cnt);
        cnt = unique(timee, timee + cnt) - timee;//去重
        int src = 0, dst = N + cnt + 1;
        //最大流节点个数、起点、终点。
        DC.init(N + cnt + 2, src, dst);

        for (int i = 1; i <= N; i++)
            DC.AddEdge(src, i, n[i] * t[i]);
        for (int i = 1; i <= cnt - 1; ++i) {
            DC.AddEdge(N + i, dst, (timee[i] - timee[i - 1]) * M);
            for (int j = 1; j <= N; ++j)
                if (s[j] <= timee[i - 1] && timee[i] <= e[j])
                    DC.AddEdge(j, N + i, INF);
        }
        printf("%s\n", DC.max_flow() == full_flow ? "Yes" : "No");
    }
    return 0;
}