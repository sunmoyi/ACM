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
int mindist[maxn];
int n, m;
vector<node>G[maxn];

void init()
{
    for(int i = 0; i <= m + 1; i++)
    {
        mindist[i] = INF;
        G[i].clear();
        inqueue[i] = false;
    }
}

int SPFA(int S, int T)
{
    priority_queue<node>Q;
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
    return mindist[T];
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        init();
        int a, b, len;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d %d", &a, &b, &len);
            G[a].push_back(node(b, len));
            G[b].push_back(node(a, len));
        }
        int ans = SPFA(1, m);
        printf("%d\n", ans);
    }
    return 0;
}