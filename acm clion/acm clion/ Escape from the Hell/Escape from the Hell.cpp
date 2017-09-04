//
// Created by 孙启龙 on 2017/4/20.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
#define FOR(i,x,y)  for(int i = (int)(x);i < (int)(y);++ i)

const int maxn = 100010;

int n, li[maxn];
LL L, sum[maxn], c[maxn];

struct Num{
    LL a, b;
    bool operator < (const Num& rhs) const{
        return a-b > rhs.a-rhs.b;
    }
}s[maxn];

void Init()
{
    LL ca = 0;
    int idx = 1;
    FOR(i, 2, n+1)
    {
        ca = ca+s[i].a-s[i].b-c[idx];
        if(ca <= 0)
            break;
        ++ idx;
    }
    li[1] = idx;
    FOR(i, 2, n+1)
    {
        if(i-1 > idx)
        {
            li[i] = idx;
            continue;
        }
        if(idx == n)
        {
            li[i] = n;
            continue;
        }
        ca += s[i-1].a-s[i-1].b+s[i].b-s[i].a;
        while(ca > 0 && idx < n)
        {
            ++ idx;
            ca += s[idx+1].a-s[idx+1].b-c[idx];
        }
        li[i] = idx;
    }
}

int ff = n+1;

bool judge(int x)
{
    -- x;
    FOR(i, 1, n+1)
    {
        LL lim = L-s[i].a;
        if(li[i] <= x)
            continue;
        if(i > x && sum[x] >= lim)
            return true;
        if(i <= x && sum[x+1]-s[i].a+s[i].b >= lim)
            return true;
    }
    return false;
}

int main()
{
    while(~scanf("%d%lld", &n, &L))
    {
        LL mx = -1;
        FOR(i, 1, n+1)
            scanf("%lld%lld", &s[i].a, &s[i].b), mx = max(mx, s[i].a);
        s[n+1].a = s[n+1].b = 0;
        FOR(i, 1 ,n+1)
            scanf("%lld", c+i);
        if(mx >= L)
        {
            printf("1\n");
            continue;
        }
        sort(s+1, s+n+1);
        ff = n;
        FOR(i, 1, n+1)
            if(s[i].a <= s[i].b)
            {
                ff = i;
                break;
            }
        sum[0] = 0;
        FOR(i, 1, n+1)
            sum[i] = sum[i-1]+s[i].a-s[i].b;
        Init();
        int l = 1, r = ff;
        if(l > r)
        {
            printf("-1\n");
            continue;
        }
        while(l < r)
        {
            int mid = (l+r) >> 1;
            if(judge(mid))
                r = mid;
            else
                l = mid+1;
        }
        if(judge(l))
            printf("%d\n", l);
        else
            printf("-1\n");
    }
    return 0;
}