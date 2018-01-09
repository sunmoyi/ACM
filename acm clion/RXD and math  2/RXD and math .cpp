//
// Created by 孙启龙 on 2017/8/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007

using namespace std;

long long n, k;

long long quick_pow_mod(long long a, long long b)
{
    long long ans = 1;
    a = a % mod;
    while(b)
    {
        if(b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

int main (int agrc, char* agrv[])
{
    int Case = 1;
    while(scanf("%lld %lld", &n, &k) != EOF)
    {
        long long ans = quick_pow_mod(n, k);
        printf("Case #%d: %lld\n", Case++, ans % mod);
    }
    return 0;
}