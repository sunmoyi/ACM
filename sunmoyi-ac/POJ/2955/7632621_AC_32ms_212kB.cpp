//
// Created by 孙启龙 on 2016/11/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

int dp[110][110];
char str[110];

int main (void)
{
    while(scanf("%s", str) != EOF && str[0] != 'e')
    {
        memset(dp, 0, sizeof(dp));
        int len = strlen(str);
        for(int k = 1; k < len; k++)
        {
            for(int i = 0, j = k; j < len; i++, j++)
            {
                if((str[i] == '(' && str[j] == ')') || (str[i] == '[' && str[j] == ']'))
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                for(int x = i; x < j; x++)
                    dp[i][j] = max(dp[i][j], dp[i][x] + dp[x + 1][j]);
            }
        }
        printf("%d\n", dp[0][len - 1]);
    }
    return 0;
}