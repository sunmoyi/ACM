//
// Created by 孙启龙 on 2017/8/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define MAXN 1010
#define MAXM 600000
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

#define MAX_NODE MAXN
#define MAX_EDGE_NUM MAXM

struct Edge{
    int to;
    int vol;
    int cost;
    int next;
};
Edge gEdges[MAX_EDGE_NUM];

int gHead[MAX_NODE];
int gPre[MAX_NODE];
int gPath[MAX_NODE];
int gDist[MAX_NODE];
bool vis[MAX_NODE];

int gEdgeCount;
void InsertEdge(int u, int v, int vol, int cost){
    gEdges[gEdgeCount].to = v;
    gEdges[gEdgeCount].vol = vol;
    gEdges[gEdgeCount].cost = cost;
    gEdges[gEdgeCount].next = gHead[u];
    gHead[u] = gEdgeCount++;

    gEdges[gEdgeCount].to = u;
    gEdges[gEdgeCount].vol = 0;         //vol为0，表示开始时候，该边的反向不通
    gEdges[gEdgeCount].cost = -cost;    //cost 为正向边的cost相反数，这是为了
    gEdges[gEdgeCount].next = gHead[v];
    gHead[v] = gEdgeCount++;
}

//假设图中不存在负权和环,SPFA算法找到最短路径/从源点s到终点t所经过边的cost之和最小的路径
bool Spfa(int s, int t){
    memset(gPre, -1, sizeof(gPre));
    memset(gDist, 0x3F, sizeof(gDist));
    memset(vis, false, sizeof(vis));
    gDist[s] = 0;
    vis[s] = true;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()){//由于不存在负权和环，因此一定会结束
        int u = Q.front();
        Q.pop();
        vis[u] = false;
        for (int e = gHead[u]; e != -1; e = gEdges[e].next){
            int v = gEdges[e].to;
            if (gEdges[e].vol > 0 && gDist[u] + gEdges[e].cost < gDist[v]){
                gDist[v] = gDist[u] + gEdges[e].cost;
                gPre[v] = u; //前一个点
                gPath[v] = e;//该点连接的前一个边
                if(!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }

    if (gPre[t] == -1 || gDist[t] > 0)  //若终点t没有设置pre，说明不存在到达终点t的路径
        return false;
    return true;
}

int MinCostFlow(int s, int t){
    int cost = 0;
    int flow = 0;
    while (Spfa(s, t)){
        int f = INF;
        for (int u = t; u != s; u = gPre[u]){
            if (gEdges[gPath[u]].vol < f)
                f = gEdges[gPath[u]].vol;
        }
        flow += f;
        cost += gDist[t] * f;
        for (int u = t; u != s; u = gPre[u]){
            gEdges[gPath[u]].vol -= f;   //正向边容量减少
            gEdges[gPath[u]^1].vol += f; //反向边容量增加
        }
    }
    return cost;
}

int main (void)
{
    int u, v, len;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(gHead, 0xff, sizeof(gHead));
        gEdgeCount = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &u, &v, &len);
            InsertEdge(u, v, 0x3f3f3f3f, len);
            InsertEdge(v, u, 0x3f3f3f3f, len);
        }

        for (int i = 1; i <= n; i++)
            InsertEdge(0, i, b[i], a[i]);
        for(int i = 1; i <= n; i++)
            InsertEdge(i, n + 1, d[i], -c[i]);
        int start = 0, endd = n + 1;
        int ans = MinCostFlow(start, endd);
        printf("%d\n", -ans);
    }
    return 0;
}