//
// Created by 孙启龙 on 2017/3/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 30010
#define maxm 200010
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int v, len, next;
}edge[maxm];
int inqueue[maxn];
int head[maxn];
int Q[maxn];
int mindist[maxn];
int n, m;
int tot, top;

inline void addedge(int u, int v, int len)
{
    edge[tot].v = v;
    edge[tot].len = len;
    edge[tot].next = head[u];
    head[u] = tot++;
}

int SPFA(int S, int T)
{
    top = 0;
    for(int v = 1; v <= n; v++)
    {
        if(v == S)
        {
            mindist[S] = 0;
            inqueue[v] = true;
            Q[top++] = v;
        }
        else
        {
            mindist[v] = INF;
            inqueue[v] = false;
        }
    }
    while(top != 0)
    {
        int u = Q[--top];
        inqueue[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if(mindist[v] > mindist[u] + edge[i].len)
            {
                mindist[v] = mindist[u] + edge[i].len;
                if(!inqueue[v])
                {
                    inqueue[v] = true;
                    Q[top++] = v;
                }
            }
        }
    }
    return mindist[T];
}

int main (void)
{
    int u, v, len;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        tot = 0;
        memset(head, -1, sizeof(head));
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &u, &v, &len);
            addedge(u, v, len);
        }
        int ans = SPFA(1, n);
        printf("%d\n", ans);
    }
    return 0;
}