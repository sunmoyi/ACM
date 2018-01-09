//
// Created by 孙启龙 on 2017/10/16.
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
    int v, val, next;
}p[maxn];
struct node{
    int x;
    long long step;
    node(int x = 0, long long step = 0): x(x), step(step){}
    bool operator < (const node &rhs) const{
        return step > rhs.step;
    }
};

int head[maxn], len, a[maxn], mark[maxn];
long long vis[maxn];
priority_queue<node>Q;

void addedge(int u, int v, int val)
{
    p[len].v = v;
    p[len].val = val;
    p[len].next = head[u];
    head[u] = len++;
}

long long Dijkstra()
{
    while(!Q.empty())
    {
        node now = Q.top();
        Q.pop();
        if(mark[now.x])
            return now.step;
        for(int i = head[now.x]; i != -1; i = p[i].next)
        {
            int next = p[i].v;
            if(vis[next] > now.step + p[i].val)
                vis[next] = now.step + p[i].val, Q.push(node(next, vis[next]));
        }
    }
    return INF;
}

void init()
{
    memset(vis, 0x3f, sizeof(vis));
    memset(mark, 0, sizeof(mark));
    while(!Q.empty())
        Q.pop();
}

long long solve(int k)
{
    long long ans = 1LL << 50;
    for(int i = 1; i < 20; i++)
    {
        init();
        for(int j = 0; j < k; j++)
        {
            if(a[j] & (1 << i))
                Q.push(node(a[j], 0)), vis[a[j]] = 0;
            else
                mark[a[j]] = 1;
        }
        ans = min(ans, Dijkstra());

        init();
        for(int j = 0; j < k; j++)
        {
            if(a[j] & (1 << i))
                mark[a[j]] = 1;
            else
                Q.push(node(a[j], 0)), vis[a[j]] = 0;
        }
        ans = min(ans, Dijkstra());
    }
    return ans;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        memset(head, -1, sizeof(head));
        len = 0;
        int n, m;
        scanf("%d %d", &n, &m);
        while(m--)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
        }
        int k;
        scanf("%d", &k);
        for(int i = 0; i < k; i++)
            scanf("%d", &a[i]);
        printf("Case #%d: %lld\n", Case, solve(k));
    }
    return 0;
}