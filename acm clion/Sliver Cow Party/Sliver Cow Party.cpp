//
// Created by 孙启龙 on 2017/3/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 10010
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int v, len;
    node(int v = 0, int len = 0): v(v), len(len){}
    bool friend operator < (const node&a, const node&b)
    {
        return a.len > b.len;
    }
};
bool inqueue[maxn];
int mindist1[maxn];
int mindist2[maxn];
int n, m;
vector<node>G[maxn];
vector<node>GT[maxn];

void init()
{
    for(int i = 0; i < maxn; i++)
    {
        mindist1[i] = INF;
        mindist2[i] = INF;
        G[i].clear();
        GT[i].clear();
    }
}

void SPFA(int S,int *mindist, vector<node>G[])
{
    priority_queue<node>Q;
    memset(inqueue, false, sizeof(inqueue));
    mindist[S] = 0;
    inqueue[S] = true;
    for(int i = 0; i < G[S].size(); i++)
    {
        int vex = G[S][i].v;
        mindist[vex] = min(G[S][i].len, mindist[vex]);
        inqueue[vex] = true;
        Q.push(G[S][i]);
    }
    while(!Q.empty())
    {
        node now = Q.top();
        Q.pop();
        inqueue[now.v] = false;
        for(int i = 0; i < G[now.v].size(); i++)
        {
            int vex = G[now.v][i].v;
            int len = G[now.v][i].len;
            if(len + mindist[now.v] < mindist[vex])
            {
                mindist[vex] = len + mindist[now.v];
                if(!inqueue[vex])
                {
                    inqueue[vex] = true;
                    Q.push(G[now.v][i]);
                }
            }
        }
    }
}

int main (void)
{
    int s;
    while(scanf("%d %d %d ", &n, &m, &s) != EOF)
    {
        init();
        int a, b, len;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &a, &b, &len);
            G[a].push_back(node(b, len));
            GT[b].push_back(node(a, len));
        }
        SPFA(s, mindist1, G);
        SPFA(s, mindist2, GT);
        int maxx = 0;
        for(int i = 1; i <= n; i++)
            maxx = max(maxx, mindist1[i] + mindist2[i]);
        printf("%d\n", maxx);
    }
    return 0;
}