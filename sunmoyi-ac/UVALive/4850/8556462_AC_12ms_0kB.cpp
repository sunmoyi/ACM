//
// Created by 孙启龙 on 2017/3/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 510

using namespace std;

struct work{
    int s, d;
}w[maxn];
int n, pos;

int cmp(work a, work b)
{
    if(a.d != b.d)
        return a.d < b.d;
    return a.s < b.s;
}

int solve(int x)
{
    int max1 = 0, max2 = 0, t = 0;
    for(int i = 0; i <= pos; i++)
    {
        if(i == x)
            continue;
        t += w[i].s;
        int k = max(t - w[i].d, 0);
        max2 = max(max2, k);
        if(max2 > max1)
            swap(max2, max1);
    }
    t += w[x].s;
    int k = max(t - w[x].d, 0);
    max2 = max(max2, k);
    return max1 + max2;
}

int main (void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &w[i].s, &w[i].d);
        sort(w, w + n, cmp);

        int max1 = 0, max2 = 0, t = 0;
        for(int i = 0; i < n; i++)
        {
            t += w[i].s;
            if(t - w[i].d >= max2)
            {
                pos = i;
                max2 = t - w[i].d;
            }
            if(max2 > max1)
                swap(max1, max2);
            //printf("times: %d: max1 %d    max2 %d     pos %d\n", i, max1, max2, pos);
        }
        int res = max1 + max2;
        for(int i = 0; i < pos; i++)
            res = min(res, solve(i));
        printf("%d\n", res);
    }
    return 0;
}