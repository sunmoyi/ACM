//
// Created by 孙启龙 on 2017/9/24.
//
//
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include <queue>
//
//#define maxn 100010
//
//using namespace std;
//
//struct node{
//    int v, w, next;
//}edge[maxn << 2];
//
//int n, cnt, head[maxn], dis[maxn], vis[maxn], val[maxn];
//
//void add(int u, int v, int w)
//{
//    edge[cnt].v = v;
//    edge[cnt].w = w;
//    edge[cnt].next = head[u];
//    head[u] = cnt++;
//}
//
//void spfa(int s)
//{
//    queue<int>Q;
//    memset(vis, 0, sizeof(vis));
//    for(int i = 1; i <= n + 2; i++)
//        dis[i] = 0xf3f3f3f3;
//    dis[s] = 0;
//    vis[s] = 1;
//    Q.push(s);
//    while(!Q.empty())
//    {
//        int u = Q.front();
//        Q.pop();
//        vis[u] = 0;
//        for(int i = head[u]; ~i; i = edge[i].next)
//        {
//            int v = edge[i].v;
//            int w = edge[i].w;
//            if(dis[v] < dis[u] + w)
//            {
//                dis[v] = dis[u] + w;
//                if(!vis[v])
//                    vis[v] = true, Q.push(v);
//            }
//        }
//    }
//}
//
//int main (void)
//{
//    int u, v, w;
//    int T;
//    scanf("%d", &T);
//    while(T--)
//    {
//        cnt = 0;
//        memset(head, 0xff, sizeof(head));
//        scanf("%d", &n);
//        for(int i = 1; i <= n; i++)
//            scanf("%d", &val[i]);
//        for(int i = 1; i < n; i++)
//            scanf("%d %d %d", &u, &v, &w), add(u, v, -w), add(v, u, -w);
//        int S = n + 1, T = n + 2;
//        for(int i = 1; i <= n; i++)
//            add(S, i, -val[i]), add(i, T, val[i]);
//        spfa(S);
//        printf("%d\n", dis[T]);
//    }
//    return 0;
//}

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
#define rush() int T;scanf("%d",&T);while(T--)

typedef long long ll;
const int maxn = 100005;

struct node {
    int v, w;

    node(int _v, int _w) : v(_v), w(_w) {
    }
};

int n, ans;
int val[maxn];
int dp[maxn][2];
vector<node> vec[maxn];

void dfs(int u, int pre) {
    dp[u][0] = -val[u];
    dp[u][1] = val[u];
    for (int i = 0; i < vec[u].size(); i++) {
        int v = vec[u][i].v;
        int w = vec[u][i].w;
        if (v == pre)
            continue;
        dfs(v, u);
        dp[u][0] = max(dp[u][0], dp[v][0] - w);
        dp[u][1] = max(dp[u][1], dp[v][1] - w);
    }
    ans = max(ans, dp[u][0] + dp[u][1]);
}

int main() {
    int u, v, w;
    rush() {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            vec[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &val[i]);
        }
        for (int i = 1; i < n; i++) {
            scanf("%d%d%d", &u, &v, &w);
            vec[u].push_back(node(v, w));
            vec[v].push_back(node(u, w));
        }
        ans = 0;
        dfs(1, -1);
        printf("%d\n", ans);
    }
    return 0;
}