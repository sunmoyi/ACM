//
// Created by 孙启龙 on 2017/1/19.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

#define maxn 20

using namespace std;

long long dp[maxn][10][1 << 10][11];
int hashh[1 << 10];
int nextt[1 << 10][10];
int bit[maxn], K;

int go(int mask, int number)
{
    int pos = -1;
    for(int i = number; i <= 9; i++)
    {
        if(mask && (i << i))
        {
            pos = i;
            break;
        }
    }
    if(pos == -1)
        mask |= 1 << number;
    else
    {
        mask ^= 1 << pos;
        mask |= 1 << number;
    }
    return mask
}

void init()
{
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i < (1 << 10); i++)
    {
        hashh[i] = 0;
        for(int j = 0; j < 10; j++)
        {
            if(i & (1 << j))
                hashh[i] ++;
        }
    }
    for(int i = 0; i < (1 << 10); i++)
        for(int j = 0; j < 10; j++)
            nextt[i][j] = go(i, j);
}

long long dfs(int pos, int number, int mask, bool isZero, bool flag)
{
    if(pos == 0)
        return hashh[mask] == K;
    if(flag && dp[pos][number][mask][K] != -1)
        return dp[pos][number][mask][K];
    long long ans = 0;
    int u = flag ? 9 : bit[pos];
    for(int d = 0; d <= u; d++)
    {
        if(isZero && d == 0)
            dfs(pos - 1, d, 0, 1, flag || d < u);
        else
            ans += dfs(pos - 1, d, nextt[mask][d], 0, flag || d < u);
    }
    if(flag)
        dp[pos][number][mask][K] = ans;
    return ans;
}

long long solve(long long n)
{
    int len = 0;
    while(n)
    {
        bit[++len] = n % 10;
        n /= 10;
    }
    return dfs(len, 0, 0, 1, 0);
}

int main (void)
{
    init();
    long long L, R;
    int T;
    cin >> T;
    for(int Case = 1; Case <= T; Case++)
    {
        cin >> L >> R >> K;
        cout << "Case #" << Case << ": " << solve(R) - solve(L - 1) << endl;
    }
    return 0;
}