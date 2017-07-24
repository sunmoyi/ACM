//
// Created by 孙启龙 on 2017/5/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 10010;
const int MAXM = 100010;
struct Edge
{
    int to,next;
    bool cut;//是否为桥的标记
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN];
int Index,top;
bool Instack[MAXN];
bool cut[MAXN];
int add_block[MAXN];//删除一个点后增加的连通块

void addedge(int u,int v) {
    edge[tot].to = v;
	edge[tot].next = head[u];
	edge[tot].cut = false;
    head[u] = tot++;
}

void Tarjan(int u,int pre)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    int son = 0;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        v = edge[i].to;
        if (v == pre)
            continue;
        if (!DFN[v])
        {
            son++;
            Tarjan(v, u);
            if (Low[u] > Low[v])
                Low[u] = Low[v];
            if (u != pre && Low[v] >= DFN[u])//不是树根
            {
                cut[u] = true;
                add_block[u]++;
            }
        } else if (Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(u == pre && son > 1)
        cut[u] = true;
    if(u == pre)
        add_block[u] = son - 1;
    Instack[u] = false;
    top--;
}

void solve(int N)
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,0,sizeof(Instack));
    memset(add_block,0,sizeof(add_block));
    memset(cut,false,sizeof(cut));
    Index = top = 0;
    int cnt = 0;
    for(int i = 1;i <= N;i++)
    if( !DFN[i] )
    {
        Tarjan(i,i);
        cnt++; }
    int ans = 0;
    for(int i = 1;i <= N;i++)
        ans = max(ans,cnt+add_block[i]); printf("%d\n",ans);
}

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
int main()
{
    int n,m; int u,v;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0 && m == 0)
            break;
        init();
        while(m--)
        {
            scanf("%d%d",&u,&v); u++;v++; addedge(u,v); addedge(v,u);
        }
        solve(n);
    }
    return 0;
}
