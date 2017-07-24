//
// Created by 孙启龙 on 2017/5/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#define maxn 110
#define mem0(x) memset(x, 0, sizeof(x))
#define memI(x) memset(x, 0x3f, sizeof(x))
using namespace std;

vector<int>G[maxn];
stack<int>S;
int low[maxn], dfn[maxn], Bcnt, timee, belong[maxn], in[maxn], out[maxn];
bool instack[maxn];
int n, m;

void init_tarjan()
{
    Bcnt = timee = 0;
    mem0(low);
    mem0(dfn);
    mem0(belong);
    mem0(in);
    mem0(out);
    mem0(instack);
    for(int i = 0; i <= n; i++)
        G[i].clear();
    while(!S.empty())
        S.pop();
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
        int v;
        Bcnt++;
        do{
            v = S.top();
            S.pop();
            instack[v] = false;
            belong[v] = Bcnt;
        }while(u != v);
    }
}

void solve()
{
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);

    if(Bcnt == 1)
    {
        printf("1\n0\n");
        return;
    }
    int u, v;
    for(u = 1; u <= n; u++)
    {
        for(int i = 0; i < G[u].size(); i++)
        {
            v = G[u][i];
            if(belong[u] != belong[v])
            {
                in[belong[v]]++;
                out[belong[u]]++;
            }
        }
    }

    int intime = 0, outtime = 0;
    for(int i = 1; i <= Bcnt; i++)
    {
        if(in[i] == 0)
            intime++;
        if(out[i] == 0)
            outtime++;
    }
    printf("%d\n%d\n", intime, max(intime, outtime));
    return;
}

int main (void)
{
    while(scanf("%d",&n) != EOF)
    {
        init_tarjan();
        int u, v;
        for(u = 1; u <= n; u++)
        {
            while(scanf("%d", &v), v)
                G[u].push_back(v);
        }
        solve();
    }
    return 0;
}