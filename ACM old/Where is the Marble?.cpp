//
// Created by 孙启龙 on 2016/11/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000

using namespace std;

int n, q, x, a[maxn];

int main (void)
{
    int Case = 1;
    while(scanf("%d %d", &n, &q) == 2 && n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        printf("CASE# %d:\n", Case++);
        while(q--)
        {
            scanf("%d", &x);
            int p = lower_bound(a, a + n, x) - a;

            if(p < n && a[p] == x)
                printf("%d found at %d\n", x, p + 1);
            else
                printf("%d not found\n", x);
        }
    }
    return 0;
}