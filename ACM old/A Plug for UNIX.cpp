//
// Created by 孙启龙 on 16/10/22.
//

#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
#define maxn 410
#define INF 0x3f3f3f3f

using namespace std;

struct Edge{
    int from, to, cap, flow;
    Edge(int from = 0, int to = 0, int cap = 0, int flow = 0):from(from), to(to), cap(cap), flow(flow){}
};
vector<string>names;
int n, m, k;
int targer[maxn];
int device[maxn];
int from[maxn], to[maxn];

int ID(const string& s)
{
    for(int i = 0; i < names.size(); i++)
        if(names[i] == s)
            return i;
    names.push_back(s);
    return names.size() - 1;
}

struct Edmondskarp{
    int n, m;
    vector<Edge>edges;           //边数的两倍， 正反两条边 其中 i如果是原边   （i^1）就是其反向遍
    vector<int>G[maxn];          //临界链表， 其中G[i][j]表示结点i的第j条边的标号
    int a[maxn];                 //起点到i这个点的最大可改进亮
    int p[maxn];                 //最短路上的弧

    void init(int n)
    {
        for(int i = 0; i < n; i++)
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
            Q.push(s);
            a[s] = INF;
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

Edmondskarp g;

int main (void)
{
    int T;
    cin >> T;
    while(T--)
    {
        names.clear();
        string s1, s2;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> s1;
            targer[i] = ID(s1);
        }
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> s1 >> s2;
            device[i] = ID(s2);
        }
        cin >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> s1 >> s2;
            from[i] = ID(s1);
            to[i] = ID(s2);
        }

        int V = names.size();
        g.init(V + 2);
        for(int i = 0; i < m; i++)
            g.addedge(V, device[i], 1);
        for(int i = 0; i < n; i++)
            g.addedge(targer[i], V + 1, 1);
        for(int i = 0; i < k; i++)
            g.addedge(from[i], to[i], INF);
        int r = g.maxflow(V, V + 1);
        cout << m - r << endl;
        if(T)
            cout << endl;
    }
    return 0;
}