//
// Created by 孙启龙 on 2017/8/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long pow_mod(long long a, long long b, long long mod)
{
    long long ans = 1;
    a %= mod;
    while(b)
    {
        if(b&1)
            ans = ans * a % mod;
        b >>= 1;
        a = a*a%mod;
    }
    return ans;
}

long long GetC(long long n,long long m,long long mod)
{
    if(m > n)
        return 0;
    if(m > n - m)
        m = n - m;
    long long a = 1,b = 1;
    while(m)
    {
        a = a*n%mod;
        b = b*m%mod;
        m--;
        n--;
    }
    return a * pow_mod(b,mod-2,mod)%mod;
}

long long Lucas(long long n,long long k,long long mod)
{
    if(k == 0)
        return 1;
    return GetC(n%mod,k%mod,mod)*Lucas(n/mod,k/mod,mod)%mod;
}
int main()
{
    int t;
    long long n,m,q;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%I64d %I64d",&n,&m);
        printf("%I64d\n", Lucas(max(n, m), min(n, m), 1000000007));
    }
    return 0;
}