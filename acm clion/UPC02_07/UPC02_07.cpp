//
// Created by 孙启龙 on 2017/7/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 100010
#define maxm 25
using namespace std;

int dp[maxn][maxm][4];
char pos[maxn];
map<char, int>mp;
int killpos[4][4] = {{0, 0, 0, 0},{0, 0, 1, 0},{0, 0, 0, 1},{0, 1, 0, 0}};
int n, m;

int main (void) {
    mp['H'] = 1;
    mp['S'] = 2;
    mp['P'] = 3;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        getchar();
        scanf("%c", &pos[i]);
    }

    for (int i = 1; i <= 3; i++)
        dp[1][0][i] = killpos[i][mp[pos[1]]];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j != 0)
                    for (int t = 1; t <= 3; t++)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][t]);

                dp[i][j][k] += killpos[k][mp[pos[i]]];
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= m; i++)
        for (int j = 1; j <= 3; j++)
            ans = max(ans, dp[n][i][j]);
    printf("%d\n", ans);
    return 0;
}