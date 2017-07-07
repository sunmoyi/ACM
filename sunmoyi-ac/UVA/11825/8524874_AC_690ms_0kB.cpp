//
// Created by 孙启龙 on 2017/3/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 16

using namespace std;

int n, P[maxn], cover[1 << maxn], f[1 << maxn];

int main (void)
{
    int Case = 0;
    while(scanf("%d", &n) != EOF && n)
    {
        int m, x;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &m);
            P[i] = 1 << i;
            while(m--)
            {
                scanf("%d", &x);
                P[i] |= (1 << x);

            }
        }

        for(int S = 0; S < (1 << n); S++)
        {
            cover[S] = 0;
            for(int i = 0; i < n; i++)
                if(S & (1 << i))
                    cover[S] |= P[i];
        }

        f[0] = 0;
        const int ALL = (1 << n) - 1;
        for(int S = 1; S < (1 << n); S++)
        {
            f[S] = 0;
            for(int S0 = S; S0; S0 = (S0 - 1) & S)
            {
                if(cover[S0] == ALL)
                    f[S] = max(f[S], f[S0 ^ S] + 1);
            }
        }
        printf("Case %d: %d\n", ++Case, f[ALL]);
    }
    return 0;
}