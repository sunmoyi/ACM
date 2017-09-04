//
// Created by 孙启龙 on 2017/8/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1010

using namespace std;

double dp[maxn];
double x[maxn], y[maxn];
int n;

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lf %lf", &x[i], &y[i]), dp[i] = 1LL << 60;
        for(int i = 2; i <= n; i++)
        {
            double rate = 0x3f3f3f3f;
            for(int j = i - 1; j >= 1; j--)
            {
                double nowrate = (y[i] - y[j]) / (x[i] - x[j]);
                if(nowrate <= rate)
                {
                    double dis = sqrt((y[i] - y[j]) * (y[i] - y[j]) + (x[i] - x[j]) * (x[i] - x[j]));
                    if(j != 2)
                        dp[i] = min(dp[i], min(dp[j - 1], dp[j]) + dis);
                    else
                        dp[i] = min(dp[i], dp[j] + dis);
                }
                rate = min(rate, nowrate);
            }
        }
        printf("%.6lf\n", dp[n]);
    }
    return 0;
}