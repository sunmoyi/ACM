//
// Created by 孙启龙 on 2017/1/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 100010
#define INF 0x3f3f3f3f

using namespace std;

struct edge{
    int u, v, c;
    edge(int u = 0, int v = 0, int c = 0):u(u), v(v), c(c){}
};

vector<edge>edges;
vector<int>G[maxn];

void addedge(int u, int v, int c)
{
    edges.push_back(edge(u, v, c));
    int idx = edges.size() - 1;
    G[u].push_back(idx);
};

int n, vis[maxn];
int d[maxn];

void rev_bfs()
{
    memset(vis, 0, sizeof(vis));
    d[n - 1] = 0;
    vis[n - 1] = true;

    queue<int>Q;
    Q.push(n - 1);
    while(!Q.empty())
    {
        int v = Q.front(); Q.pop();
        for(int i = 0; i < G[v].size(); i++)
        {
            int e = G[v][i];
            int u = edges[e].v;
            if(!vis[u])
            {
                vis[u] = true;
                d[u] = d[v] + 1;
                Q.push(u);
            }
        }
    }
}

vector<int>ans;

void bfs()
{
    memset(vis, 0, sizeof(vis));
    vis[0] = true;
    ans.clear();

    vector<int>next;
    next.push_back(0);
    for(int i = 0; i < d[0]; i++)
    {
        int min_color = INF;
        for(int j = 0; j < next.size(); j++)
        {
            int u = next[j];
            for(int k = 0; k < G[u].size(); k++)
            {
                int e = G[u][k];
                int v = edges[e].v;
                if(d[u] == d[v] + 1)
                    min_color = min(min_color, edges[e].c);
            }
        }
        ans.push_back(min_color);

        vector<int>next2;
        for(int j = 0; j < next.size(); j++)
        {
            int u = next[j];
            for(int k = 0; k < G[u].size(); k++)
            {
                int e = G[u][k];
                int v = edges[e].v;
                if(d[u] == d[v] + 1 && !vis[v] && edges[e].c == min_color)
                {
                    vis[v] = true;
                    next2.push_back(v);
                }
            }
        }
        next = next2;
    }

    printf("%d\n", (int)ans.size());
    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);
    printf("\n");
}

int main (void)
{
    int u, v, c, m;
    while(scanf("%d %d", &n, &m) == 2)
    {
        edges.clear();
        for(int i = 0; i < n; i++)
            G[i].clear();
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &c);
            addedge(u - 1, v - 1, c);
            addedge(v - 1, u - 1, c);
        }
        rev_bfs();
        bfs();
    }
    return 0;
}