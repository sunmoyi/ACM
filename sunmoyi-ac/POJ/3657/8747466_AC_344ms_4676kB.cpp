//
// Created by 孙启龙 on 2017/4/11.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxm 251000
#define maxn 1100000

using namespace std;

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1001000
#define M 30000
#define inf 0x3f3f3f3f
using namespace std;

struct Lux
{
    int l,r,x;
    bool operator < (const Lux &a)const{
        return x>a.x;
    }
}q[M],Q[M];

int n,m,f[N];
int stk[N],top;
int find(int x)
{
    top=0;
    while(f[x]!=x)
        stk[++top]=x,x=f[x];
    while(top)
        f[stk[top--]]=x;
    return x;
}

bool check(int mid)
{
    int i,j,k,t;
    int L,R,l,r;
    for(i=1;i<=n;i++)
        f[i]=i;
    for(i=1;i<=mid;i++)
        q[i]=Q[i];
    sort(q+1,q+mid+1);
    for(i=1;i<=mid;i=j+1)
    {
        L=l=q[i].l;
        R=r=q[i].r;
        for(j=i;j<mid&&q[j+1].x==q[j].x;)
        {
            j++;
            L=min(L,q[j].l),R=max(R,q[j].r);
            l=max(l,q[j].l),r=min(r,q[j].r);
        }
        if(find(r)<l)
            return 0;
        for(t=R;k=find(t),k>=L;t=k-1)
            f[k]=L-1;
    }
    return 1;
}
int main()
{

    int i,j,k;
    int l,r,mid,ans;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%d%d%d",&Q[i].l,&Q[i].r,&Q[i].x);
    l=1,r=m,ans=0;
    for(i=1;i<=20&&l<=r;i++)
    {
        mid=l+r>>1;
        if(check(mid))
            l=mid+1;
        else
            ans=mid,r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}