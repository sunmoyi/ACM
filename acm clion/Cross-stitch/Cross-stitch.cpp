//
// Created by 孙启龙 on 2016/11/23.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[1010];
int dp[1010];
int n;
int ans = 0;

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            dp[i] = 1;
        }
        ans = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(num[j] <= num[i] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
                ans = max(ans, dp[i]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}