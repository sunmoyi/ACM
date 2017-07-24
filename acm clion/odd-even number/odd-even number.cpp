//
// Created by 孙启龙 on 2017/7/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

long long dp[25][5];
int num[25];

long long dfs(int pos, int limit, int status)
{
    if(pos < 0)
    {
        if(status == 2 || status == 3)
            return 1;
        else
            return 0;
    }
    if(!limit && dp[pos][status] != -1)
        return dp[pos][status];

    int end = limit? num[pos]: 9;
    long long ans = 0;
    for(int i = 0; i <= end; i++)
    {
        if(!status)
        {
            if(i == 0)
                ans += dfs(pos - 1, 0, 0);
            else
            {
                if(i & 1)
                    ans += dfs(pos - 1, limit && end == i, 1);
                else
                    ans += dfs(pos - 1, limit && end == i, 3);
            }
        }
        else if (status == 1)
        {
            if(i & 1)
                ans += dfs(pos - 1, limit && end == i, 2);
        }
        else if (status == 2)
        {
            if(i & 1)
                ans += dfs(pos - 1, limit && i == end, 1);
            else
                ans += dfs(pos - 1, limit && i == end, 3);
        }
        else if (status == 3)
        {
            if(i & 1)
                ans += dfs(pos - 1, limit && i == end, 1);
            else
                ans += dfs(pos - 1, limit && i == end, 4);
        }
        else
        {
            if(i & 1)
                ;
            else
                ans += dfs(pos - 1, limit && i == end, 3);
        }
    }
    if(!limit)
        dp[pos][status] = ans;
    return ans;
}

long long solve(long long n)
{
    memset(dp, -1, sizeof(dp));
    int len = 0;
    while(n)
    {
        num[len++] = n % 10;
        n /= 10;
    }
    return dfs(len - 1, 1, 0);
}

int main (void)
{
    int Case;
    scanf("%d", &Case);
    for(int i = 1; i <= Case; i++)
    {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        printf("Case #%d: ", i);
        printf("%lld\n", solve(r) - solve(l - 1));
    }
    return 0;
}