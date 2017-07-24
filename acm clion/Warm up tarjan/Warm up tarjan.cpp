//
// Created by 孙启龙 on 2017/5/2.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXM = 1e6+1e6+7;
const int M= 1e6+7;
const int MAXN = 200007;
int head[MAXN],h[MAXN],Index;
struct node
{
    int v,vis;
    int next;
}edge[MAXM];
vector<int> e[MAXN];
void add(int u, int v)
{
    edge[Index].vis=0;
    edge[Index].v=v;
    edge[Index].next=head[u];
    head[u]=Index++;
}
int low[MAXN],DFN[MAXN],belong[MAXN];
int stack_[MAXN],top;
bool in_stack[MAXN];
int dps,cir;
void Tarjan(int u)
{
    in_stack[u]=1;
    low[u]=DFN[u]=++dps;
    stack_[top++]=u;
    for(int i=head[u]; i+1; i=edge[i].next)
    {
        int v=edge[i].v;
        if(edge[i].vis)
            continue;
        edge[i].vis=edge[i^1].vis=1;
        if(!DFN[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(in_stack[v] && edge[i^1].v)
            low[u]=min(low[u],DFN[v]);
    }
    int p;
    if(low[u]==DFN[u])
    {
        cir++;
        do{
            p=stack_[--top];
            in_stack[p]=0;
            belong[p]=cir;
        }while(p!=u);
    }
}

int MAX_1,MAX_2,poi_1;
bool vis[MAXN];
int ans;
void DFS(int u,int deep)
{
    vis[u]=1;
    if(deep>MAX_1)MAX_1=deep,poi_1=u;
    for(int i=0; i<e[u].size(); i++)
    {
        int v=e[u][i];
        if(!vis[v])
        {
            DFS(v,deep+1);
            ans++;
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0)break;
        Index=0;
        memset(head,-1,sizeof(head));
        int a,b;
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        memset(in_stack,0,sizeof(in_stack));
        memset(low,0,sizeof(low));
        memset(DFN,0,sizeof(DFN));
        dps=top=cir=0;
        Tarjan(1);
        memset(h,-1,sizeof(h));
        Index=0;
        for(int i=1; i<=n; ++i)e[i].clear();
        for(int i=1; i<=n; ++i)
            for(int j=head[i]; j+1; j=edge[j].next)
            {
                int v=edge[j].v;
                if(belong[i]!=belong[v])
                {
                    e[ belong[i] ].push_back(belong[v]);
                    e[ belong[v] ].push_back(belong[i]);
                }
            }
        memset(vis,0,sizeof(vis));
        ans=MAX_1=0;
        DFS(1,0);
        int temp=ans;
        memset(vis,0,sizeof(vis));
        MAX_1=0;
        DFS(poi_1,0);
        cout<<temp-MAX_1<<endl;
    }
    return 0;
}