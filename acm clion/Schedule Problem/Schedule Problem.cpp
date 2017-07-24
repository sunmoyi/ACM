//
// Created by 孙启龙 on 2017/5/5.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include<queue>
#define maxn 1005
#define maxm maxn * maxn
#define INF 0xfffffff

using namespace std;

struct node {
    int v, w, next;
}edge[maxm];

int head[maxn], tol;
int mindist[maxn], D[maxn], cnt[maxn];
bool vis[maxn];
int ans;

void addedge(int u, int v, int w)
{
    edge[tol].v = v;
    edge[tol].w = w;
    edge[tol].next = head[u];
    head[u] = tol++;
}

bool spfa(int n)
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i <= n; i++)
        mindist[i] = -INF;
    vis[0] = true;
    mindist[0] = 0;
    queue<int>Q;
    while (!Q.empty())
        Q.pop();
    Q.push(0);
    memset(cnt, 0, sizeof(cnt));
    cnt[0]++;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if (mindist[v] < mindist[u] + w)
            {
                mindist[v] = mindist[u] + w;
                if (!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                    if (++cnt[v] > n)
                        return false;
                }
            }
        }
    }
    return true;
}

int main(void)
{
    char str[5]; int u, v; int casee = 1;
    while (scanf("%d", &ans) != EOF && ans)
    {
        memset(head, -1, sizeof(head));
        tol = 0;

        for (int i = 1; i <= ans; i++)
            scanf("%d", &D[i]);
        while (scanf("%s", str, 4))
        {
            if (str[0] == '#')
                break;
            scanf("%d %d", &u, &v);
            if (strcmp(str, "SAS") == 0)
                addedge(v, u, 0);
            else if (strcmp(str, "SAF") == 0)
                addedge(v, u, D[v]);
            else if (strcmp(str, "FAF") == 0)
                addedge(v, u, D[v] - D[u]);
            else
                addedge(v, u, -D[u]);
        }
        for (int i = 1; i <= ans; i++)
            addedge(0, i, 0);

        printf("Case %d:\n", casee++);
        if (!spfa(ans))
            printf("impossible\n");
        else
        {
            for (int i = 1; i <= ans; i++)
            {
                printf("%d %d\n", i, mindist[i]);
            }
        }
        printf("\n");
    }
    return 0;
}