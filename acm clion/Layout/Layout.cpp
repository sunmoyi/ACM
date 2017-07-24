//
// Created by 孙启龙 on 2017/3/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define maxn 20020
#define INF 0x3f3f3f

using namespace std;

struct Edge{
    int to, len, next;
}edge[maxn];
int head[maxn], vis[maxn], cnt[maxn], que[maxn], dist[maxn];
int tot;

void addedge(int u, int v, int len)
{
    edge[tot].to = v;
    edge[tot].len = len;
    edge[tot].next = head[u];
    head[u] = tot++;
}

bool SPFA(int start, int n)
{
    int front = 0, rear = 0;
    for(int v = 1; v <= n; v++)
    {
        if(v == start)
        {
            que[rear++] = v;
            vis[v] = true;
            cnt[v] = 1;
            dist[v] =0;
        }
        else
        {
            vis[v] = false;
            dist[v] = INF;
        }
    }

    while(front != rear)
    {
        int u = que[front++];
        vis[u] = false;
        if(front == maxn)
            front = 0;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if(dist[v] > dist[u] + edge[i].len)
            {
                dist[v] = dist[u] + edge[i].len;
                if(!vis[v])
                {
                    if(++cnt[v] > n)
                        return false;
                    vis[v] = true;
                    que[rear++] = v;
                    if(rear == maxn)
                        rear = 0;
                }
            }
        }
    }
    return true;
}

int main (void)
{
    int n;
    int ml, md;
    int a, b, c;
    while(scanf("%d %d %d", &n, &ml, &md) != EOF)
    {
        tot = 0;
        memset(head, -1, sizeof(head));
        while(ml--)
        {
            scanf("%d %d %d", &a, &b, &c);
            if(a > b)
                swap(a, b);
            addedge(a, b, c);
        }
        while(md--)
        {
            scanf("%d %d %d", &a, &b, &c);
            if(a < b)
                swap(a, b);
            addedge(b, a, -c);
        }
        if(!SPFA(1, n))
            printf("-1\n");
        else if (dist[n] == INF)
            printf("-2\n");
        else
            printf("%d\n", dist[n]);
    }
    return 0;
}