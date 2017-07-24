//
// Created by 孙启龙 on 2017/7/20.
//

#include <cstdio>
#define ll long long

int main()
{
    ll n, m;
    while(~scanf("%lld %lld", &n, &m))
    {
        printf((n >> 1) * (n - (n >> 1)) <= m ? "T\n" : "F\n");
    }
    return 0;
}