//
// Created by 孙启龙 on 2017/5/15.
//

#include <iostream>

using namespace std;

unsigned long long dp[100 + 16][1000 + 16][2];
#define LIMIT_ULL 100000000000000000

int main(int argc, char *argv[])
{
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= K; ++i)
    {
        dp[i][0][1] = 1;
        for (int j = 1; j <= N; ++j)
        {
            if (j < i)
            {
                dp[i][j][0] = dp[i - 1][j][0];
                dp[i][j][1] = dp[i - 1][j][1];
            }
            else
            {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i][j - i][0];
                dp[i][j][1] = dp[i - 1][j][1] + dp[i][j - i][1];
                // 高位进位
                dp[i][j][0] += dp[i][j][1] / LIMIT_ULL;
                // 低位限制
                dp[i][j][1] = dp[i][j][1] % LIMIT_ULL;
            }
        }
    }

    if (dp[K][N][0])
    {
        cout << dp[K][N][0];
    }
    cout << dp[K][N][1] << endl;

    return 0;
}