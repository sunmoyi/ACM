//
// Created by 孙启龙 on 2017/3/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define maxn 100010
#define maxm 110
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int u, v, len, next;
}e[maxn];

int dis[maxn], head[maxn];
bool use[maxn];

void Add(int u, int v, int len, int k)
{
    e[k].u = u;
    e[k].v = v;
    e[k].len = len;
    e[k].next = head[u];
    head[u] = k;
}

void spfa(int s)
{
    stack<int>sta;
    sta.push(s);

    while(sta.size())
    {
        int i = sta.top();
        sta.pop();
        use[i] = false;

        for(int j = head[i]; j != 0; j = e[j].next)
        {
            int u = e[j].u, v = e[j].v, len = e[j].len;
            if(dis[u] + len < dis[v])
            {
                dis[v] = dis[u] + len;
                if(!use[v])
                {
                    use[v] = true;
                    sta.push(v);
                }
            }
        }
    }
}

int main (void)
{
    int N, A, B;

    while(scanf("%d %d %d", &N, &A, &B) != EOF)
    {
        int i, j, k = 1;

        memset(head, 0, sizeof(head));
        for(i = 1; i <= N; i++)
        {
            int M, V;
            dis[i] = INF;
            scanf("%d %d", &M, &V);

            Add(i, V, 0, k++);
            for(j = 1; j < M; j++)
            {
                scanf("%d", &V);
                Add(i, V, 1, k++);
            }
        }

        dis[A] = 0;
        spfa(A);
        if(dis[B] == INF)
            printf("-1\n");
        else
            printf("%d\n", dis[B]);
    }
    return 0;
}

