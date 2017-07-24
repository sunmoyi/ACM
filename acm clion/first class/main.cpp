#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 10000

using namespace std;

bool is_prime[maxn];

void make_prime()
{
    for (int i = 2; i < maxn; i++)
        is_prime[i] = true;
    for (int i = 2; i < maxn; i++)
    {
        if (is_prime[i]== true)
        {
            for (int j = i + i; j < maxn; j += i)
                is_prime[j] = false;
        }
    }
}

long long gcd(long long a, long long b)
{
    return b == 0? (a): (gcd(b, a % b));
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}


long long pow_mod(long long a, long long b, long long c)
{
    long long j, i, k = 1, l;
    while (b > 0)
    {
        if (b % 2 == 1)
            k = k * a;
        a = a * a;
        b /= 2;
    }
    return k;
}

int main(void)
{
    long long i, j, k, l, n, m, b, a;
    while (scanf("%lld", &a) != EOF)
    {
        for (i = 1; i <= a; i++)
        {
            scanf("%lld %lld %lld", &b, &n, &m);
            if (n == 0)
                printf("%lld\n", b % m);
            else
                printf("%lld\n", pow_mod(b, n, m));
        }
    }
    return 0;
}









