//
// Created by 孙启龙 on 2017/10/4.
//

#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
typedef long long ll;  
const int mod = 1e9+7;  
const int maxn = 2e3+5;  
ll s[maxn][maxn], c[maxn][maxn], fac[maxn];  
  
void init()  
{  
    memset(s, 0, sizeof(s));  
    s[1][1] = 1;  
    for(int i = 2; i < maxn; i++)  
        for(int j = 1; j <= i; j++)  
            s[i][j] = (s[i-1][j-1]+(ll)j*s[i-1][j])%mod;  
    fac[0] = fac[1] = 1;  
    for(int i = 2; i < maxn; i++)  
        fac[i] = fac[i-1]*i%mod;  
    for(int i = 1; i < maxn; i++)  
        for(int j = 0; j <= i; j++)  
        {  
            if(i == j || !j) c[i][j] = 1;  
            else c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;  
        }  
}  
  
ll qpow(ll p, int q)  
{  
    ll ans = 1;  
    while(q)  
    {  
        if(q%2) ans = ans*p%mod;  
        p = p*p%mod;  
        q /= 2;  
    }  
    return ans;  
}  
  
int main(void)  
{  
    init();  
    int n, m, t;  
    cin >> t;  
    while(t--)  
    {  
        scanf("%d%d", &n, &m);  
        ll ans = 0;  
        int e = min(n, m-1);  
        for(int i = 1; i <= e; i++)  
        {  
            ans = (ans + s[n][i]*fac[i]%mod * qpow(m-i, n)%mod*c[m][i]%mod)%mod;  
        }  
        printf("%lld\n", ans%mod);  
    }  
    return 0;  
}  