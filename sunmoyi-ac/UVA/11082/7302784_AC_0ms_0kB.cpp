//
// Created by 孙启龙 on 16/10/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 60
#define INF 0x3f3f3f3f

using namespace std;

struct Edge{
    int from, to, cap, flow;
    Edge(int from = 0, int to = 0, int cap = 0, int flow = 0):from(from), to(to), cap(cap), flow(flow){}
};

struct EdmondsKarp{
    int n, m;
    vector<Edge>edges;
    vector<int>G[maxn];
    int a[maxn];
    int p[maxn];

    void init(int x)
    {
        for(int i = 0; i <= x; i++)
            G[i].clear();
        edges.clear();
    }

    void addedge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    int maxflow(int s, int t)
    {
        int flow = 0;
        while(true)
        {
            memset(a, 0, sizeof(a));
            queue<int>Q;
            a[s] = INF;
            Q.push(s);
            while(!Q.empty())
            {
                int x = Q.front();
                Q.pop();
                for(int i = 0; i < G[x].size(); i++)
                {
                    Edge &e = edges[G[x][i]];
                    if(!a[e.to] && e.cap > e.flow)
                    {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x], e.cap - e.flow);
                        Q.push(e.to);
                    }
                }
                if(a[t])
                    break;
            }
            if(!a[t])
                break;
            for(int u = t; u != s; u = edges[p[u]].from)
            {
                edges[p[u]].flow += a[t];
                edges[p[u] ^ 1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};

EdmondsKarp g;
int no[maxn][maxn];

int main (void)
{
    int T, R, C, v, Case = 0;
    scanf("%d", &T);
    while(++Case <= T)
    {
        scanf("%d %d", &R, &C);
        g.init(R + C + 2);
        int last = 0;
        for(int i = 1; i <= R; i++)
        {
            scanf("%d", &v);
            g.addedge(0, i, v - last - C);
            last = v;
        }
        last = 0;
        for(int i = 1; i <= C; i++)
        {
            scanf("%d", &v);
            g.addedge(R + i, R + C + 1, v - last - R);
            last = v;
        }
        for(int i = 1; i <= R; i++)
        {
            for(int j = 1; j <= C; j++)
            {
                g.addedge(i, R + j, 19);
                no[i][j] = g.edges.size() - 2;
            }
        }
        g.maxflow(0, R + C + 1);

        printf("Matrix %d\n", Case);
        for(int i = 1; i <= R; i++)
        {
            for(int j = 1; j <= C; j++)
            {
                printf("%d ", g.edges[no[i][j]].flow + 1);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}