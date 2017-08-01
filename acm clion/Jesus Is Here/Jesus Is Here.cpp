//
// Created by 孙启龙 on 2017/7/24.
//
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 201315
#define mod 530600414

using namespace std;

long long  dp[maxn];
long long  dist[maxn];
long long  cnt[maxn];
long long  fibo[maxn];

void init()
{
    fibo[1] = 1, fibo[2] = 2;
    cnt[1] = 1, cnt[2] = 0;
    for (int  i = 3; i < maxn; i ++)
    {
        fibo[i] = (fibo[i-1] % mod + fibo[i-2] % mod) % mod;
        cnt[i] = (cnt[i-1] % mod + cnt[i-2] % mod) % mod;
    }
    dist[1] = dist[2] = 0, dist[3] = 2;
    for (int i = 4; i < maxn; i ++)
        dist[i] = (dist[i-1] % mod + dist[i-2] % mod + (fibo[i-1] % mod * cnt[i-2] % mod) % mod) % mod;
    dp[4] = dp[1] = dp[2] = dp[3] = 0;
    for (int i = 5; i < maxn; i ++)
    {
        dp[i] = (dp[i-2] % mod + dp[i-1] % mod
                 + (cnt[i-1] % mod * dist[i-2] % mod) % mod
                 + (cnt[i-2] % mod * ((fibo[i-1] % mod * cnt[i-1] % mod) % mod - dist[i-1] % mod) % mod) % mod) % mod;
    }
}
int main()
{
    init();
    int cas = 1, t, n;
    scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        printf("Case #%d: ", cas ++);
        printf("%lld\n", dp[n]);
    }
    return 0;
}