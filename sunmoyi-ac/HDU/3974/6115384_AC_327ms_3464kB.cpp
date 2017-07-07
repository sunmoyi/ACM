
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAXN = 50010;
struct Edge
{
    int to,next;
}edge[MAXN];
int head[MAXN],tot;
int cnt;
int start[MAXN],endd[MAXN];
void init()
{
    cnt = 0;
    tot = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dfs(int u)
{
    ++cnt;
    start[u] = cnt;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        dfs(edge[i].to);
    }
    endd[u] = cnt;
}
struct Node
{
    int l,r;
    int val;
    int lazy;
}segTree[MAXN*4];
void Update_Same(int r,int v)
{
    if(r)
    {
        segTree[r].val = v;
        segTree[r].lazy = 1;
    }
}
void push_down(int r)
{
    if(segTree[r].lazy)
    {
        Update_Same(r<<1,segTree[r].val);
        Update_Same((r<<1)|1,segTree[r].val);
        segTree[r].lazy = 0;
    }
}
void Build(int i,int l,int r)
{
    segTree[i].l = l;
    segTree[i].r = r;
    segTree[i].val = -1;
    segTree[i].lazy = 0;
    if(l == r)return;
    int mid = (l+r)/2;
    Build(i<<1,l,mid);
    Build((i<<1)|1,mid+1,r);
}
void update(int i,int l,int r,int v)
{
    if(segTree[i].l == l && segTree[i].r == r)
    {
        Update_Same(i,v);
        return;
    }
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)update(i<<1,l,r,v);
    else if(l > mid)update((i<<1)|1,l,r,v);
    else
    {
        update(i<<1,l,mid,v);
        update((i<<1)|1,mid+1,r,v);
    }
}
int query(int i,int u)
{
    if(segTree[i].l == u && segTree[i].r == u)
        return segTree[i].val;
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(u <= mid)return query(i<<1,u);
    else return query((i<<1)|1,u);
}
bool used[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    int T;
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        iCase++;
        printf("Case #%d:\n",iCase);
        int u,v;
        memset(used,false,sizeof(used));
        init();
        scanf("%d",&n);
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d",&u,&v);
            used[u] = true;
            addedge(v,u);
        }
        for(int i = 1;i <= n;i++)
            if(!used[i])
            {
                dfs(i);
                break;
            }
        Build(1,1,cnt);
        char op[10];
        int m;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",op);
            if(op[0] == 'C')
            {
                scanf("%d",&u);
                printf("%d\n",query(1,start[u]));
            }
            else
            {
                scanf("%d%d",&u,&v);
                update(1,start[u],endd[u],v);
            }
        }
    }
    return 0;
}