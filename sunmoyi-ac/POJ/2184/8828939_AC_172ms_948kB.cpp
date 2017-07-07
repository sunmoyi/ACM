//
// Created by 孙启龙 on 2017/4/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define maxn 110
#define maxm 200010

using namespace std;

int dp[maxm];
int value[maxn];
int weight[maxn];
int nKind;

int main (void)
{
    int k = 100000;
    while(scanf("%d", &nKind) != EOF)
    {
        for(int i = 0; i < nKind; i++)
            scanf("%d %d", &value[i], &weight[i]);
        for(int i = 0; i <= 200000; i++)
            dp[i] = -INF;
        dp[k] = 0;
        for(int i = 0; i < nKind; i++)
        {
            if(value[i] > 0)
            {
                for(int j = 200000; j >= value[i]; j--)
                    if(dp[j - value[i]] > -INF)
                        dp[j] = max(dp[j], dp[j - value[i]] + weight[i]);
            } else{
                for(int j = 0; j <= 200000 + value[i]; j++)
                    if(dp[j - value[i]] > -INF)
                        dp[j] = max(dp[j], dp[j - value[i]] + weight[i]);
            }
        }
        int ans = 0;
        for(int i = 100000; i <= 200000; i++)
            if(dp[i] >= 0 && dp[i] + i - 100000 > ans)
                ans = dp[i] + i - 100000;
        printf("%d\n", ans);
    }
    return 0;
}