//
// Created by 孙启龙 on 2017/10/22.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <iomanip>

#define mem(a, b) memset(a,b,sizeof(a))
using namespace std;
#define M 2000005
#define N 200005
#pragma comment(linker, "/STACK:102400000,102400000")

inline void RD(int &ret) {
    char c;
    do {
        c = getchar();
    } while (c < '0' || c > '9');
    ret = c - '0';
    while ((c = getchar()) >= '0' && c <= '9')
        ret = ret * 10 + (c - '0');
}

struct edge {
    int e, next, sign;
} ed[M], reed[M];
int n, m;
int head[N], num, rehead[N], renum;
int dfn[N], low[N], st[N], inst[N], belong[N];
int dp, top, cnt;
int dis[N];
bool vis[N];
int bridgenum;

void add(int s, int e) {
    ed[num].e = e;
    ed[num].sign = 0;
    ed[num].next = head[s];
    head[s] = num++;
}

void readd(int s, int e) {
    reed[renum].e = e;
    reed[renum].sign = 0;
    reed[renum].next = rehead[s];
    rehead[s] = renum++;
}

void init() {
    mem(dfn, 0);
    mem(low, 0);
    mem(st, 0);
    mem(belong, 0);
    mem(head, -1);
    num = 0;
    dp = 0;
    top = 0;
    cnt = 0;
    mem(rehead, -1);
    renum = 0;
    bridgenum = 0;
}

void tarjan(int now, int fa) {
    dfn[now] = low[now] = ++dp;
    st[top++] = now;
    inst[now] = 1;

    for (int i = head[now]; ~i; i = ed[i].next) {
        if (ed[i].sign)
            continue;
        ed[i].sign = ed[i ^ 1].sign = 1;
        int e = ed[i].e;
        if (!dfn[e]) {
            tarjan(e, now);
            low[now] = min(low[now], low[e]);
            if (dfn[now] < low[e]) {
                bridgenum++;
            }
        } else if (inst[e]) {
            low[now] = min(low[now], dfn[e]);
        }
    }
    if (low[now] == dfn[now]) {
        int xx;
        cnt++;
        do {
            xx = st[--top];
            inst[xx] = 0;
            belong[xx] = cnt;
        } while (xx != now);
    }
}

void build() {
    for (int i = 1; i <= n; i++) {
        dp = 0, top = 0;
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; ~j; j = ed[j].next) {
            int e = ed[j].e;
            if (belong[i] == belong[e])
                continue;
            readd(belong[i], belong[e]);
            readd(belong[e], belong[i]);
        }
    }
}

queue<int> qe;
int pos;

int bfs(int s) {
    while (!qe.empty())
        qe.pop();
    dis[s] = 0;
    mem(vis, 0);
    vis[s] = 1;
    qe.push(s);
    int ans = 0;
    while (!qe.empty()) {
        int temp = qe.front();
        qe.pop();
        for (int i = rehead[temp]; ~i; i = reed[i].next) {
            int e = reed[i].e;
            if (!vis[e]) {
                dis[e] = dis[temp] + 1;
                vis[e] = 1;
                qe.push(e);
                if (ans < dis[e]) {
                    ans = dis[e];
                    pos = e;
                }
            }
        }
    }
    return ans;
}

int main() {
    while (scanf("%d%d", &n, &m), (n + m)) {
        init();
        while (m--) {
            int a, b;
            RD(a);
            RD(b);
            add(a, b);
            add(b, a);
        }
        build();
        bfs(1);
        int now = bfs(pos);
        printf("%d\n", bridgenum - now);
    }
    return 0;
}