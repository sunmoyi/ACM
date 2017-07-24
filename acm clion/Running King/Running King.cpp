//
// Created by 孙启龙 on 2017/7/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010
#define mod 1000000007

using namespace std;

long long a[maxn], n, m, k;

void init()
{
    a[0] = 1;
    for(long long i = 1; i < maxn; i++)
    {
        a[i] = a[i - 1] * i;
        a[i] %= mod;
    }
}

long long pow_mod(long long x, long long p)
{
    long long ans = 1;
    x %= mod;
    while(p)
    {
        if(p & 1)
            (ans *= x) %= mod;
        (x *= x) %= mod;
        p >>= 1;
    }
    return ans;
}

long long C(int n, int m)
{
    if(m > n)
        return 0;
    return a[n] * pow_mod(a[m] * a[n - m] % mod, mod - 2) % mod;
}

long long Lucas(long long n, long long m)
{
    if(m == 0)
        return 1;
    return Lucas(n / mod, m / mod) * C(n % mod, m % mod) % mod;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    init();
    while(T--)
    {
        scanf("%lld %lld %lld", &n, &m, &k);
        long long res = Lucas(n - m * k - 1, m - 1);
        (res *= n) %= mod;
        res *= pow_mod(m, mod - 2);
        res %= mod;
        printf("%lld\n", res);
    }
    return 0;
}