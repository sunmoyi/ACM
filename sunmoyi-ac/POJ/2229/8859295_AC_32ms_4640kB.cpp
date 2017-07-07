//
// Created by 孙启龙 on 2017/4/21.
//

#include<cstdio>
#include<iostream>
#define mod 1000000000

using namespace std;

int dp[1000010];

int main (void)
{
    int n;
    cin >> n;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if((i & 1) == 1)
            dp[i] = dp[i - 1];
        else
            dp[i] = (dp[i - 1] + dp[i >> 1]) % mod;
    }
    printf("%d\n", dp[n]);
    return 0;
}