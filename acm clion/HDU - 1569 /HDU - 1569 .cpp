//
// Created by 孙启龙 on 2017/10/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

#define MAXN 3005
#define MAXM 500005
#define oo 1000000007
#define ll long long
using namespace std;

struct Dinic {
    struct node {
        int x, y, c, next;
    } line[MAXM];
    int Lnum, _next[MAXN], dis[MAXN];

    void initial(int n) {
        for (int i = 0; i <= n; i++)
            _next[i] = -1;
        Lnum = -1;
    }

    void addline(int x, int y, int c) {
        line[++Lnum].next = _next[x], _next[x] = Lnum;
        line[Lnum].x = x, line[Lnum].y = y, line[Lnum].c = c;
        line[++Lnum].next = _next[y], _next[y] = Lnum;
        line[Lnum].x = y, line[Lnum].y = x, line[Lnum].c = 0;
    }

    bool BFS(int s, int e) {
        queue<int> Q;
        while (!Q.empty())
            Q.pop();
        memset(dis, 0, sizeof(dis));
        dis[s] = 1;
        Q.push(s);
        while (!Q.empty()) {
            int h, k;
            h = Q.front(), Q.pop();
            if (h == e)
                return dis[e];
            for (k = _next[h]; k != -1; k = line[k].next)
                if (line[k].c && !dis[line[k].y])
                    dis[line[k].y] = dis[h] + 1, Q.push(line[k].y);
        }
        return false;
    }

    int dfs(int x, int flow, int e) {
        if (x == e)
            return flow;
        int temp, cost = 0;
        for (int k = _next[x]; k != -1; k = line[k].next)
            if (line[k].c && dis[line[k].y] == dis[x] + 1) {
                temp = dfs(line[k].y, min(flow - cost, line[k].c), e);
                if (temp) {
                    line[k].c -= temp, line[k ^ 1].c += temp;
                    cost += temp;
                    if (flow == cost)
                        return cost;
                } else
                    dis[line[k].y] = -1;
            }
        return cost;
    }

    int MaxFlow(int s, int e) {
        int MaxFlow = 0;
        while (BFS(s, e))
            MaxFlow += dfs(s, oo, e);
        return MaxFlow;
    }
}dinic;

int main (void)
{
    int R, C, s, e, v,sum;
    while(scanf("%d %d", &R, &C) != EOF)
    {
        dinic.initial(R * C + 5);
        s = R * C + 1, e = R * C + 2, sum = 0;
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                scanf("%d", &v);
                sum += v;
                if((i + j) % 2)
                {
                    dinic.addline(s, i * C + j, v);
                    if(i)
                        dinic.addline(i * C + j, (i - 1) * C + j, oo);
                    if(j)
                        dinic.addline(i * C + j, i * C + j - 1, oo);
                    if(i != R - 1)
                        dinic.addline(i * C + j, (i + 1) * C + j, oo);
                    if(j != C - 1)
                        dinic.addline(i * C + j, i * C + j + 1, oo);
                }
                else
                    dinic.addline(i * C + j, e, v);
            }
        }
        printf("%d\n", sum - dinic.MaxFlow(s, e));
    }
    return 0;
}