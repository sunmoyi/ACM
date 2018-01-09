//
// Created by 孙启龙 on 2017/10/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 100010
#define maxm 200010
#define INF 1e18

using namespace std;

long long dist[maxn];
int head[maxn], tot;
long long dist2[maxn];

struct edge{
    int from, to, next;
    long long cost;
}e[maxm];

void addedge(int u, int v, int w)
{
    e[tot].from = u;
    e[tot].to = v;
    e[tot].cost = w;
    e[tot].next = head[u];
    head[u] = tot++;
}

struct node{
    int v;
    long long c;
    node(long long c = 0, int v = 0):v(v), c(c){}
    bool operator < (const node &rhs)const {
        return c > rhs.c;
    }
};

void Dijkstra(int n, int st)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(dist2, 0x3f, sizeof(dist2));
    priority_queue<node>Q;
    while(!Q.empty())
        Q.pop();
    dist[st] = 0;
    Q.push(node(0, st));
    while(!Q.empty())
    {
        node now = Q.top();
        Q.pop();
        int u = now.v;
        long long d = now.c;
        if(dist2[u] < d)
            continue;
        for(int i = head[u]; i != -1; i = e[i].next)
        {
            int to = e[i].to;
            long long cost = e[i].cost;
            long long d2 = cost + d;
            if(dist[to] > d2)
            {
                swap(dist[to], d2);
                Q.push(node(dist[to], to));
            }
            if(dist2[to] > d2 && dist[to] < d2)
            {
                dist2[to] = d2;
                Q.push(node(dist2[to], to));
            }
        }
    }
}

int main(void)
{
    int T;
    int vn, en;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &vn ,&en);
        tot = 0;
        memset(head, -1, sizeof(head));
        int u, v, w;
        for(int i = 1; i <= en; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        int st, ed;
        st = 1, ed = vn;
        Dijkstra(vn, st);
        printf("%lld\n", dist2[ed]);
    }
    return 0;
}