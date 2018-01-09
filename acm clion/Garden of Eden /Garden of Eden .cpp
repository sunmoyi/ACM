//
// Created by 孙启龙 on 2017/10/24.
//

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
#define MS(x, y) memset(x,y,sizeof(x))
typedef long long LL;
const int MAXN = 5e4 + 5;
struct Edge {
    int v, nxt;
} edge[MAXN << 1];
int head[MAXN], edgenum;

void addedge(int u, int v) {
    edge[edgenum].v = v;
    edge[edgenum].nxt = head[u];
    head[u] = edgenum++;
}

int n, k, K;
int col[MAXN];
LL ans;

int root, max_sub;
int siz[MAXN];
LL cnt[MAXN], cnt1[MAXN];
bool used[MAXN];

void findroot(int u, int f, int num) {
    siz[u] = 1;
    int K = 0;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int &v = edge[i].v;
        if (used[v] || v == f)
            continue;
        findroot(v, u, num);
        K = max(K, siz[v]);
        siz[u] += siz[v];
    }
    K = max(K, num - siz[u]);
    if (K < max_sub)
        max_sub = K, root = u;
}

void dfs(int u, int f, int sta) {
    sta |= (1 << col[u]);
    ++cnt[sta];
    ++cnt1[sta];
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int &v = edge[i].v;
        if (used[v] || v == f)
            continue;
        dfs(v, u, sta);
    }
}

LL work2(int u, int sta) {
    for (int i = 0; i <= K; ++i)
        cnt[i] = cnt1[i] = 0;
    sta |= (1 << col[u]);
    ++cnt[sta];
    ++cnt1[sta];
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int &v = edge[i].v;
        if (used[v])
            continue;
        dfs(v, u, sta);
    }
    for (int i = 0; i < k; ++i)
        for (int j = K; j >= 0; --j) { //高维前缀和
            if (!((1 << i) & j))
                cnt[j] += cnt[(1 << i) | j];
        }
    LL ret = 0;
    for (int i = 1; i <= K; ++i)
        ret += cnt1[i] * cnt[(K ^ i)];
    return ret;
}

LL work1(int u, int num) {
    max_sub = num;
    root = u;
    findroot(u, 0, num);
    u = root;
    used[u] = true;
    LL ret = work2(u, 0);
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int &v = edge[i].v;
        if (used[v])
            continue;
        ret -= work2(v, (1 << col[u]));
        ret += work1(v, siz[v]);
    }
    return ret;
}

int main() {
    while (~scanf("%d%d", &n, &k)) {
        ans = 0;
        K = (1 << k) - 1;
        MS(head, -1);
        MS(used, false);
        edgenum = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%d", col + i), --col[i];
        int u, v;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        printf("%lld\n", work1(1, n));
    }
}