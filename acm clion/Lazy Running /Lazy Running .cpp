//
// Created by 孙启龙 on 2017/10/16.
//


#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <iostream>

#define LL long long
using namespace std;

struct Edge { int y;LL w; };
typedef pair<LL, int> P;
vector<Edge> g[4];
LL d[4][100000], K, m;
int n, s;

inline void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++)
            d[i][j] = 2000000000000000000;
    q.push(P(0LL, s));                           //d[s][0]不能赋值为0
    while (!q.empty()) {
        LL w = q.top().first;
        int j = q.top().second;
        q.pop();
        if (w > d[j][w % m])
            continue;
        for (int k = 0; k < g[j].size(); k++) {
            int y = g[j][k].y;
            LL dist = w + g[j][k].w;
            if (d[y][dist % m] > dist)                   //更新的时候更新取模后对应的点
            {
                d[y][dist % m] = dist;
                q.push(P(dist, y));
            }
        }
    }
}

int main() {
    n = 4;
    s = 1;
    int T_T;
    cin >> T_T;
    while (T_T--) {
        int d1, d2, d3, d4;
        memset(g, 0, sizeof(g));
        scanf("%I64d%d%d%d%d", &K, &d1, &d2, &d3, &d4);
        g[0].push_back(Edge{1, d1});
        g[1].push_back(Edge{0, d1});
        g[1].push_back(Edge{2, d2});
        g[2].push_back(Edge{1, d2});
        g[2].push_back(Edge{3, d3});
        g[3].push_back(Edge{2, d3});
        g[3].push_back(Edge{0, d4});
        g[0].push_back(Edge{3, d4});
        m = 2 * min(d1, d2);                         //为了使效率更高，w取两条与2相连的边中小的那个
        dijkstra(s);
        LL ans = 2000000000000000000;
        int p;
        for (int i = 0; i < m; i++)                     //枚举剩余系下所有的可能的最小花费
        {
            LL delta = K - d[1][i];
            if (delta <= 0)
                ans = min(ans, d[1][i]);
            else
                ans = min(ans, d[1][i] + delta / m * m + (delta % m > 0) * m);
        }
        printf("%lld\n", ans);
    }
    return 0;
}