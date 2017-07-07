//
// Created by 孙启龙 on 2017/2/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T, a, b, k;

long long c[35];

long long f(int k ,int i)
{
    if(!i)
        return 0;
    if(!k)
        return 1;
    if(i < 1<<(k - 1))
        return 2 * f(k - 1, i);
    else
        return f(k - 1, i - (1 << (k - 1))) + 2 * c[k - 1];
}

int main (void)
{
    c[0] = 1;
    for(int i = 1; i < 30; i++)
        c[i] = 3 * c[i - 1];
    scanf("%d", &T);
    for(int s = 1; s <= T; s++)
    {
        scanf("%d %d %d", &k, &a, &b);
        long long total = f(k, b) - f(k, a - 1);
        printf("Case %d: %lld\n", s, total);
    }
    return 0;
}