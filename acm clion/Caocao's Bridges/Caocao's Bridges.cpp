//
// Created by 孙启龙 on 2017/5/2.
//

#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

#define MAX_N 1010
#define MAX_M  MAX_N*MAX_N*2//类似有向边
#define INF 0xfffffff

int n, m;
int dfn[MAX_N], low[MAX_N], head[MAX_N];

int ans = INF, tot, num;

struct Bridge {
    int v, c, id, next;
}e[MAX_M];


//双向增加边
void addBridge(int u, int v, int c, int id)
{
    e[tot].v = v;
    e[tot].c = c;
    e[tot].id = id;
    e[tot].next = head[u];
    head[u] = tot++;
}
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++num;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        int id = e[i].id;
        if (fa == id) continue;//同一条边
        if (!dfn[v]) {
            tarjan(v, id);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v]) {//说明此处为桥，更新ans
                ans = min(ans, e[i].c);
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
int main() {
    int u, v, w;
    while (cin >> n >> m ,n||m) {
        tot = 0;
        memset(head, -1, sizeof(head));
        for (int i = 1; i <= m; i++) {
            cin >> u >> v >> w;
            addBridge(u, v, w, i);
            addBridge(v, u, w, i);
        }

        ans = INF;
        num = 0;
        memset(dfn, 0, sizeof(dfn));
        int ok = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!dfn[i]) {
                ok++;
                tarjan(i, 0);
            }
        }
        if (ans == 0)ans = 1;
        if (ans == INF)ans = -1;
        if (ok > 1)ans = 0;
        cout << ans << endl;
    }
    return 0;
}