//
// Created by 孙启龙 on 16/10/23.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 210
#define maxm 20410
#define INF 0x3f3f3f3f
#define abs(a) ((a) > 0? (a):(-(a)))
using namespace std;

int n, m, first[maxn], e, nextt[maxm], v[maxm], flow[maxm], cost[maxm];
int dis[maxn], pre[maxn], vis[maxn], sum[maxn];

struct Point{
    int x, y, z;
}p[maxn];

int distance(int i, int j)
{
    return abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y) + 1;
}

void add(int x, int y, int f, int c)
{
    v[e] = y, flow[e] = f, cost[e] = c;
    nextt[e] = first[x], first[x] = e++;
}

void init()
{
    int x;
    memset(first, -1, sizeof(first)), e = 0;
    for(int i = 0; i < n + m; i++)
        scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &x), sum[j] += x;
            add(i, n + j, INF - x, distance(i, n + j));
            add(n + j, i, x, -distance(i, n + j));
        }
    }
    for(int i = 0; i < m; i++)
        add(n + i, n + m, p[n + i].z - sum[i], 0), add(n + m, n + i, sum[i], 0);
}

int dfs(int cur, int &x)
{
    int i = pre[cur];
    if(i == -1 || vis[cur] == 1)
        return 0;
    if(vis[cur] == -1)
    {
        x = cur;
        return 1;
    }
    vis[cur] = -1;
    if(dfs(v[i ^ 1], x))
        return 1;
    vis[cur] = 1;
    return 0;
}

void print()
{
    int i, j, x;
    memset(vis, 0, sizeof(vis[0]) * (n + m + 1));
    for(i = 0; i <= n + m; i ++)
        if(!vis[i] && dfs(i, x))
            break;
    for(i = pre[x]; ; i = pre[v[i ^ 1]])
    {
        flow[i] -= 1, flow[i ^ 1] += 1;
        if(v[i ^ 1] == x)
            break;
    }
    printf("SUBOPTIMAL\n");
    for(i = 0; i < n; i ++)
    {
        printf("%d", flow[i * m * 2 + 1]);
        for(j = 1; j < m; j ++)
            printf(" %d", flow[(i * m + j) * 2 + 1]);
        printf("\n");
    }
}

void solve()
{
    int i, j, flag;
    memset(dis, 0, sizeof(dis[0]) * (n + m + 1));
    memset(pre, -1, sizeof(pre[0]) * (n + m + 1));
    for(i = 0; i <= n + m; i ++)
    {
        flag = 0;
        for(j = 0; j < e; j ++)
            if(flow[j] && dis[v[j]] > dis[v[j ^ 1]] + cost[j])
                dis[v[j]] = dis[v[j ^ 1]] + cost[j], pre[v[j]] = j, flag = 1;
        if(flag == 0)
            break;
    }
    if(i > n + m)
        print();
    else
        printf("OPTIMAL\n");
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        init();
        solve();
    }
    return 0;
}