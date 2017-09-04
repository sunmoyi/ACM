//
// Created by 孙启龙 on 2017/8/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 13

using namespace std;

long long a, b;
long long dp[maxn][3][11][3][3][3];
int dig[maxn];

long long dfs(int pos, bool same, int last, bool apr, bool ex8, bool ex4, bool limit)
{
    if(pos == 0)
    {
        if(apr)
            return 1;
        else
            return 0;
    }
    if(!limit && dp[pos][same][last][apr][ex8][ex4] != -1)
        return dp[pos][same][last][apr][ex8][ex4];
    int maxx = limit? dig[pos]: 9;
    long long ans = 0;
    for(int i = 0; i <= maxx; i++)
    {
        if((i == 4 && ex8) || (i == 8 && ex4))
            continue;
        ans += dfs(pos - 1, last == i, i, apr||(same && last == i), (ex8 || i == 8), (ex4 || i == 4), (limit && i == maxx));
    }
    if(!limit)
        dp[pos][same][last][apr][ex8][ex4] = ans;
    return ans;
}

long long cal(long long x)
{
    memset(dp, -1, sizeof(dp));
    int num = 0;
    while(x)
    {
        dig[++num] = x % 10;
        x /= 10;
    }
    return dfs(num, false, 0, false, false, false, true);
}

int main (void)
{
    while(scanf("%lld %lld", &a, &b) != EOF)
    {
        long long ans2 = cal(b);
        long long ans1 = (a == 10000000000ll? cal(a) - 1: cal(a - 1));
        printf("%lld\n", ans2 - ans1);
    }
    return 0;
}