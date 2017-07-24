//
// Created by 孙启龙 on 2017/4/27.
//

#include <iostream>
#include <string>
using namespace std;

int cost[32];
int dp[2048][2048];


int main(int argc, char *argv[])
{

    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    for (int i = 0; i < N; ++i)
    {
        char c;
        int add_cost, delete_cost;
        cin >> c >> add_cost >> delete_cost;
        cost[c - 'a'] = min(add_cost, delete_cost);
    }

    for (int i = M - 1; i >= 0; --i)
    {
        for (int j = i + 1; j < M; ++j)
        {
            dp[i][j] = min(	dp[i + 1][j] + cost[s[i] - 'a'],
                               dp[i][j - 1] + cost[s[j] - 'a']);
            if (s[i] == s[j])
            {

                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            }
        }
    }

    cout << dp[0][M - 1] << endl;


    return 0;
}