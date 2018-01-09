////
//// Created by 孙启龙 on 2017/9/9.
////
//
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<stack>
//#include<vector>
//#define N 10010
//using namespace std;
//
//int dfn[N], low[N], sccno[N], dfs_clock, cnt;
//stack<int> st;
//vector<int> g[N];
//
//int n, m;
//
//void tarjan(int u) {
//    dfn[u] = low[u] = ++dfs_clock;
//    st.push(u);
//    for (int i = 0; i < g[u].size(); ++i) {
//        int v = g[u][i];
//        if (dfn[v] == 0) {
//            tarjan(v);
//            low[u] = min(low[u], low[v]);
//        } else if (sccno[v] == 0)
//        {
//            low[u] = min(low[u], low[v]);
//        }
//    }
//    if (low[u] == dfn[u]) {
//        cnt++;
//        for (;;) {
//            int x = st.top();
//            st.pop();
//            sccno[x] = cnt;
//            if (x == u)
//                break;
//        }
//    }
//}
//
//bool in[N], out[N];
//
//void init() {
//    scanf("%d %d", &n, &m);
//    dfs_clock = cnt = 0;
//    while (!st.empty())
//        st.pop();
//    for (int i = 1; i <= n; ++i) {
//        sccno[i] = 0;
//        g[i].clear();
//        low[i] = dfn[i] = 0;
//        in[i] = out[i] = false;
//    }
//    for (int i = 1; i <= m; i++) {
//        int a, b;
//        scanf("%d %d", &a, &b);
//        g[a].push_back(b);
//    }
//}
//
//int main() {
//
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//
//        init();
//        for (int i = 1; i <= n; ++i) {
//            if (dfn[i] == 0)
//                tarjan(i);
//        }
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 0; j < g[i].size(); ++j) {
//                int v = g[i][j];
//                if (sccno[i] == sccno[v])
//                    continue;
//                out[sccno[i]] = true;
//                in[sccno[v]] = true;
//            }
//        }
//        if (cnt == 1) {
//            printf("0\n");
//            continue;
//        }
//        int cnt1 = 0, cnt2 = 0;
//        for (int i = 1; i <= cnt; ++i) {
//            if (!in[i])
//                cnt1++;
//            if (!out[i])
//                cnt2++;
//        }
//        printf("%d\n", max(cnt1, cnt2));
//    }
//    return 0;
//}