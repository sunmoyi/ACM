//
// Created by 孙启龙 on 2017/7/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

int dp[maxn][maxn], op1[maxn], op2[maxn];

int main (void)
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &op1[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &op2[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(max(op1[i], op2[j]) - min(op1[i], op2[j]) <= 4)
                dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1] + 1));
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    printf("%d\n", dp[n][n]);
    return 0;
}