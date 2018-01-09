//#include<cstdio>
//#include<queue>
//#include<vector>
//#include<iostream>
//
//#define maxn 10010
//using namespace std;
//
//struct Node {
//    int v;
//    int w;
//
//    Node(int v = 0, int w = 0): v(v), w(w){}
//};
//
//vector<Node> E[maxn];
//int d[maxn];
//int Case;
//int n, m;
//
//void init() {
//    scanf("%d %d", &n, &m);
//    int in[maxn] = {0};
//    for (int i = 0; i < maxn; i++)
//        E[i].clear();
//    for (int i = 0; i < m; i++) {
//        int x, y, z;
//        scanf("%d %d %d", &x, &y, &z);
//        E[x].push_back(Node(y, z));
//        in[y]++;
//    }
//    for (int i = 1; i <= n; i++) {
//        if (!in[i]) {
//            E[0].push_back(Node(i, 0));
//        }
//    }
//}
//
//void run()
//{
//    for (int i = 0; i < maxn; i++)
//        d[i] = 0;
//    priority_queue<pair<int, int> > q;
//    q.push(make_pair(d[0], 0));
//    while (!q.empty()) {
//        int now = q.top().second;
//        q.pop();
//        for (int i = 0; i < E[now].size(); i++) {
//            int v = E[now][i].v;
//            if (d[v] <= d[now] + E[now][i].w) {
//                d[v] = d[now] + E[now][i].w;
//                q.push(make_pair(d[v], v));
//            }
//        }
//    }
//}
//
//int anss()
//{
//    int ans = 0;
//    for (int i = 1; i <= n; i++)
//        ans = max(ans, d[i]);
//    return ans;
//}
//
//int main() {
//    scanf("%d", &Case);
//    while (Case--) {
//        init();
//        run();
//
//        printf("%d\n", anss());
//    }
//}
