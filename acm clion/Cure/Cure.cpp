//
// Created by 孙启龙 on 2017/7/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

double dp[300010], sum = 0, t;

int main (void)
{
    dp[0] = 0;
    for(int i = 1; i <= 300000; i++)
        dp[i] = dp[i - 1] + (1.0 / (i * 1.0 * i));
    long long n;
    while(scanf("%lld", &n) != EOF)
    {
        if(n < 0)
            n = -n;
        if(n > 300000)
            n = 300000;
        printf("%.5lf\n", dp[n]);
    }
    return 0;
}