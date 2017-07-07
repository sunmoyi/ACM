//
// Created by 孙启龙 on 2017/4/13.
//

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
#define MAX_V 1000 + 16
#define MAX_L 1000000

struct edge
{
    int to, cost;
    edge(){}
    edge(int to, int cost) : to(to), cost(cost){}
};
typedef pair<int, int> P;
vector<edge> G[MAX_V];
int d[MAX_V];
int V, E;


int dijkstra_ex(int s, int x)
{
    priority_queue<P, vector<P>, greater<P> > que;
    memset(d, 0x3f, V * sizeof(int));
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i)
        {
            edge e = G[v][i];
            int new_d = d[v] + (e.cost >= x ? 1 : 0);
            if (d[e.to] > new_d)
            {
                d[e.to] = new_d;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d[V - 1];
}

int main(int argc, char *argv[])
{
    int K;
    cin >> V >> E >> K;
    for (int i = 0; i < E; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        --from;
        --to;
        G[from].push_back(edge(to, cost));
        G[to].push_back(edge(from, cost));
    }
    int lb = 0, ub = MAX_L + 2;
    while (ub - lb > 1)
    {
        int mid = (ub + lb) >> 1;
        if (dijkstra_ex(0, mid) > K)
        {
            lb = mid;
        }
        else
        {
            ub = mid;
        }
    }
    cout << (lb > MAX_L ? -1 : lb) << endl;

    return 0;
}