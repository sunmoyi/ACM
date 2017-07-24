//
// Created by 孙启龙 on 2017/2/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long ans[110][110];

int main (void)
{
    int n, m, x, y;
    long long k;
    scanf("%d %d %I64d %d %d", &n, &m, &k, &x, &y);
    int t;
    if(n > 1)
        t = (2 * n - 2) * m;
    else
        t = m;
    for(int i = 2; i < n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            ans[i][j] = k / t * 2;
        }
    }
    for(int j = 1; j <= m; j++)
        ans[1][j] = ans[n][j] = k / t;

    int p = (int)(k % t);
    for(int i = 1; i <= n && p; i++)
    {
        for(int j = 1; j <= m && p; j++)
        {
            if(p)
            {
                ans[i][j]++;
                p--;
            }
        }
    }
    for(int i = n - 1; i > 1 && p; i--)
    {
        for(int j = 1; j <= m && p; j++)
        {
            if(p)
            {
                ans[i][j]++;
                p--;
            }
        }
    }

    long long mx = 0, mi = (long long)1 << 60;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            mi = min(mi, ans[i][j]);
            mx = max(mx, ans[i][j]);
        }
    }
    printf("%I64d %I64d %I64d\n", mx, mi, ans[x][y]);
    return 0;
}