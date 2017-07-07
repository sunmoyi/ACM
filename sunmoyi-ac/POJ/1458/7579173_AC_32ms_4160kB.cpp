//
// Created by 孙启龙 on 2016/11/23.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[1010][1010];
char str1[1010], str2[1010];

int main (void)
{
    while(scanf("%s %s", str1, str2) != EOF)
    {
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        printf("%d\n", dp[len1][len2]);
    }
    return 0;
}