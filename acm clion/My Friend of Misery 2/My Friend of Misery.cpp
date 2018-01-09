//
// Created by 孙启龙 on 2017/8/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T, n, m;
char op[3];

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        long long sum = 0, l = 0, r = 1ll << 60;
        while(n--)
        {
            scanf("%d%s", &m, op);
            if(op[0] == '+')
                sum += m + 25, l = sum;
            else
                r = min(r, sum + m + 25);
        }
        printf("%lld\n", r - l);
    }
    return 0;
}