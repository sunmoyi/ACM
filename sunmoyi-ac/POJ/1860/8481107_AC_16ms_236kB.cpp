//
// Created by 孙启龙 on 2017/3/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1010

using namespace std;

struct node {
    int v;
    double rate;
    double occ;
    node(int v = 0, double rate = 0, double occ = 0) : v(v), rate(rate), occ(occ) {}
    bool friend operator < (const node&a, const node&b)
    {
        return a.rate < b.rate;
    }
};

bool inqueue[maxn];
vector<node>G[maxn];
double maxx[maxn];
int start;
double money;
int V, E;

void init(void)
{
    for (int i = 1; i < maxn; i++)
    {
        inqueue[i] = false;
        G[i].clear();
        maxx[i] = 0;
    }
}

bool Dijkstra(void)
{
    queue<node>Q;
    for (int i = 0; i < G[start].size(); i++)
    {
        int vex = G[start][i].v;
        Q.push(G[start][i]);
        maxx[vex] = max(maxx[vex], (maxx[start] - G[start][i].occ) * G[start][i].rate);
        inqueue[vex] = true;
    }
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        inqueue[now.v] = false;
        for (int i = 0; i < G[now.v].size(); i++)
        {
            int vex = G[now.v][i].v;
            double moneyy = (maxx[now.v] - G[now.v][i].occ) * G[now.v][i].rate;
            if (moneyy > maxx[vex])
            {
                maxx[vex] = moneyy;
                if (maxx[start] > money)
                    return true;
                if (!inqueue[vex])
                {
                    inqueue[vex] = true;
                    Q.push(G[now.v][i]);
                }
            }
        }
    }
    return false;
}

int main(void)
{
    int a, b;
    double rate1, occ1, rate2, occ2;
    while (scanf("%d %d %d %lf", &V, &E, &start, &money) != EOF)
    {
        init();
        maxx[start] = money;
        for (int i = 1; i <= E; i++)
        {
            scanf("%d %d", &a, &b);
            scanf("%lf %lf %lf %lf", &rate1, &occ1, &rate2, &occ2);
            G[a].push_back(node(b, rate1, occ1));
            G[b].push_back(node(a, rate2, occ2));
        }
        if (Dijkstra())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}