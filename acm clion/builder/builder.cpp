//
// Created by 孙启龙 on 2017/8/9.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxa 210
#define maxn 50010
#define mod 1000000007

using namespace std;

int s[maxn][maxa];
int C[maxa][maxa];

void init(int n, int a)
{
    for(int i = 0; i <= n; i++)
    {
        s[i][0] = 0;
        if(i <= a)
            s[i][i] = 1;
        for(int j = 1; j <= min(i, a); j++)
            s[i][j] = (0ll + s[i - 1][j - 1] + 1ll * (i - 1) * s[i - 1][j] % mod) % mod;
    }
    for(int i = 0; i <= a; i++)
    {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++)
            C[i][j] = (0ll + C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
}

int main (void)
{
    init(50000, 200);
    int T, n, a, b;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &n, &a, &b);
        printf("%lld\n", (1ll * s[n - 1][a + b - 2] * C[a + b - 2][a - 1]) % mod);
    }
    return 0;
}