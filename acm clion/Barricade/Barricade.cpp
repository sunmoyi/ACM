//
// Created by 孙启龙 on 2017/7/18.
//


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 1010
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int v, w;
    node(int v = 0, int w = 0):v(v), w(w){}
};
vector<node>e[maxn];
int s, t, n, m, vs, vt;
int d[maxn];
int vis[maxn];

void spfa()
{
    memset(vis,0,sizeof(vis));
    for(int i = 1;i<=n;i++)
        d[i]=INF;
    d[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u]=0;
        for(int i = 0;i<e[u].size();i++)
        {
            int v = e[u][i].v;
            if(d[v]>d[u]+1)
            {
                d[v]=d[u]+1;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}

struct Edge{
    int from, to, cap, flow;
    Edge(int from = 0, int to = 0, int cap = 0, int flow = 0): from(from), to(to), cap(cap), flow(flow){}
};

struct Dinic{
    int s, t;
    vector<Edge>edges;
    vector<int>G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void init()
    {
        for(int i = 0; i <= n + 1; i++)
            G[i].clear();
        edges.clear();
    }

    void addedge(int from, int to, int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        int mm = (int)edges.size();
        G[from].push_back(mm-2);
        G[to].push_back(mm-1);
    }

    bool bfs()
    {
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(s);
        d[s]=0;
        vis[s]=1;
        while (!q.empty())
        {
            int x = q.front();q.pop();
            for (int i = 0;i<G[x].size();i++)
            {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to]=1;
                    d[e.to] = d[x]+1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int dfs(int x, int a)
    {
        if (x==t || a==0)
            return a;
        int flow = 0,f;
        for(int &i=cur[x];i<G[x].size();i++)
        {
            Edge &e = edges[G[x][i]];
            if (d[x]+1 == d[e.to] && (f=dfs(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if (a==0)
                    break;
            }
        }
        return flow;
    }

    int maxflow(int s, int t)
    {
        this->s=s;
        this->t=t;
        int flow = 0;
        while (bfs())
        {
            memset(cur,0,sizeof(cur));
            flow+=dfs(s,INF);
        }
        return flow;
    }
}dc;

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; i++)
            e[i].clear();
        for(int i = 1; i <= m; i++)
        {
            int u, v, di;
            scanf("%d %d %d", &u, &v, &di);
            e[u].push_back(node(v, di));
            e[v].push_back(node(u, di));
        }
        s = 1, t = n;
        spfa();
        dc.init();
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < e[i].size(); j++)
                if(d[e[i][j].v] == d[i] + 1)
                    dc.addedge(i, e[i][j].v, e[i][j].w);
        printf("%d\n", dc.maxflow(s, t));
    }
    return 0;
}