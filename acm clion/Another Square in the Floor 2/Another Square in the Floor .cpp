//
// Created by 孙启龙 on 2017/8/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1050

using namespace std;

int T;
long long a, b, ans;

int main (void)
{
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%lld %lld", &a, &b);
            ans = max(a, b) * max(a, b);
            printf("%lld\n", ans);
        }
    }
    return 0;
}