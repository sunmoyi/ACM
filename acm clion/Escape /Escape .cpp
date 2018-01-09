//
// Created by 孙启龙 on 2017/10/18.
//

#include <queue>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 2060;

struct edge {
    int to, cap, rev;

    edge(int a, int b, int c) {
        to = a;
        cap = b;
        rev = c;
    }
};

vector<edge> G[maxn];
int level[maxn], iter[maxn], n, cnt[maxn];

void add_edge(int from, int to, int cap) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size() - 1));
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (unsigned int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t)
        return f;
    for (int &i = iter[v]; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (1) {
        bfs(s);
        if (level[t] < 0)
            return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, inf)) > 0)
            flow += f;
    }
}

int main(void) {
    int n, m, op;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < maxn; i++)
            G[i].clear();
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            int temp = 0;
            for (int j = 0; j < m; j++) {
                scanf("%d", &op);
                if (op == 1)
                    temp += (1 << j);
            }
            cnt[temp]++;
        }
        for (int i = 0; i < (1 << m); i++) {
            if (cnt[i]) {
                add_edge(0, i + 1, cnt[i]);
                for (int j = 0; j < m; j++) {
                    if (i & (1 << j))
                        add_edge(i + 1, (1 << m) + 2 + j, cnt[i]);
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &op);
            add_edge((1 << m) + i + 1, (1 << m) + m + 2, op);
        }
        int ans = max_flow(0, (1 << m) + m + 2);
        if (ans >= n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}