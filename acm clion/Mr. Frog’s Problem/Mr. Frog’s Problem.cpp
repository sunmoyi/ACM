//
// Created by 孙启龙 on 2016/11/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long a, b;
int T;

int main (void)
{
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        scanf("%lld %lld", &a, &b);
        printf("Case #%d:\n", Case);
        if(a == b)
        {
            printf("1\n");
            printf("%lld %lld\n", a, a);
        }
        else
        {
            printf("2\n");
            printf("%lld %lld\n", min(a, b), max(a, b));
            printf("%lld %lld\n", max(a, b), min(a, b));
        }
    }
    return 0;
}