//
// Created by 孙启龙 on 2016/10/29.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long T, n, s;

long long gcd(long long a, long long b)
{
    return b == 0? a: gcd(b, a % b);
}

long long lcm (long long a, long long b)
{
    if(a < b)
        swap(a, b);
    return a / gcd(a, b) * b;
}

int main (void)
{
    scanf("%lld", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%lld %lld", &n, &s);
        printf("Case #%d:", t);
        long long lcmm = 1;
        for(int i = 1; i <= n; i++)
        {
            lcmm = lcm(lcmm, i);
            if(lcmm - 1 > s)
                break;
        }
        if(s == 0)
            printf(" Yes\n");
        else if((s + 1) % lcmm == 0)
            printf(" Yes\n");
        else
            printf(" No\n");
    }
    return 0;
}