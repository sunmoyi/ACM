//
// Created by 孙启龙 on 2017/7/29.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define maxn 150005

using namespace std;

struct node {
    char name[205];
    int v, tp;

    friend bool operator<(node a, node b) {
        if (a.v == b.v)
            return a.tp > b.tp;
        return a.v < b.v;
    }
};

struct node1 {
    int t, r;
} ask[maxn];
node fri[maxn];
int put[maxn], wen[105];

bool cmp(node1 a, node1 b) {
    return a.t < b.t;
}

int main() {
    int t, k, m, p, ok, now;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &k, &m, &p);
        for (int i = 0; i < k; i++) {
            scanf("%s %d", fri[i].name, &fri[i].v);
            fri[i].tp = i;
        }
        ask[0].t = -1;
        for (int i = 0; i < m; i++)
            scanf("%d %d", &ask[i].t, &ask[i].r);
        for (int i = 0; i < p; i++)
            scanf("%d", &wen[i]);
        priority_queue<node> q;
        sort(ask, ask + m, cmp);
        now = 0;
        ok = 0;
        for (int i = 1; i <= k; i++) {
            q.push(fri[i - 1]);
            if (i == ask[now].t) {
                for (int j = 1; j <= ask[now].r && (!q.empty()); j++) {
                    node x = q.top();
                    q.pop();
                    put[ok++] = x.tp;
                }
                now++;
            }
        }
        while (!q.empty()) {
            node x = q.top();
            q.pop();
            put[ok++] = x.tp;
        }
        for (int i = 0; i < p; i++)
            printf("%s%c", fri[put[wen[i] - 1]].name, i == p - 1 ? '\n' : ' ');
    }
}