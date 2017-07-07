#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007

using namespace std;

long long s1[20][2][7][7], s2[20][2][7][7], cnt[20][2][7][7];
int bit[20], len;
long long fac[20] = { 1 };
typedef pair<pair<int, int>, int> pairr;
//pair<pair<”Î7”–πÿµƒ ˝µƒ∏ˆ ˝, °∆£®”Î7”–πÿµƒ ˝£©>, °∆£®”Î7”–πÿµƒ ˝µƒ∆Ω∑Ω£©>
pairr dfs(int len, int a, int b, int c, int limit)
{
    if (cnt[len][a][b][c] != -1 && !limit)
        return make_pair(make_pair(cnt[len][a][b][c], s1[len][a][b][c]), s2[len][a][b][c]);
    if (!len)
    {
        if (!a && b && c)
            cnt[len][a][b][c] = 0;
        else
            cnt[len][a][b][c] = 1;
        s1[len][a][b][c] = s2[len][a][b][c] = 0;
        return make_pair(make_pair(cnt[len][a][b][c], s1[len][a][b][c]), s2[len][a][b][c]);
    }
    int up = limit ? bit[len] : 9;
    long long tcnt = 0, ts1 = 0, ts2 = 0;
    for (int i = 0; i <= up; i++)
    {
        int nl = len - 1, na = (a || i == 7), nb = (b + i) % 7, nc = (c * 10 + i) % 7;
        long long f = (fac[len - 1] * i) % mod;
        pairr pre = dfs(nl, na, nb, nc, limit && (i == up));
        ts1 = (ts1 + pre.first.second + pre.first.first * f) % mod;
        ts2 = (ts2 + pre.second + (f * f % mod) * pre.first.first + 2 * f * pre.first.second) % mod;
        tcnt = (tcnt + pre.first.first) % mod;
    }
    if (!limit)
    {
        cnt[len][a][b][c] = tcnt;
        s1[len][a][b][c] = ts1;
        s2[len][a][b][c] = ts2;
    }
    return make_pair(make_pair(tcnt, ts1), ts2);
}

long long sum(long long n)
{
    long long a = n, b = n + 1, c = 2 * n + 1;
    int x = 3, y = 2;
    if (a%x == 0)
        a /= x, x = 1;
    if (a%y == 0)
        a /= y, y = 1;
    if (b%x == 0)
        b /= x, x = 1;
    if (b%y == 0)
        b /= y, y = 1;
    if (c%x == 0)
        c /= x, x = 1;
    if (c%y == 0)
        c /= y, y = 1;
    a %= mod;
    b %= mod;
    c %= mod;
    return (a * b % mod) * c % mod;

}

long long solve(long long n)
{
    len = 0;
    long long m = n;
    while (n)
    {
        bit[++len] = n % 10;
        n /= 10;
    }
    return (sum(m) - dfs(len, 0, 0, 0, 1).second) % mod;
}

int main(void)
{
    for (int i = 1; i < 20; i++)
        fac[i] = (fac[i - 1] * 10) % mod;
    int t;
    long long l, r;
    memset(cnt, -1, sizeof(cnt));
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", ((solve(r) - solve(l - 1)) % mod + mod) % mod);
    }
    return 0;
}