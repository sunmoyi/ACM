//
// Created by 孙启龙 on 2017/4/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iostream>
#define maxn 1000010

using namespace std;

long long n, m, a[maxn], ans, maxl, l, r, mid;
long long c[10000010];

bool check(long long x)
{
    long long tot = 0;
    memset(c, 0, sizeof(c));
    for(int i = 1; i <= n; i++)
        c[a[i]]++;
    for(long long i = maxl; i >= x; i--)
    {
        if(i / 2 >= x)
        {
            if(i % 2)
                c[i / 2] += c[i], c[i / 2 + 1] += c[i];
            else
                c[i / 2] += c[i] * 2;
        }
        else
        {
            tot += c[i];
        }
    }
    if(tot >= m)
        return true;
    else
        return false;
}

int main (void)
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        scanf("%I64d", &a[i]);
        r = max(r, a[i]);
    }
    l = 1, maxl = r;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if(ans == 0)
        ans = -1;
    cout << ans << endl;
    return 0;
}