//
// Created by 孙启龙 on 2017/4/30.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100017

using namespace std;


long long  Min[4*N], mark[4*N],b[N];
struct node{
    long long val,tim;
}a[N];

void pushup(int rt)
{
    Min[rt] = min(Min[rt<<1],Min[rt<<1|1]);
}

void pushdown(int l,int r,int rt)
{
    if(mark[rt])
    {
        mark[rt<<1] += mark[rt];
        mark[rt<<1|1] += mark[rt];
        Min[rt<<1] += mark[rt];
        Min[rt<<1|1] += mark[rt];
        mark[rt] = 0;
    }
}

void build(int l,int r,int rt)
{
    Min[rt] = mark[rt] = 0;
    if(l == r) return;
    int mid = (l+r)/2;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}

void update(int l,int r,int aa,int bb,long long val,int rt)
{
    if(aa <= l && bb >= r)
    {
        Min[rt] += val;
        mark[rt] += val;
        return;
    }
    pushdown(l,r,rt);
    int mid = (l+r)/2;
    if(aa <= mid) update(l,mid,aa,bb,val,rt<<1);
    if(bb > mid)  update(mid+1,r,aa,bb,val,rt<<1|1);
    pushup(rt);
}

long long GetTime()
{
    int date,month,hour,minu;
    scanf("%d.%d %d:%d",&date,&month,&hour,&minu);
    return (long long)month*31LL*24*60 + date*24LL*60 + 60LL*hour + minu;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i].val);
        a[i].tim = GetTime();
        b[i] = a[i].tim;
    }
    sort(b + 1, b + n + 1);
    build(1, n + 10, 1);
    for(int i = 1; i <= n; i++)
    {
        long long pos = lower_bound(b + 1, b + n + 1, a[i].tim) - b;
        update(1, n + 10, pos, n, a[i].val,1);
        printf("%lld\n",min(0LL,Min[1]));
    }
    return 0;
}