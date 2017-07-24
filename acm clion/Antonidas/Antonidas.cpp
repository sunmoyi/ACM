//
// Created by 孙启龙 on 2017/7/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>
#include <queue>

#define maxn 10010

using namespace std;

struct State{
    int u, f, p;
    State(int u = 0, int f = 0, int p = 0): u(u), f(f), p(p){}
};

int N, E, first[maxn], jump[maxn << 1], val[maxn << 1];
int far[maxn], dep[maxn];
char S[maxn], C[maxn];

void addedge(int u, int v)
{
    jump[E] = first[u];
    val[E] = v;
    first[u] = E++;
}

int dfs(int u, int f)
{
    far[u] = f;
    int d = 0;
    for(int i = first[u]; i != -1; i = jump[i])
    {
        int v = val[i];
        if(v == f)
            continue;
        d = max(dfs(v, u), d);
    }
    return dep[u] = d + 1;
}

void init()
{
    int u, v;
    E = 0;
    memset(first, -1, sizeof(first));
    scanf("%d", &N);
    for(int i = 1; i < N; i++)
    {
        scanf("%d %d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    scanf("%s", S + 1);
    dfs(1, 0);
}

bool judge()
{
    scanf("%s", C + 1);
    int n = (int)strlen(C + 1);
    queue<State>Q;

    for(int i = 1; i <= N; i++)
        if(S[i] == C[1])
            Q.push(State(i, 0, 1));

    int cnt = 0;
    while(!Q.empty())
    {
        State cur = Q.front();
        Q.pop();
        int u = cur.u, f = cur.f, p = cur.p;

        if(f == far[u] && n - p >= dep[u])
            continue;

        for(int i = first[u]; i != -1; i = jump[i])
        {
            int v = val[i];
            if(v == f || S[v] != C[p + 1])
                continue;
            if(p + 1 == n)
                return true;
            Q.push(State(v, u, p + 1));
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
        init();
        printf("Case #%d: %s\n", Case, judge()? "Find" : "Impossible");
    }
    return 0;
}