//
// Created by 孙启龙 on 2017/3/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 330
#define INF 0x3f3f3f3f

using namespace std;

int cost[maxn][maxn];
int dist[maxn];
int que[maxn * 10];
bool vis[maxn];

void spfa(int start, int n)
{
    int front = 0, rear = 0;
    for(int v = 1; v <= n; v++)
    {
        if(v == start)
        {
            dist[v] = INF;
            vis[v] = false;
        }
        else if (cost[start][v] != INF)
        {
            dist[v] = cost[start][v];
            vis[v] = true;
            que[rear++] = v;
        }
        else
        {
            dist[v] = INF;
            vis[v] = false;
        }
    }

    while(front != rear)
    {
        int u = que[front++];
        vis[u] = false;
        if(front == maxn)
            front = 0;
        for(int v = 1; v <= n; v++)
        {
            if(dist[v] > dist[u] + cost[u][v])
            {
                dist[v] = dist[u] + cost[u][v];
                if(!vis[v])
                {
                    vis[v] = true;
                    que[rear++] = v;
                    if(rear == maxn)
                        rear = 0;
                }
            }
        }
    }
}

int main (void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d", &cost[i][j]);
        spfa(1, n);
        int ans = dist[n];
        int loop1 = dist[1];
        spfa(n, n);
        int loop2 = dist[n];
        ans = min(ans, loop1 + loop2);
        printf("%d\n", ans);
    }
    return 0;
}