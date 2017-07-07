#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define N 5

using namespace std;

long long random(long long n)
{
    return (long long)((double)rand() / RAND_MAX * n + 0.5);
}

long long mutli(long long a, long long b, long long m)
{
    long long ret = 0;
    while (b > 0)
    {
        if (b & 1)
            ret = (ret + a) % m;
        b /= 2;
        a = (a << 1) % m;
    }
    return ret;
}

long long quick_mod(long long a, long long b, long long m)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = mutli(ans, a, m);
            b--;
        }
        b /= 2;
        a = mutli(a, a, m);
    }
    return ans;
}

bool Witness(long long a, long long n)
{
    long long m = n - 1;
    int j = 0;
    while (!(m & 1))
    {
        j++;
        m /= 2;
    }
    long long x = quick_mod(a, m, n);
    if (x == 1 || x == n - 1)
        return false;
    while (j--)
    {
        x = x * x % m;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool Miller_rabin(long long n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (!(n & 1))
        return false;
    for (int i = 1; i <= N; i++)
    {
        long long a = random(n - 2) + 1;
        if (Witness(a, n))
            return false;
    }
    return true;
}

int main(void)
{
    long long n;
    while (scanf("%lld", &n) != EOF)
    {
        long long ans = 0;
        int t = 0;
        for(long long  ss = 1; ss <= n; ss++)
        {
            if(Miller_rabin(ss))
                ans++;
            if(ss % 8979491 == 0)
                printf("%d\n", ++t);
        }
        printf("%lld\n", ans);
    }
    return 0;
}