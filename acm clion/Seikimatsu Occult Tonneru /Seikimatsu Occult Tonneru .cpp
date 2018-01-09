//
// Created by 孙启龙 on 2017/10/18.
//

#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
#define maxn 1111
#define maxm 1111111
#define INF 0x3f3f3f3f
int head[maxn], cur[maxn], d[maxn], st[maxm], s, e, no, n;

struct point {
    int u, v, flow, next;

    point() {
    };

    point(int x, int y, int z, int w) : u(x), v(y), next(z), flow(w) {
    };
} p[maxm];

void add(int x, int y, int z) {
    p[no] = point(x, y, head[x], z);
    head[x] = no++;
    p[no] = point(y, x, head[y], 0);
    head[y] = no++;
}

void init() {
    memset(head, -1, sizeof(head));
    no = 0;
}

bool bfs() {
    int i, x, y;
    queue<int> q;
    memset(d, -1, sizeof(d));
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (i = head[x]; i != -1; i = p[i].next) {
            if (p[i].flow && d[y = p[i].v] < 0) {
                d[y] = d[x] + 1;
                if (y == e)
                    return true;
                q.push(y);
            }
        }
    }
    return false;
}

int dinic() {
    int i, loc, top, x = s, nowflow, maxflow = 0;
    while (bfs()) {
        for (i = s; i <= e; i++)
            cur[i] = head[i];
        top = 0;
        while (true) {
            if (x == e) {
                nowflow = INF;
                for (i = 0; i < top; i++) {
                    if (nowflow > p[st[i]].flow) {
                        nowflow = p[st[i]].flow;
                        loc = i;
                    }
                }
                for (i = 0; i < top; i++) {
                    p[st[i]].flow -= nowflow;
                    p[st[i] ^ 1].flow += nowflow;
                }
                maxflow += nowflow;
                top = loc;
                x = p[st[top]].u;
            }
            for (i = cur[x]; i != -1; i = p[i].next)
                if (p[i].flow && d[p[i].v] == d[x] + 1)
                    break;
            cur[x] = i;
            if (i != -1) {
                st[top++] = i;
                x = p[i].v;
            } else {
                if (!top)
                    break;
                d[x] = -1;
                x = p[st[--top]].u;
            }
        }
    }
    return maxflow;
}

int N, M, num[maxn], U[maxn], V[maxn], W[maxn], P[maxn];

int main(void)
{
    while(scanf("%d %d", &N, &M) != EOF)
    {
        for(int i = 1; i <= N; i++)
            scanf("%d", &num[i]);
        int k = 0;
        int flag = 0;
        for(int i = 1; i <= M; i++)
        {
            scanf("%d %d %d %d", &U[i], &V[i], &W[i], &P[i]);
            if(P[i] > 0)
                k++;
            if(P[i] < 0)
                flag = 1;
        }
        if(!flag)
        {
            printf("Poor Heaven Empire\n");
            continue;
        }
        int ans = 0;
        int cost = 0;
        for(int i = 0; i < (1 << k); i++)
        {
            init();
            s = 0;
            e = N + 1;
            int tcost = 0;
            int temp = 0;
            for(int j = 1; j <= N; j++)
                add(s, j, num[j]);
            for(int j = 1; j <= M; j++)
            {
                if(P[j] < 0)
                {
                    add(U[j], V[j], INF);
                    add(U[j], e, W[j]);
                }
                if(P[j] == 0)
                    add(U[j], V[j], INF);
                if(P[j] > 0)
                {
                    if(i & (1 << temp))
                        add(U[j], V[j], INF), tcost += W[j];
                    else
                        add(U[j], V[j], 1);
                    temp++;
                }
            }
            int tans = dinic();
            if(tans > ans || (tans == ans && cost > tcost))
                ans = tans, cost = tcost;
        }
        if(ans == 0)
            printf("Poor Heaven Empire\n");
        else
            printf("%d %d\n", ans, cost);
    }
    return 0;
}