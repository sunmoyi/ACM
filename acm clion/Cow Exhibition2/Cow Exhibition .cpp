//
// Created by 孙启龙 on 2017/5/11.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define maxm 200010

using namespace std;

int n;
int dp[maxm];
int value[maxn], weight[maxn];

int main (void)
{
    int mid = 100000;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d %d", &value[i], &weight[i]);
        for(int i = 0; i < maxm; i++)
            dp[i] = -0x3f3f3f3f;
        dp[mid] = 0;
        for(int i = 0; i < n; i++)
        {
            if(value[i] > 0)
            {
                for(int j = 200000; j >= value[i]; j--)
                    if(dp[j - value[i]] > -0x3f3f3f3f)
                        dp[j] = max(dp[j - value[i]] + weight[i], dp[j]);
            }
            else
            {
                for(int j = 0; j <= 200000 + value[i]; j++)
                    if(dp[j - value[i]] > -0x3f3f3f3f)
                        dp[j] = max(dp[j], dp[j - value[i]] + weight[i]);
            }
        }
        int ans = 0;
        for(int i = 100000; i <= 200000; i++)
            if(dp[i] > 0)
                ans = max(ans, dp[i] + i - 100000);
        printf("%d\n", ans);
    }
    return 0;
}