//
// Created by 孙启龙 on 2017/9/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#define maxn 50010

using namespace std;

bitset<maxn>a, b, ans, bx;

void solve(int x)
{
    for(int i = x; i >= 0; i--)
    {
        ans[i] = ((a >> i) & bx).count() & 1;
        if(!b[i])
            continue;
        for(int j = 0; j < maxn; j += i)
            bx.flip(j);
    }
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        a.reset(), b.reset(), ans.reset(), bx.reset();
        int n, m, q, x, maxx = 0;
        scanf("%d %d %d", &n, &m, &q);
        for(int i = 0; i < n; i++)
            scanf("%d", &x), a.set(x);
        for(int i = 0; i < m; i++)
            scanf("%d", &x), b.set(x), maxx = max(maxx, x);
        solve(maxx);
        while(q--)
        {
            scanf("%d", &x);
            if(ans[x])
                printf("1\n");
            else
                printf("0\n");
        }
    }
    return 0;
}