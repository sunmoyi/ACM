//
// Created by 孙启龙 on 2016/11/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010
#define abs(x) (x > 0? x:(-(x)))

using namespace std;

long long a[maxn], c[maxn], tot, m;

int main (void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        tot = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            tot += a[i];
        }
        m = tot / n;
        c[0] = 0;
        for(int i = 1; i < n; i++)
            c[i] = c[i - 1] + a[i] - m;
        sort(c, c + n);
        long long x1 = c[n / 2], ans = 0;
        for(int i = 0; i < n; i++)
            ans += abs(x1 - c[i]);
        printf("%lld\n", ans);
    }
    return 0;
}