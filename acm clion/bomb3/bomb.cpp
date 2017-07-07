//
// Created by 孙启龙 on 2016/11/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 30

using namespace std;

long long dp[maxn][3];

void init()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= 22; i++)
    {
        dp[i][0] = dp[i - 1][0] * 10 - dp[i - 1][1];// yu 49wuguan de shu
        dp[i][1] = dp[i - 1][0];//yu 49wuguan danshi 9kaitou de shu
        dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1];//yu 49 youguan de shu
    }
}

long long solve(long long n)
{
    long long temp = n, len = 0, a[25], flag = 0, ans = 0;
    while(n)
    {
        a[++len] = n % 10;
        n /= 10;
    }
    a[len + 1] = 0;
    for(int i = len; i; i--)
    {
        ans += dp[i - 1][2] * a[i];
        if(flag)
            ans += dp[i - 1][0] * a[i];
        if(!flag && a[i] > 4)
            ans += dp[i - 1][1];
        if(a[i + 1] == 4 && a[i] == 9)
            flag = 1;
    }
    return ans;
}

int main (void)
{
    int t;
    long long n;
    init();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", solve(n + 1));
    }
    return 0;
}