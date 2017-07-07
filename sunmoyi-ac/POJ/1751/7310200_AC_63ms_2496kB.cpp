//
// Created by 孙启龙 on 16/10/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 800
#define INF 0x3f3f3f3f

using namespace std;

int n, m, dist[maxn][maxn], x[maxn], y[maxn], lowcost[maxn], pre[maxn];

void Prim()
{
    for(int i = 1; i <= n; i++)
    {
        lowcost[i] = dist[1][i];
        pre[i] = 1;
    }
    lowcost[1] = -1;
    int mini = INF, pos = -1;
    for(int i = 1; i < n; i++)
    {
        mini = INF;
        for(int j = 1; j <= n; j++)
        {
            if(lowcost[j] != -1 && lowcost[j] < mini)
            {
                pos = j;
                mini = lowcost[j];
            }
        }
        if(dist[pre[pos]][pos])
            printf("%d %d\n", pre[pos], pos);
        lowcost[pos] = -1;
        for(int j = 1; j <= n; j++)
        {
            if(lowcost[j] > dist[pos][j])
            {
                lowcost[j] = dist[pos][j];
                pre[j] = pos;
            }
        }
    }
}

int main ()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
            for(int j = 1; j < i; j++)
                dist[i][j] = dist[j][i] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            dist[i][i] = INF;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            dist[a][b] = dist[b][a] = 0 ;
        }
        Prim();
    }
    return 0;
}