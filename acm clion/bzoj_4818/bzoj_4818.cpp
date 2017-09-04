//
// Created by 孙启龙 on 2017/8/9.
//

/*
 * TLE
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxm 20000005
#define maxp 110
#define mod 20170408

using namespace std;

int n, m, p, prime[maxm / 10], tot, f[maxp];
struct arr{
    int a[maxp][maxp];
}ans, a;
bool not_prime[maxm];

void get_prime(int n)
{
    not_prime[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!not_prime[i])
            prime[++tot] = i;
        for(int j = 1; j <= tot && i * prime[j] <= n; j++)
        {
            not_prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}

void mul(arr &c, arr a, arr b)
{
    memset(c.a, 0, sizeof(c.a));
    for(int i = 0; i < p; i++)
        for(int j = 0; j < p; j++)
            for(int k = 0; k < p; k++)
                c.a[i][j] = (c.a[i][j] + 1ll * a.a[i][k] * b.a[k][j] % mod) % mod;
}

arr ksm(arr x, int y)
{
    memset(ans.a, 0, sizeof(ans.a));
    for(int i = 0; i < p; i++)
        ans.a[i][i] = 1;
    while(y)
    {
        if(y & 1)
            mul(ans, ans, x);
        mul(x, x, x);
        y >>= 1;
    }
    return ans;
}

int solve1()
{
    for(int i = 1; i <= m; i++)
        f[i % p]++;
    for(int j = 1; j <= m; j++)
        a.a[(-j % p + p) % p][0]++;
    for(int i = 1; i < p; i++)
        for(int j = 0; j < p; j++)
            a.a[j][i] = a.a[(j - 1 + p) % p][i - 1];
    a = ksm(a, n - 1);
    int ans = 0;
    for(int i = 0; i < p; i++)
        ans = (ans + 1ll * f[i] * a.a[i][0] % mod) % mod;
    return ans;
}

int solve2()
{
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= m; i++)
        if(not_prime[i])
            f[i % p]++;
    memset(a.a, 0, sizeof(a.a));
    for(int j = 1; j <= m; j++)
        if(not_prime[j])
            a.a[(-j % p + p) % p][0]++;
    for(int i = 1; i < p; i++)
        for(int j = 0; j < p; j++)
            a.a[j][i] = a.a[(j - 1 + p) % p][i - 1];
    a = ksm(a, n - 1);
    int ans = 0;
    for(int i = 0; i < p; i++)
        ans = (ans + 1ll * f[i] * a.a[i][0] % mod) % mod;
    return ans;
}

int main (void)
{
    scanf("%d %d %d", &n, &m, &p);
    get_prime(m);
    int x = solve1(), y = solve2();
    printf("%d\n", (x - y + mod) % mod);
    return 0;
}
*/


#include<cstdio>
#include<cstring>

#define MN 20000000
#define MP 1270610
#define MK 100
#define MOD 20170408

struct mat {
    int z[MK][MK];

    mat() {
        memset(z, 0, sizeof(z));
    }

    mat operator*(const mat &b) {
        mat c;
        int i, j, k;
        for (i = 0; i < MK; ++i)
            for (k = 0; k < MK; ++k)
                if (z[i][k])
                    for (j = 0; j < MK; ++j)
                        c.z[i][j] = (c.z[i][j] + 1LL * z[i][k] * b.z[k][j]) % MOD;
        return c;
    }
} a, x;

bool u[MN + 5];
int p[MP + 5], pn, s[MK];

int main() {
    int n, m, k, i, j, ans;

    //线性筛
    for (u[1] = 1, i = 2; i <= MN; ++i) {
        if (!u[i])
            p[++pn] = i;
        for (j = 1; i * p[j] <= MN; ++j) {
            u[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }

    scanf("%d%d%d", &n, &m, &k);


    //瞎几把选
    for (i = 1; i <= m; ++i)
        ++s[i % k];
    a.z[0][0] = 1;
    for (i = 0; i < k; ++i)
        for (j = 0; j < k; ++j)
            x.z[i][(i + j) % k] = s[j] % MOD;
    for (i = n; i; i >>= 1, x = x * x)
        if (i & 1)
            a = a * x;
    ans = a.z[0][0];


    //不选素数
    memset(s, 0, sizeof(s));
    memset(a.z, 0, sizeof(a.z));
    for (i = 1; i <= m; ++i)
        if (u[i])
            ++s[i % k];
    a.z[0][0] = 1;
    for (i = 0; i < k; ++i)
        for (j = 0; j < k; ++j)
            x.z[i][(i + j) % k] = s[j] % MOD;
    for (i = n; i; i >>= 1, x = x * x)
        if (i & 1)
            a = a * x;


    //容斥
    printf("%d", (ans - a.z[0][0] + MOD) % MOD);
}