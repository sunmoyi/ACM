//
// Created by 孙启龙 on 2016/11/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 100010
#define INF 0x3f3f3f3f

using namespace std;

vector<int>Set[maxn];
vector<int>Belong[maxn];

struct node{
    long long d;
    int u;
    node(long long d = 0, int u = 0):d(d), u(u){}
    bool operator < (const node &a) const
    {
        return d > a.d;
    }
};

int n, m, Case = 1;
int num[maxn];
bool visnode[maxn], used[maxn];
long long d1[maxn], d2[maxn], dis[maxn];

void init()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        Belong[i].clear();
    for(int i = 0; i < m; i++)
        Set[i].clear();

    int t;
    for(int i = 0; i < m; i++)
    {
        scanf("%lld %d", &dis[i], &num[i]);
        for(int j = 0; j < num[i]; j++)
        {
            scanf("%d", &t);
            Set[i].push_back(t);
            Belong[t].push_back(i);
        }
    }
}

void Dijkstra(int s, long long *d)
{
    priority_queue<node>Q;
    for(int i = 1; i <= n; i++)
        d[i] = INF;
    d[s] = 0;
    memset(visnode, 0, sizeof(visnode));
    memset(used, 0, sizeof(used));
    Q.push(node(0, s));

    while(!Q.empty())
    {
        node x = Q.top();
        Q.pop();
        int u = x.u;
        if(visnode[u])
            continue;
        visnode[u] = true;

        for(int i = 0; i < Belong[u].size(); i++)
        {
            int v = Belong[u][i];
            if(used[v])
                continue;
            used[v] = true;
            for(int j = 0; j < num[v]; j++)
            {
                int vv = Set[v][j];
                if(vv == u)
                    continue;
                if(d[vv] > d[u] + dis[v])
                {
                    d[vv] = d[u] + dis[v];
                    Q.push(node(d[vv], vv));
                }
            }
        }
    }
}

void solve()
{
    Dijkstra(1, d1);
    Dijkstra(n, d2);

    long long ans = INF;
    for(int i = 1; i <= n; i++)
        ans = min(ans, max(d1[i], d2[i]));

    if(ans == INF)
        printf("Case #%d: Evil John\n", Case++);
    else
    {
        printf("Case #%d: %lld\n", Case++, ans);
        bool flag = false;
        for(int i = 1; i <= n; i++)
        {
            if(ans == max(d1[i], d2[i]))
            {
                if(flag)
                    printf(" ");
                printf("%d", i);
                flag = true;
            }
        }
        printf("\n");
    }
}

int main ()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        init();
        solve();
    }
    return 0;
}