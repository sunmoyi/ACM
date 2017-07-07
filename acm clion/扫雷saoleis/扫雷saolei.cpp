//
// Created by 孙启龙 on 2016/11/7.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 100000007

using namespace std;

int a[10005];
long long dp[10005][3][3];
char str[10005];
int dir[3][10];
int T;

int main(void)
{
    dir[2][0] = 1, dir[2][1] = 2, dir[2][2] = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", str);
        int len = strlen(str);

        for(int i = 0; i < len; i++)
        {
            a[i+1] = str[i] - '0';
        }

        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        dp[0][0][1]=1;
        dp[0][0][2]=1;

        for(int i = 1; i <= len; i++)
        {
            for(int j = 0;j <= 2;j++)
            {
                if(a[i] - j >= 0 && a[i] - j <= 2)
                {
                    dp[i][j][a[i] - j] = dp[i - 1][0][j] * dir[2][j];
                        if(dp[i][j][a[i] - j] >= 100000007)
                            dp[i][j][a[i] - j] -= 100000007;

                }
                if(a[i] - j - 1 >= 0 && a[i] - j - 1 <= 2)
                {
                    dp[i][j][a[i] - j - 1] = (dp[i - 1][1][j]) * dir[2][j];
                    if(dp[i][j][a[i] - j - 1] >= 100000007)
                        dp[i][j][a[i] - j - 1] -= 100000007;

                }
                if(a[i] - j - 2 >= 0 && a[i] - j - 2 <= 2)
                {
                    dp[i][j][a[i] - j - 2] = dp[i - 1][2][j] * dir[2][j];
                    if(dp[i][j][a[i] - j - 2] >= 100000007)
                        dp[i][j][a[i] - j - 2] -= 100000007;

                }
            }
        }

        long long ans = 0;
        for(int j = 0; j <= 2; j++)
        {
            ans += dp[len][j][0];
        }
        printf("%lld\n", ans % 100000007);
    }
    return 0;
}