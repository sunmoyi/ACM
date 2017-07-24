//
// Created by 孙启龙 on 2017/7/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define maxm 26

using namespace std;

struct DFA{
    int n, g[maxn][maxm];
    bool ac[maxn];

    void init()
    {
        int m, k, u, v;
        char c[5];

        scanf("%d %d %d", &n, &m, &k);
        memset(ac, false, sizeof(ac));
        for(int i = 0; i <= n; i++)
            for(int j = 0; j < maxm; j++)
                g[i][j] = n;

        while(k--)
        {
            scanf("%d", &u);
            ac[u] = true;
        }

        while(m--)
        {
            scanf("%d %d %s", &u, &v, c);
            g[u][c[0] - 'a'] = v;
        }
    }
}A, B;

struct State{
    int u, v, p, w;
    State(int u = 0, int v = 0, int p = 0, int w = 0):u(u), v(v), p(p), w(w){}
}Q[maxn * maxn];

bool vis[maxn][maxn];

void put(int x)
{
    if(x > 0)
    {
        put(Q[x].p);
        printf("%c", Q[x].w + 'a');
    }
}

bool solve()
{
    if(A.ac[0] ^ B.ac[0])
        return true;

    memset(vis, false, sizeof(vis));
    int head = 0, rear = 0;

    Q[rear++] = State(0, 0, -1, 0);
    vis[0][0] = true;

    while(head < rear)
    {
        State & cur = Q[head++];
        for(int i = 0; i < maxm; i++)
        {
            int u = A.g[cur.u][i];
            int v = B.g[cur.v][i];
            if(vis[u][v])
                continue;
            vis[u][v] = true;
            Q[rear++] = State(u, v, head - 1, i);

            if(A.ac[u] ^ B.ac[v])
            {
                put(rear - 1);
                return true;
            }
        }
    }
    return false;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        A.init();
        B.init();
        printf("Case #%d: ", Case);
        if(!solve())
            printf("0\n");
        else
            printf("\n");
    }
    return 0;
}