//
// Created by 孙启龙 on 2016/11/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 100
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int v, len;
    node(int v = 0, int len = 0): v(v), len(len){}
    friend bool operator < (const node&a, const node&b)
    {
        return a.len > b.len;
    }
};

bool inqueue[maxn];
int mindist[maxn];
int n, m;
vector<node>G[maxn];
int nouse;

void init()
{
    for(int i = 0; i < maxn; i++)
    {
        mindist[i] = INF;
        G[i].clear();
        inqueue[i] = false;
    }
}

void init2()
{
    for(int i = 0; i < maxn; i++)
    {
        mindist[i] = INF;
        inqueue[i] = false;
    }
}

int Dijkstra(int s, int t)
{
    mindist[s] = 0;
    inqueue[s] = true;
    priority_queue<node>Q;
    for(int i = 0; i < G[s].size(); i++)
    {
        int vex = G[s][i].v;
        if(vex == nouse)
            continue;
        Q.push(G[s][i]);
        mindist[vex] = min(mindist[vex], G[s][i].len);
        inqueue[vex] = true;
    }
    while(!Q.empty())
    {
        node now = Q.top();
        Q.pop();
        inqueue[now.v] = 0;
        for(int i = 0; i < G[now.v].size(); i++)
        {
            int vex = G[now.v][i].v;
            int len = G[now.v][i].len;
            if(vex == nouse)
                continue;
            if(len + mindist[now.v] < mindist[vex])
            {
                mindist[vex] = mindist[now.v] + len;
                if(!inqueue[vex])
                {
                    inqueue[vex] = true;
                    Q.push(G[now.v][i]);
                }
            }
        }
    }
    return mindist[t];
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF && (n + m))
    {
        init();
        int a, b, len;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &a, &b, &len);
            G[a].push_back(node(b, len));
            G[b].push_back(node(a, len));
        }
        int maxx = -1;
        for(int i = 2; i < n; i++)
        {
            init2();
            nouse = i;
            int ans = Dijkstra(1, n);
            maxx = max(maxx, ans);
        }
        if(maxx == INF)
            printf("Inf\n");
        else
            printf("%d\n", maxx);
    }
    return 0;
}