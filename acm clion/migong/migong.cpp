//
// Created by 孙启龙 on 2017/5/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>

#define maxn 10010

using namespace std;

int n;
vector<int>G[maxn];
int Bcnt;
int Top;
int Index;
int low[maxn], dfn[maxn];
int belong[maxn], stack[maxn];
bool instack[maxn];

void init_tarjan()
{
    Bcnt = Top = Index = 0;
    for(int i = 1; i <= n; i++)
    {
        low[i] = dfn[i] = 0;
        G[i].clear();
    }
}

void tarjan(int u)
{
    stack[Top++] = u;
    instack[u] = true;
    low[u] = dfn[u] = ++Index;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        }
        else if (instack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u])
    {
        ++Bcnt;
        int v;
        do{
            v = stack[--Top];
            instack[v] = false;
            belong[v] = Bcnt;
        }while(u != v);
    }
}

int main(void)
{
    int m;
    while(cin >> n >> m, n + m)
    {
        init_tarjan();
        while(m--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
        }

        for(int i = 1; i <= n; i++)
            if(!dfn[i])
                tarjan(i);

        printf("%s\n", Bcnt == 1? "Yes": "No");
    }
    return 0;
}