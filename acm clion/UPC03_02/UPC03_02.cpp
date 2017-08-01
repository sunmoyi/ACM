//
// Created by 孙启龙 on 2017/7/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100006
#define lowbit(x) (x&-x)
#define LL long long
using namespace std;

int n,a[maxn],b[maxn],p1[maxn],p2[maxn];
LL ans,ans0,ans1,f[maxn];
void put(int x,int y){for(;x<=n;x+=lowbit(x))f[x]+=y;}
int get(int x){
    int sum=0;
    for(;x;x-=lowbit(x))sum+=f[x];
    return sum;
}
int main(){

    scanf("%d", &n);
    for(int i=1;i<=n;i++)scanf("%d", &a[i]),p1[a[i]]=i;
    for(int i=1;i<=n;i++)scanf("%d", &b[i]),p2[b[i]]=i;
    for(int i=n;i>=1;i--)ans0+=get(p1[b[i]]),put(p1[b[i]],1);
    ans=ans1=ans0;
    for(int i=1;i<=n;i++){
        ans0=ans0-p1[b[i]]+1+n-p1[b[i]];
        ans=min(ans,ans0);
    }
    for(int i=1;i<=n;i++){
        ans1=ans1-p2[a[i]]+1+n-p2[a[i]];
        ans=min(ans,ans1);
    }
    printf("%lld",ans);
    return 0;
}