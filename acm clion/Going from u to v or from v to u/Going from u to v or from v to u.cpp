//
// Created by 孙启龙 on 2017/5/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define maxn 1010

using namespace std;

vector<int>G[maxn];
vector<int>E[maxn];
stack<int>S;
queue<int>Q;
int n, tot;
int dfn[maxn], low[maxn], belong[maxn], in[maxn], Bcnt, timee;
bool instack[maxn];

void init_tarjan()
{
    Bcnt = timee = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(belong, 0, sizeof(belong));
    memset(in, 0, sizeof(in));
    memset(instack, false, sizeof(instack));
    for(int i = 0; i <= n; i++)
    {
        G[i].clear();
        E[i].clear();
    }
    if(!S.empty())
        S.pop();
    if(!Q.empty())
        Q.pop();
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++timee;
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

bool topsort()
{
    int count = 0;
    for(int i = 1; i <= Bcnt; i++)
        if(in[i] == 0)
            count++, Q.push(i);
    if(count > 1)
        return false;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        count = 0;
        for(int i = 0; i < E[u].size(); i++)
        {
            int v = E[u][i];
            in[v]--;
            if(in[v] == 0)
                count++, Q.push(v);
        }
        if(count > 1)
            return false;
    }
    return true;
}

void solve()
{
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);

    for(int u = 1; u <= n; u++)
    {
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(belong[u] != belong[v])
            {
                in[v]++;
                E[u].push_back(v);
            }
        }
    }
    if(topsort())
        printf("Yes\n");
    else
        printf("No\n");
}

int main (void)
{
    int T, u, v;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &tot);
        init_tarjan();
        while(tot--)
        {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
        }
        solve();
    }
    return 0;
}