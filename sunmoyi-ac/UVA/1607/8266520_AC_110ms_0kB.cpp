//
// Created by 孙启龙 on 2017/2/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010

using namespace std;

struct gate{
    int a, b, o;
};

int T, v0, vn, ans, n, m;
gate gates[maxn];

int opt(int k)
{
    for(int i = 1; i <= m; i++)
    {
        int ia = (gates[i].a < 0) ? (-gates[i].a > k) : (gates[gates[i].a].o);
        int ib = (gates[i].b < 0) ? (-gates[i].b > k) : (gates[gates[i].b].o);
        gates[i].o = !(ia && ib);
    }
    return gates[m].o;
}

int solve()
{
    int l = 1, r = n;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(opt(mid) == vn)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main (void)
{
    scanf("%d", &T);
    for(int C = 0; C < T; ++C)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++)
            scanf("%d %d", &gates[i].a, &gates[i].b);
        v0 = opt(0);
        vn = opt(n);
        if(v0 == vn)
        {
            for(int i = 1; i <= n; i++)
                printf("0");
            printf("\n");
        }
        else
        {
            ans = solve();
            for(int i = 1; i < ans; i++)
                printf("0");
            printf("x");
            for(int i = ans + 1; i <= n; i++)
                printf("1");
            printf("\n");
        }
    }
    return 0;
}