//
// Created by 孙启龙 on 2017/3/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 310
#define INF 1e30f

using namespace std;

struct Node{
    double x, y;
}node[maxn];
bool vis[maxn];
double dist[maxn];
double cost[maxn][maxn];

double dis(Node a, Node b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void Dijkstra(int n, int start)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        vis[i] = false;
    }
    dist[start] = 0;
    for (int j = 0; j<n; j++)
    {
        int k = -1;
        double Min = INF;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && dist[i]<Min)
            {
                Min = dist[i];
                k = i;
            }
        }

        if (k == -1)
            break;

        vis[k] = true;
        for (int i = 1; i <= n; i++)
            if (!vis[i] && dist[k] + cost[k][i]<dist[i])
                dist[i] = dist[k] + cost[k][i];
    }
}

int main()
{
    double v1 = 10000.0 / 60;
    double v2 = 40000.0 / 60;
    while (scanf("%lf%lf%lf%lf", &node[1].x, &node[1].y, &node[2].x, &node[2].y) == 4)
    {
        int n = 2;
        int cnt1 = 3;
        int x, y;
        for (int i = 1; i<300; i++)
        {
            for (int j = 1; j<300; j++)
            {
                if (i == j)
                    cost[i][j] = 0;
                else
                    cost[i][j] = INF;
            }
        }
        while (scanf("%d%d", &x, &y) == 2)
        {
            if (x == -1 && y == -1)
            {
                cnt1 = n + 1;
                continue;
            }
            n++;
            node[n].x = x;
            node[n].y = y;
            if (n != cnt1)
                cost[n][n - 1] = cost[n - 1][n] = min(cost[n][n - 1], dis(node[n], node[n - 1]) / v2);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cost[i][j] = min(cost[i][j], dis(node[i], node[j]) / v1);
        Dijkstra(n, 1);
        printf("%.0lf\n", (dist[2]));
    }
    return 0;
}