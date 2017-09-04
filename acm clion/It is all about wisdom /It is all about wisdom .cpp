//
// Created by 孙启龙 on 2017/8/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 100010

using namespace std;

struct Edge{
    int to, next, cost, limit;
}edge[maxn << 1];
int mindist[maxn << 1], head[maxn << 1], num;
bool inqueue[maxn << 1];
int n, m, k, u, v, cost, limit;

void init()
{
    memset(head, -1, sizeof(head));
    num = 0;
}

bool check(int lim)
{
    memset(mindist, 0x3f, sizeof(mindist));
    memset(inqueue, false, sizeof(inqueue));
    queue<int>Q;
    Q.push(1);
    mindist[1] = 0, inqueue[1] = true;
    while(!Q.empty())
    {
        int now = Q.front(), next;
        Q.pop();
        inqueue[now] = false;
        for(int i = head[now]; i != -1; i = edge[i].next)
        {
            next = edge[i].to;
            if(mindist[next] > mindist[now] + edge[i].cost && edge[i].limit <= lim && mindist[now] + edge[i].cost < k)
            {
                mindist[next] = mindist[now] + edge[i].cost;
                if(next == n)
                    return true;
                if(!inqueue[next])
                {
                    inqueue[next] = true;
                    Q.push(next);
                }
            }
        }
    }
    return false;
}

int binarySearch()
{
    int l = 1, r = 1e9, mid;
    if(!check(r))
        return -1;
    while(l < r)
    {
        mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d %d", &u, &v ,&cost, &limit);
            edge[num] = Edge{v, head[u], cost, limit};
            head[u] = num++;
            edge[num] = Edge{u, head[v], cost, limit};
            head[v] = num++;
        }
        int ans = binarySearch();
        printf("%d\n", ans);
    }
    return 0;
}