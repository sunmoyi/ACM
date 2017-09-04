//
// Created by 孙启龙 on 2017/8/6.
//

#include"iostream"
#include"cstdio"
#include"cstring"

using namespace std;
const int N = 10005;
const int M = 20005;
const int N_Q = 2000005;

int n, m, q, dis[N], vis[N], father[N], ans[N_Q / 2];

struct Edge {
    int v, len, next;
} edge[M];
int tot, head[N];

inline void add(int a, int b, int c) {
    edge[tot].v = b;
    edge[tot].len = c;
    edge[tot].next = head[a];
    head[a] = tot++;
    edge[tot].v = a;
    edge[tot].len = c;
    edge[tot].next = head[b];
    head[b] = tot++;
}

struct Ques {
    int v, index, next;
} Q[N_Q];
int q_tot, q_head[N];

void add_ques(int a, int b, int index) {
    Q[q_tot].v = b;
    Q[q_tot].index = index;
    Q[q_tot].next = q_head[a];
    q_head[a] = q_tot++;
    Q[q_tot].v = a;
    Q[q_tot].index = index;
    Q[q_tot].next = q_head[b];
    q_head[b] = q_tot++;
}

int find(int k) {
    if (father[k] == k)
        return k;
    father[k] = find(father[k]);
    return father[k];
}

void Tarjan_LCA(int k, int deep, int root) {
    int j, v;
    father[k] = k;
    vis[k] = root;
    dis[k] = deep;
    for (j = head[k]; j != -1; j = edge[j].next) {
        v = edge[j].v;
        if (vis[v] != -1)
            continue;
        Tarjan_LCA(v, deep + edge[j].len, root);
        father[v] = k;
    }
    for (j = q_head[k]; j != -1; j = Q[j].next) {
        v = Q[j].v;
        if (vis[v] != root)
            continue;
        ans[Q[j].index] = dis[v] + dis[k] - 2 * dis[find(v)];
    }
}

int main() {
    int i;
    int a, b, c;
    while (scanf("%d%d%d", &n, &m, &q) != -1) {
        tot = q_tot = 0;
        memset(head, -1, sizeof(head));
        memset(q_head, -1, sizeof(q_head));
        while (m--) {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        for (i = 0; i < q; i++) {
            scanf("%d%d", &a, &b);
            ans[i] = -1;
            add_ques(a, b, i);
        }

        memset(vis, -1, sizeof(vis));
        for (i = 1; i <= n; i++)
            if (vis[i] == -1)
                Tarjan_LCA(i, 0, i);
        for (i = 0; i < q; i++) {
            if (ans[i] == -1)
                printf("Not connected\n");
            else
                printf("%d\n", ans[i]);
        }
    }
    return 0;
}