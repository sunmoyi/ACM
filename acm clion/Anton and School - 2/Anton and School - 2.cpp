//
// Created by 孙启龙 on 2017/3/23.
//

#include<stdio.h>
#include<string.h>
#include <cstdio>'
using namespace std;
#define mod 1000000007
#define ll long long
const ll N = 1000000+5;
const ll M = 1000000+5;
ll pre[2000500];
ll bac[2000500];
char a[2000500];
ll fac[1000050];            //阶乘
ll inv_of_fac[1000005];        //阶乘的逆元
ll qpow(ll x,ll n)
{
    ll ret=1;
    for(; n; n>>=1)
    {
        if(n&1) ret=ret*x%mod;
        x=x*x%mod;
    }
    return ret;
}
void init()
{
    fac[1]=1;
    for(int i=2; i<=M; i++)
        fac[i]=fac[i-1]*i%mod;
    inv_of_fac[M]=qpow(fac[M],mod-2);
    for(int i=M-1; i>=0; i--)
        inv_of_fac[i]=inv_of_fac[i+1]*(i+1)%mod;
}
ll C(ll a,ll b)
{
    if(b>a) return 0;
    if(b==0) return 1;
    return fac[a]*inv_of_fac[b]%mod*inv_of_fac[a-b]%mod;
}
int main()
{
    while(~scanf("%s",a+1))
    {
        init();
        int n=strlen(a+1);
        memset(pre,0,sizeof(pre));
        memset(bac,0,sizeof(bac));
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='(')pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1];
        }
        for(int i=n;i>=1;i--)
        {
            if(a[i]==')')bac[i]=bac[i+1]+1;
            else bac[i]=bac[i+1];
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==')')continue;
            else
            {
                int nn=pre[i];
                int mm=bac[i+1];
                ans+=C(nn+mm-1,mm-1);
                ans%=mod;
            }
        }
        printf("%I64d\n",(ans+mod)%mod);
    }
}