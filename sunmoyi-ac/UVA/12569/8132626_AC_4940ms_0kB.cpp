//
// Created by 孙启龙 on 2017/2/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 15
#define maxstate (1 << maxn) * maxn + 10

using namespace std;

int n, m, s, t;
int fa[maxstate], dist[maxstate];
bool vis[1 << maxn][maxn], g[maxn][maxn];

typedef int go[2];
typedef int state[2];

state st[maxstate];
go k[maxstate];

void read()
{
    memset(g,0,sizeof(g));
    memset(k,0,sizeof(k));
    memset(fa,0,sizeof(fa));
    memset(st,0,sizeof(st));
    memset(vis,0,sizeof(vis));
    memset(dist,0,sizeof(dist));
    scanf("%d %d %d %d", &n, &m, &s, &t);
    st[1][1] =  s - 1, st[1][0] = 1 << (s - 1);
    for(int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);
        st[1][0] |= 1 << (k - 1);
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u - 1][v - 1] = g[v - 1][u - 1] = true;
    }
}

int bfs()
{
    int front = 1, rear = 2;
    while(front < rear)
    {
        state &s = st[front];
        if(s[1] == t - 1)
            return front;
        for(int i = 0; i < n; i++)
        {
            if(!(s[0] & (1 << i)))
                continue;
            for(int j = 0; j < n; j++)
            {
                if((s[0] & (1 << j)) || !g[i][j])
                    continue;
                state &t = st[rear];
                memcpy(&t, &s, sizeof(s));
                if(s[1] == i)
                    t[1] = j;
                t[0] ^= 1 << i | 1 << j;
                k[rear][0] = i + 1, k[rear][1] = j + 1;
                dist[rear] = dist[front] + 1, fa[rear] = front;
                if(!vis[t[0]][t[1]])
                    vis[t[0]][t[1]] = true, ++rear;
            }
        }
        ++front;
    }
    return 0;
}

void print_ans(int a)
{
    if(!fa[a])
        return;
    print_ans(fa[a]);
    printf("%d %d\n", k[a][0], k[a][1]);
    return;
}

int main (void)
{
    int t, tt = 0;
    scanf("%d", &t);
    while(t--)
    {
        read();
        int a = bfs();
        printf("Case %d: %d\n",++tt,a?dist[a]:-1);
        print_ans(a);
        printf("\n");
    }
    return 0;
}