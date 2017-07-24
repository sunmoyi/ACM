//
// Created by 孙启龙 on 2017/3/29.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
using namespace std;
const int N = 1000000+10;
int d[26][N*3],dmax[26][N*3],dmin[26][N*3],setv[26][N*3],addv[26][N*3];
int r,c,m;
struct node
{
    int tot,maxn,mini;
};
void up(int num,int rt)
{
    d[num][rt]=d[num][rt<<1]+d[num][rt<<1|1];
    dmax[num][rt]=max(dmax[num][rt<<1],dmax[num][rt<<1|1]);
    dmin[num][rt]=min(dmin[num][rt<<1],dmin[num][rt<<1|1]);
}
void build(int num,int rt,int l,int r)
{
    setv[num][rt]=-1;
    addv[num][rt]=0;
    d[num][rt]=dmax[num][rt]=dmin[num][rt]=0;
    if (l>=r){
        return;
    }
    int mid=(l+r)>>1;
    build(num,lson);
    build(num,rson);
}
void pushdown(int num,int rt,int l,int r)
{
    if (l>=r)
        return;
    int mid=(l+r)>>1;
    if (setv[num][rt]>=0)
    {
        d[num][rt<<1]=(mid-l+1)*setv[num][rt];
        dmax[num][rt<<1]=setv[num][rt];
        dmin[num][rt<<1]=setv[num][rt];

        d[num][rt<<1|1]=(r-mid)*setv[num][rt];
        dmax[num][rt<<1|1]=setv[num][rt];
        dmin[num][rt<<1|1]=setv[num][rt];

        setv[num][rt<<1]=setv[num][rt<<1|1]=setv[num][rt];
        setv[num][rt]=-1;
        addv[num][rt<<1]=addv[num][rt<<1|1]=0;
    }
    if (addv[num][rt])
    {
        d[num][rt<<1]+=(mid-l+1)*addv[num][rt];
        dmax[num][rt<<1]+=addv[num][rt];
        dmin[num][rt<<1]+=addv[num][rt];

        d[num][rt<<1|1]+=(r-mid) *addv[num][rt];
        dmax[num][rt<<1|1]+=addv[num][rt];
        dmin[num][rt<<1|1]+=addv[num][rt];

        addv[num][rt<<1]+=addv[num][rt];
        addv[num][rt<<1|1]+=addv[num][rt];
        addv[num][rt]=0;
    }
}
void pushdown2(int num,int rt,int l,int r)
{
    if (l>=r)
        return;
    int mid=(l+r)>>1;
    if (setv[num][rt]>=0)
    {
        d[num][rt<<1]=(mid-l+1)*setv[num][rt];
        dmax[num][rt<<1]=setv[num][rt];
        dmin[num][rt<<1]=setv[num][rt];

        d[num][rt<<1|1]=(r-mid)*setv[num][rt];
        dmax[num][rt<<1|1]=setv[num][rt];
        dmin[num][rt<<1|1]=setv[num][rt];

        setv[num][rt<<1]=setv[num][rt<<1|1]=setv[num][rt];
        setv[num][rt]=-1;
        addv[num][rt<<1]=addv[num][rt<<1|1]=0;
    }
    if (addv[num][rt]){
        d[num][rt<<1]+=(mid-l+1)*addv[num][rt];
        dmax[num][rt<<1]+=addv[num][rt];
        dmin[num][rt<<1]+=addv[num][rt];

        d[num][rt<<1|1]+=(r-mid) *addv[num][rt];
        dmax[num][rt<<1|1]+=addv[num][rt];
        dmin[num][rt<<1|1]+=addv[num][rt];

        addv[num][rt<<1]+=addv[num][rt];
        addv[num][rt<<1|1]+=addv[num][rt];
        addv[num][rt]=0;
    }
}

void add(int num,int v,int L,int R,int rt,int l,int r)
{

    if (L<=l && r<=R)
    {
        d[num][rt]+=v*(r-l+1);
        dmax[num][rt]+=v;
        dmin[num][rt]+=v;
        addv[num][rt]+=v;
        return;
    }
    pushdown(num,rt,l,r);
    int mid=(l+r)>>1;
    if (L<=mid)
        add(num,v,L,R,lson);
    if (R>mid)
        add(num,v,L,R,rson);
    up(num,rt);
}
void sets(int num,int v,int L,int R,int rt,int l,int r)
{

    if (L<=l && r<=R){
        d[num][rt]=v*(r-l+1);
        dmax[num][rt]=v;
        dmin[num][rt]=v;
        setv[num][rt]=v;
        addv[num][rt]=0; //set标记直接清除当前的add标记 这里要注意别漏掉
        return;
    }
    pushdown(num,rt,l,r);
    int mid=(l+r)>>1;
    if (L<=mid)
        sets(num,v,L,R,lson);
    if (R>mid)
        sets(num,v,L,R,rson);
    up(num,rt);
}
node query(int num,int L,int R,int rt,int l,int r)
{
    int mid=(l+r)>>1;
    pushdown2(num,rt,l,r);
    if (L<=l && r<=R){
        node tmp=(node){d[num][rt],dmax[num][rt],dmin[num][rt]};
        return tmp;
    }
    node t1=(node){-1,0,0};
    node t2=(node){-1,0,0};
    if (L<=mid) t1=query(num,L,R,lson);
    if (R>mid) t2=query(num,L,R,rson);
    if (t1.tot<0) return t2;
    if (t2.tot<0) return t1;
    t1.tot+=t2.tot;
    t1.maxn=max(t2.maxn,t1.maxn);
    t1.mini=min(t1.mini,t2.mini);
    return t1;

}
int main()
{
    while (scanf("%d%d%d",&r,&c,&m)!=EOF)
    {
        for (int i=0;i<r;i++){
            build(i,1,1,c);
        }
        while (m--){
            int deno,x1,y1,x2,y2,v;
            scanf("%d",&deno);
            if (deno<=2){
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
                x1--;x2--;
                for (int i=x1;i<=x2;i++)
                {
                    if (deno==1)
                        add(i,v,y1,y2,1,1,c);
                    else
                        sets(i,v,y1,y2,1,1,c);
                }
            }
            else
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1--;x2--;
                node ans;
                for (int i=x1;i<=x2;i++)
                {
                    if (i==x1)
                        ans=query(i,y1,y2,1,1,c);
                    else
                    {
                        node tmp=query(i,y1,y2,1,1,c);
                        ans.tot+=tmp.tot;
                        ans.maxn=max(tmp.maxn,ans.maxn);
                        ans.mini=min(tmp.mini,ans.mini);
                    }
                }
                printf("%d %d %d\n",ans.tot,ans.mini,ans.maxn);
            }
        }
    }
    return 0;
}