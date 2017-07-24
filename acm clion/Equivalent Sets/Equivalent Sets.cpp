//
// Created by 孙启龙 on 2017/5/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#define maxn 200010

using namespace std;

vector<int>G[maxn];
int n, m, Bcnt, timee;
int low[maxn], dfn[maxn], belong[maxn], in[maxn], out[maxn];
bool insatck[maxn];
stack<int>S;
int sum1, sum2;

void init_tarjan()
{
    Bcnt = timee = 0;
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(belong, 0, sizeof(belong));
    sum1 = sum2 = 0;
    for(int i = 1; i <= n; i++)
        G[i].clear();
}

void tarjan(int u)
{
    low[u] = dfn[u] = ++timee;
    S.push(u);
    insatck[u] = true;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (insatck[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        Bcnt++;
        int v;
        do{
            v = S.top();
            S.pop();
            insatck[v] = false;
            belong[v] = Bcnt;
        }while(u != v);
    }
}

int main (void)
{

    while(scanf("%d %d", &n, &m) != EOF)
    {
        init_tarjan();
        int u, v;
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
        }


        for(int i = 1; i <= n; i++)
            if(!dfn[i])
                tarjan(i);


        if(Bcnt == 1)
        {
            printf("0\n");
            continue;
        }
        for(u = 1; u <= n; u++)
        {
            for(int i = 0; i < G[u].size(); i++)
            {
                v = G[u][i];
                if(belong[u] != belong[v])
                    in[belong[u]]++, out[belong[v]]++;
            }
        }
        for(int i = 1; i <= Bcnt; i++)
        {
            if(in[i] == 0)
                sum1++;
            if(out[i] == 0)
                sum2++;
        }
        printf("%d\n", max(sum1, sum2));
    }
    return 0;
}