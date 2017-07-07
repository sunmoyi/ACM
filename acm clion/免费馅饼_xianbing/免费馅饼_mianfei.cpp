//
// Created by 孙启龙 on 2016/11/23.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int dp[20][maxn];

int main (void)
{
    int n, x, y;
    while(scanf("%d", &n) != EOF && n)
    {
        memset(dp, 0, sizeof(dp));
        int maxtime = 0;
        for(int i =0 ; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            dp[x][y]++;
            maxtime = max(maxtime, y);
        }

        for(int j = maxtime - 1; j >= 0; j--)
        {
            dp[0][j] += max(dp[0][j + 1], dp[1][j + 1]);
            dp[10][j] += max(dp[9][j + 1], dp[10][j + 1]);
            for(int i = 1; i < 10; i++)
                dp[i][j] += max(max(dp[i - 1][j + 1], dp[i][j + 1]), dp[i + 1][j + 1]);
        }
        printf("%d\n", dp[5][0]);
    }
    return 0;
}