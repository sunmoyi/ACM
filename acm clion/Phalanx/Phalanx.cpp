//
// Created by 孙启龙 on 2017/4/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

char map[maxn][maxn];
int dp[maxn][maxn];
int n;

int main (void)
{
    while(scanf("%d", &n) != EOF && n)
    {
        for(int i = 0; i < n; i++)
                scanf("%s", map[i]);

        memset(dp, 0, sizeof(dp));

        int ans = 1;
        for(int i = 0; i < n; i++)
            dp[0][i] = dp[i][0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int t1 = i, t2 = j;
                while(t1 >= 0 && t2 < n && map[t1][j] == map[i][t2])
                    t1--, t2++;
                int len = i - t1;
                if(len > dp[i - 1][j + 1] + 1)
                    dp[i][j] = dp[i - 1][j + 1] + 1;
                else
                    dp[i][j] = len;
                ans = max (ans, dp[i][j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}