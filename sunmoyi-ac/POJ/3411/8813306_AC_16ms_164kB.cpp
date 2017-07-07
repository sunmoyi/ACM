//
// Created by 孙启龙 on 2017/4/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20
#define INF 0x3f3f3f3f

using namespace std;

int vis[maxn];
int n, m;
int min_cost;
struct node{
    int a, b, c, p, r;
}e[maxn];

void dfs(int x, int fee)
{
    if(x == n)
    {
        min_cost = min(min_cost, fee);
        return;
    }
    for(int i = 1; i <= m; i++)
    {
        if(e[i].a == x && vis[e[i].b] <= 2)
        {
            vis[e[i].b]++;
            if(vis[e[i].c])
                dfs(e[i].b, fee + e[i].p);
            else
                dfs(e[i].b, fee + e[i].r);
            vis[e[i].b]--;
        }
    }
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        min_cost = INF;
        for(int i = 1; i <= m; i++)
            scanf("%d %d %d %d %d", &e[i].a, &e[i].b, &e[i].c, &e[i].p, &e[i].r);
        vis[1] = 1;
        dfs(1, 0);
        if(min_cost != INF)
            printf("%d\n", min_cost);
        else
            printf("impossible\n");
    }
    return 0;
}
