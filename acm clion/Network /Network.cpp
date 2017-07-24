//
// Created by 孙启龙 on 2017/5/2.
//

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 100000 + 10;
int low[maxn],pre[maxn], dfs_clock=0, belong[maxn], Bcnt;
bool isbridge[maxn];
bool instack[maxn];
stack<int>S;
vector<int>G[maxn];
int cnt_bridge;
int father[maxn];

void dfs(int u, int fa)
{
    father[u]=fa;
    low[u] = pre[u] = ++dfs_clock;
    S.push(u);
    instack[u] = true;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(v == fa)
            continue;
        if(!pre[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > pre[u])
            {
                cnt_bridge++;
                isbridge[v] = true;
            }
        }
        else if (instack[v])
            low[u] = min(low[u], pre[v]);
    }
    if(low[u] == pre[u])
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

void init(int n)
{
    memset(isbridge,false,sizeof isbridge);
    memset(instack,false,sizeof instack);
    memset(belong,false,sizeof belong);
    Bcnt = 0;
    memset(pre,0,sizeof pre);
    cnt_bridge=dfs_clock=0;
    for(int i=0; i<n; i++)
        G[i].clear();
}

void LCA(int a,int b)
{
    while(pre[a]>pre[b])
    {
        if(isbridge[a])
        {
            isbridge[a]=false;
            cnt_bridge--;
        }
        a=father[a];
    }
    while(pre[b]>pre[a])
    {
        if(isbridge[b])
        {
            isbridge[b]=false;
            cnt_bridge--;
        }
        b=father[b];
    }
    if(a!=b)
    {
        while(pre[a]>pre[b])
        {
            if(isbridge[a])
            {
                isbridge[a]=false;
                cnt_bridge--;
            }
            a=father[a];
        }
        while(pre[b]>pre[a])
        {
            if(isbridge[b])
            {
                isbridge[b]=false;
                cnt_bridge--;
            }
            b=father[b];
        }
    }
}

int main()
{
    int n,m,Case=1;
    while(scanf("%d %d",&n,&m),!(n==0 && m==0))
    {
        init(n);
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            a--;
            b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        dfs(0,-1);
        int Q;
        cin>>Q;
        printf("Case %d:\n",Case++);
        while(Q--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            a--;
            b--;
            LCA(a,b);
            printf("%d\n",cnt_bridge);
            if(Q==0)
                printf("\n");
        }
    }

    return 0;
}