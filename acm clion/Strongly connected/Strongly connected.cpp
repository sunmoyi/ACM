//
// Created by 孙启龙 on 2017/5/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>

#define maxn 100010

using namespace std;

int dfn[maxn], low[maxn], belong[maxn], in[maxn], out[maxn];
int size[maxn];
int n, m, Bcnt, timee;
bool instack[maxn];
vector<int>G[maxn];
stack<int>S;

void init_tarjan()
{
    Bcnt = timee = 0;
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(belong, 0, sizeof(belong));
    memset(size, 0, sizeof(size));
    memset(instack, 0, sizeof(instack));
    for(int i = 0; i <= n + 1; i++)
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
    if(dfn[u] == low[u])
    {
        Bcnt++;
        int v;
        do{
            size[Bcnt]++;
            v = S.top();
            S.pop();
            instack[v] = false;
            belong[v] = Bcnt;
        }while(u != v);
    }
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        scanf("%d %d", &n, &m);
        init_tarjan();
        int u, v;
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            u--, v--;
            G[u].push_back(v);
        }

        for(int i = 0; i < n; i++)
            if(!dfn[i])
                tarjan(i);

        printf("Case %d: ", Case);
        if(Bcnt == 1)
        {
            printf("-1\n");
            continue;
        }
        for(u = 0; u < n; u++)
        {
            for(int i = 0; i < G[u].size(); i++)
            {
                v = G[u][i];
                if(belong[u] != belong[v])
                    in[belong[v]]++, out[belong[u]]++;
            }
        }
        int minn = 0x3f3f3f3f;
        for(int i = 1; i <= Bcnt; i++)
        {
            if(in[i] == 0 || out[i] == 0)
                minn = min(minn, size[i]);
        }
        long long ans = 0;
        ans = (long long)n * (long long)n - n - (long long)minn * (long long)(n - minn) - m;
        printf("%lld\n", ans);
    }
    return 0;
}