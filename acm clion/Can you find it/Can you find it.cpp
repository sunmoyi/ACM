//
// Created by 孙启龙 on 2017/7/22.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef __int64 ll;
const int N = 1e5+10;
ll C, k1, b1, k2;
ll a[2*N], b[2*N];

ll pow_mod(ll x, ll y, ll k)
{
    ll s = 1;
    while(y)
    {
        if (y % 2)
            s = (s * x)%k;
        x = (x * x)%k;
        y >>= 1;
    }
    return s;
}

int main()
{
    int cas = 1;
    while(~scanf("%lld %lld %lld %lld", &C, &k1, &b1, &k2))
    {
        printf("Case #%d:\n", cas++);
        for(ll i = 1; i < C; i++)
        {
            ll cnt = pow_mod(i, k1 + b1, C);
            a[i] = i;
            b[i] = (cnt / C + 1) * C - cnt;
        }
        bool flag; ll ans = 0;
        for(ll i = 1; i < C; i++)
        {
            flag = 0;
            for(ll j = 2; j <= 100; j++)
            {
                if((pow_mod(a[i], k1 * j + b1, C) + pow_mod(b[i], k2 * (j-1) + 1, C)) % C)
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
                ans++; printf("%I64d %I64d\n", a[i], b[i]);
            }
        }
        if(ans == 0) printf("-1\n");
    }
    return 0;
}