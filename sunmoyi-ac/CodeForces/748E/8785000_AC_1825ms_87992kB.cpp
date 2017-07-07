#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
#define maxn 1000010
#define llg long long 
#define yyj(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout);
llg n,m,a[maxn],ans,i,maxl,l,r,mid;
llg c[10000010];

llg check(llg x)
{
    llg tot=0;
    for (i=1;i<=maxl;i++) c[i]=0;
    for (i=1;i<=n;i++) c[a[i]]++;
    for (i=maxl;i>=x;i--)
    {
        if (i/2>=x)
        {
            if (i%2) {c[i/2]+=c[i]; c[i/2+1]+=c[i];}
            else {c[i/2]+=c[i]*2;}
        }
        else
        {
            tot+=c[i];
        }
    }
    if (tot>=m) return 1;else return 0;
}

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;i++) { scanf("%I64d",&a[i]); r=max(r,a[i]);}
    l=1; maxl=r;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (check(mid)) {l=mid+1; ans=mid;}else {r=mid-1;} 
    }
    if (ans==0) ans--;
    cout<<ans;
    return 0;
}