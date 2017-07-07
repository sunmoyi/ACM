#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
using namespace std;

long long dp[1000010][1010];
long long fac[1010];

int DP()
{
    for(int i = 1; i <= 100; i++)
    {
        dp[i][1] = 1;
        dp[i][i] = 1;
        for(int j = 2; j < i; j++)
        {
            dp[i][j] = ((dp[i - 1][j] * j) % mod + (dp[i- 1][j - 1])) % mod;
        }
    }
}

int main (void)
{
    fac[1] = 1;
    for(int i = 2; i <= 1000; i++)
        fac[i] = (fac[i - 1] * i) % mod;

    memset(dp, 0, sizeof(dp));
    DP();

    for(int i = 1; i <= 100; i++)
    {
        printf("i = %d\n", i);
        for(int j = 1; j <= 100; j++)
            printf("%lld ", (dp[i][j] * fac[j]) % mod);

    }
}