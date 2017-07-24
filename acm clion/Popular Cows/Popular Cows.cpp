//
// Created by 孙启龙 on 2017/5/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#define maxn 20010
#define maxm 100010

using namespace std;

vector<int>G[maxn];
stack<int>S;
int n, m;
int low[maxn], dfn[maxn], timee, Bcnt, out[maxn], belong[maxn];
bool instack[maxn];

void init_tarjan()
{
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(out, 0, sizeof(out));
    memset(belong, 0, sizeof(belong));
    memset(instack, false, sizeof(instack));
    Bcnt = timee = 0;
    for(int i = 1; i <= n; i++)
        G[i].clear();
}

void tarjan(int u)
{
    low[u] = dfn[u] = ++timee;
    S.push(u);
    instack[u] = true;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instack[v])
           low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u])
    {
        Bcnt++;
        int v;
        do{
            v = S.top();
            S.pop();
            instack[v] = false;
            belong[v] = Bcnt;
        }while(v != u);
    }
}

void solve()
{
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);

    int u, v;
    for(u = 1; u <= n; u++)
    {
        for(int i = 0; i < G[u].size(); i++)
        {
            v = G[u][i];
            if(belong[u] != belong[v])
                out[belong[u]]++;
        }
    }

    int sum = 0, pos = -1;
    for(int i = 1; i <= Bcnt; i++)
        if(out[i] == 0)
            sum++, pos = i;
    if(sum > 1)
        printf("0\n");
    else
    {
        sum = 0;
        for(int i = 1; i <= n; i++)
            if(belong[i] == pos)
                sum++;
        printf("%d\n", sum);
    }
}

int main(void)
{
    int u, v;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        init_tarjan();
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
        }
        solve();
    }
    return 0;
}