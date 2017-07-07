//
// Created by 孙启龙 on 2017/3/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>

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
char str[100];
vector<node>G[maxn];

int num(void)
{
    if(str[0] == 'x')
        return -1;
    else
        return atoi(str);
}

void init()
{
    for(int i = 0; i < maxn; i++)
    {
        mindist[i] = INF;
        G[i].clear();
        inqueue[i] = false;
    }
}

void SPFA(int S)
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
}

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        init();
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                scanf("%s", str);
                int len = num();
                if(len >= 0)
                {
                    G[i].push_back(node(j, len));
                    G[j].push_back(node(i, len));
                    //printf("%d -> %d = %d\n", i, j, len);
                    //printf("%d -> %d = %d\n", j, i, len);
                }
            }
        }
        SPFA(1);
        int maxx = 0;
        for(int i = 2; i <= n; i++)
            maxx = max(maxx, mindist[i]);
        printf("%d\n", maxx);
    }
    return 0;
}