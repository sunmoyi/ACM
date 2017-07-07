//
// Created by 孙启龙 on 2017/2/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 32

using namespace std;

int n, a[maxn + 1];

bool dfs(int d, int maxd)
{
    if(a[d] == n)
        return maxn;
    if(d == maxd)
        return false;

    int maxv = a[0];
    for(int i = 1; i <= d; i++)
        maxv = max(maxv, a[i]);
    if(maxv << (maxd - d) < n)
        return false;

    for(int i = d; i >= 0; i--)
    {
        a[d + 1] = a[d] + a[i];
        if(dfs(d + 1, maxd))
            return true;
        a[d + 1] = a[d] - a[i];
        if(dfs(d + 1, maxd))
            return true;
    }
    return false;
}

int solve(int n)
{
    if(n == 1)
        return 0;
    a[0] = 1;
    for(int maxd = 1; maxd < maxn; maxd++)
        if(dfs(0, maxd))
            return maxd;
    return maxn;
}

int main (void)
{
    while(scanf("%d", &n) == 1 && n)
        printf("%d\n", solve(n));
    return 0;
}
