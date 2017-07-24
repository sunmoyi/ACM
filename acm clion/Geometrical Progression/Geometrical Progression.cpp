//
// Created by 孙启龙 on 2017/2/8.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, l, r;

long long pow(long long a, long long x)
{
    long long ans = 1;
    while (x)
    {
        if (x & 1)
            ans *= a;
        a *= a;
        x /= 2;
    }
    return ans;
}

long long gcd(long long a, long long b)
{
    return (b>0) ? gcd(b, a%b) : a;
}

int main()
{
    while (scanf("%I64d %I64d %I64d", &n, &l, &r) != EOF)
    {
        if (n == 1)
        {
            printf("%I64d\n", r - l + 1);
        }
        else if (n == 2)
        {
            printf("%I64d\n", (r - l + 1)*(r - l));
        }
        else if (n > 25)
        {
            puts("0");
        }
        else
        {
            long long ans = 0;
            long long maxnum = pow(2, log(100000000*0.1)/log(2.0) / (n - 1));
            maxnum = min(maxnum, 3200LL);
            for (long long i = 1;i <= maxnum;i++)
            {
                for (long long j = i + 1;j <= maxnum;j++)
                {
                    if (gcd(i, j) == 1)
                    {
                        long long a = pow(j, n - 1);
                        long long b = pow(i, n - 1);
                        if (l*a / b > r)
                            continue;
                        ans += (r*b / a) / b - (l - 1) / b;
                    }
                }
            }
            printf("%I64d\n", ans * 2);
        }
    }
    return 0;
}