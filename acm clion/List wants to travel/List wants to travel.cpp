//
// Created by 孙启龙 on 2017/7/17.
//

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<bitset>
#include<algorithm>
using namespace std;
#define lson th<<1
#define rson th<<1|1
typedef long long ll;
typedef long double ldb;
#define inf 999999999
#define pi acos(-1.0)
#define maxn 40010
#define maxm 50050

struct edge{
    int to,next,len;
}e[2*maxm];
int pos,tot,Lc,Rc;
int top[maxn],son[maxn],fa[maxn],dep[maxn],num[maxn],p[maxn],a[maxn],c[maxn],first[maxn];
void dfs1(int u,int pre,int deep)
{
    int i,j,v;
    dep[u]=deep;
    fa[u]=pre;
    num[u]=1;
    for(i=first[u];i!=-1;i=e[i].next){
        v=e[i].to;
        if(v==pre)continue;
        a[v]=e[i].len;
        dfs1(v,u,deep+1);
        num[u]+=num[v];
        if(son[u]==-1 || num[son[u] ]<num[v]){
            son[u]=v;
        }
    }
}

void dfs2(int u,int tp)
{
    int i,j,v;
    top[u]=tp;
    if(son[u]!=-1){
        p[u]=++pos;
        c[pos]=a[u];
        dfs2(son[u],tp);
    }
    else{
        p[u]=++pos;
        c[pos]=a[u];
        return;
    }
    for(i=first[u];i!=-1;i=e[i].next){
        v=e[i].to;
        if(v==son[u] || v==fa[u])continue;
        dfs2(v,v);
    }
}


struct node{
    int l,r,num,cl,cr,flag;
}b[4*maxn];

void pushup(int th)
{
    b[th].cl=b[lson].cl;
    b[th].cr=b[rson].cr;
    b[th].num=b[lson].num+b[rson].num;
    if(b[lson].cr==b[rson].cl)b[th].num--;
}

void pushdown(int th)
{
    if(b[th].flag==1){
        b[lson].flag=b[rson].flag=1;
        b[lson].cl=b[lson].cr=b[rson].cl=b[rson].cr=b[th].cl;
        b[lson].num=b[rson].num=1;
        b[th].flag=-1;
    }
}

void build(int l,int r,int th)
{
    int mid;
    b[th].l=l;b[th].r=r;
    b[th].flag=-1;
    if(l==r){
        b[th].cl=b[th].cr=c[l];
        b[th].num=1;
        return;
    }
    mid=(b[th].l+b[th].r)/2;
    build(l,mid,lson);
    build(mid+1,r,rson);
    pushup(th);
}

void update(int l,int r,int color,int th)
{
    int mid;
    if(b[th].l==l && b[th].r==r){
        b[th].num=1;
        b[th].flag=1;
        b[th].cl=b[th].cr=color;
        return;
    }
    pushdown(th);
    mid=(b[th].l+b[th].r)/2;
    if(r<=mid)update(l,r,color,lson);
    else if(l>mid)update(l,r,color,rson);
    else{
        update(l,mid,color,lson);
        update(mid+1,r,color,rson);
    }
    pushup(th);
}

int question(int l,int r,int th,int L,int R)
{
    int mid,num;
    if(b[th].l==L)Lc=b[th].cl;
    if(b[th].r==R)Rc=b[th].cr;
    if(b[th].l==l && b[th].r==r){
        return b[th].num;
    }
    pushdown(th);
    mid=(b[th].l+b[th].r)/2;
    if(r<=mid)return question(l,r,lson,L,R);
    else if(l>mid)return question(l,r,rson,L,R);
    else{
        num=question(l,mid,lson,L,R)+question(mid+1,r,rson,L,R);
        if(b[lson].cr==b[rson].cl)num--;
        return num;
    }
}

int solve(int u,int v)
{
    int f1,f2;
    f1=top[u];f2=top[v];
    int num=0,pre1,pre2;
    pre1=pre2=-1;
    while(f1!=f2){
        if(dep[f1]<dep[f2]){
            swap(pre1,pre2);swap(f1,f2);swap(u,v);
        }
        num+=question(p[f1],p[u],1,p[f1],p[u]);
        if(pre1==Rc)num--;
        pre1=Lc;
        u=fa[f1];
        f1=top[u];
    }
    if(u!=v){
        if(dep[u]<dep[v]){
            swap(pre1,pre2);swap(u,v);
        }
        num+=question(p[son[v]],p[u],1,p[son[v]],p[u]);
        if(pre1!=-1 && Rc==pre1)num--;
        if(pre2!=-1 && Lc==pre2)num--;
    }
    else if(pre1==pre2)num--;
    return num;
}

void gengxin(int u,int v,int value)
{
    int f1,f2;
    f1=top[u];f2=top[v];
    while(f1!=f2){
        if(dep[f1]<dep[f2]){
            swap(f1,f2);swap(u,v);
        }
        update(p[f1],p[u],value,1);
        u=fa[f1];
        f1=top[u];
    }
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    if(u!=v){
        update(p[son[v]],p[u],value,1);
    }
}
void add(int u,int v,int len)
{
    tot++;
    e[tot].next=first[u];e[tot].to=v;e[tot].len=len;
    first[u]=tot;
}
int main()
{
    int i,j,n,m,u,v,f,g,h,w;
    char s[10];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(first,-1,sizeof(first));
        memset(son,-1,sizeof(son));
        pos=0;tot=0;
        for(i=1;i<=n-1;i++){
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);add(v,u,w);
        }
        dfs1(1,0,1);
        dfs2(1,1);

        build(1,pos,1);
        for(i=1;i<=m;i++){
            scanf("%s",s);
            if(s[0]=='Q'){
                scanf("%d%d",&f,&g);
                printf("%d\n",solve(f,g));
            }
            else{
                scanf("%d%d%d",&f,&g,&h);
                gengxin(f,g,h);
            }
        }

    }
    return 0;
}