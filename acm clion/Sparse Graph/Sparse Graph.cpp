//
// Created by 孙启龙 on 2017/7/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include <queue>

#define maxn 200010
#define INF 0x3f3f3f3f

using namespace std;

vector<int>G[maxn];
int dist[maxn];
int n;

void bfs(int s)
{
    set<int>open, closed;
    set<int>::iterator it;
    for(int i = 1; i <= n; i++)
        if(i != s)
            open.insert(i);
    memset(dist, INF, sizeof(dist));

    queue<int>Q;
    Q.push(s);
    dist[s] = 0;
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(!open.count(v))
                continue;
            open.erase(v);
            closed.insert(v);
        }
        for(it = open.begin(); it != open.end(); it++)
        {
            dist[*it] = dist[u] + 1;
            Q.push(*it);
        }
        open.swap(closed);
        closed.clear();
    }
}

int main (void)
{
    int m, u, v, s, T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            G[i].clear();
        while(m--)
        {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        scanf("%d", &s);
        bfs(s);

        for(int i = 1; i <= n; i++)
        {
            if(i == s)
                continue;
            printf("%d%c",dist[i]==INF?-1:dist[i]," \n"[i==n]);
        }
    }
    return 0;
}