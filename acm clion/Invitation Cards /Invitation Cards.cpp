//
// Created by 孙启龙 on 2017/3/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 1000010
#define INF 0x3f3f3f3f

using namespace std;

struct {
    int w, v, next;
}edge[maxn];
int edgehead[maxn];
long long d[maxn];
bool vis[maxn];
int n, m, k;
int a[maxn][3];

struct cmp{
    bool operator() (const int a, const int b)
    {
        return d[a] > d[a];
    }
};

void addedge(int u, int v, int w)
{
    edge[k].v = v;
    edge[k].w = w;
    edge[k].next = edgehead[u];
    edgehead[u] = k++;
}

long long Dijkstra()
{
    memset(d, 0x7f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    priority_queue<int , vector<int>, cmp>que;
    d[1] = 0;
    que.push(1);

    while(!que.empty())
    {
        int u = que.top();
        vis[u] = true;
        que.pop();
        for(int i = edgehead[u]; i != 0; i = edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if(!vis[v] && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                que.push(v);
            }
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        ans += d[i];
    return ans;
}

int main (void)
{
    int Case;
    scanf("%d", &Case);
    while(Case--)
    {
        k = 1;
        memset(edgehead, 0, sizeof(edgehead));
        memset(edge, 0, sizeof(edge));
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", a[i], a[i] + 1, a[i] + 2);
            addedge(a[i][0], a[i][1], a[i][2]);
        }
        long long ans = Dijkstra();
        k = 1;
        memset(edgehead, 0, sizeof(edgehead));
        memset(edge, 0, sizeof(edge));
        for(int i = 1; i <= m; i++)
        {
            addedge(a[i][1], a[i][0], a[i][2]);
        }
        ans += Dijkstra();
        printf("%lld\n", ans);
    }
    return 0;
}