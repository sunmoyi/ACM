//
// Created by 孙启龙 on 2017/2/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define INF 0x3f3f3f3f

using namespace std;

int a[maxn], b[maxn], p[maxn];

int main (void)
{
    int n, l, r, maxv = -INF, minv = INF;
    scanf("%d %d %d", &n , &l ,&r);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for(int i = 0; i < n; i++)
    {
        b[i] = a[i] + p[i];
        maxv = max(maxv, b[i]);
        minv = min(minv, b[i]);
    }

    if(maxv - minv + 1 > (r - l + 1))
        printf("-1\n");
    else
    {
        if(minv < l)
        {
            for(int i = 0; i < n; i++)
                b[i] += (l - minv);
        }
        else if (maxv > r)
        {
            for(int i = 0; i < n; i++)
                b[i] -= (maxv - r);
        }

        for(int i = 0; i < n - 1; i++)
            printf("%d ", b[i]);
        printf("%d\n", b[n - 1]);
    }
    return 0;
}