//
// Created by 孙启龙 on 2017/4/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long T, a, b, x, y;

int main (void)
{
    while(scanf("%lld", &T) != EOF)
    {
        while(T--)
        {
            scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
            long long ans = 0;
            long long tempx = x, tempy= y;
            for(int i = 1; i <= 100; i++)
            {
                long long ans1 = tempx / a;
                long long ans2 = tempy / b;
                if(tempx < a && tempy < b)
                    break;
                tempx -= ans1 * a;
                tempy -= ans2 * b;
                ans += ans1 + ans2;
                tempx += ans1 + ans2;
                tempy += ans1 + ans2;
            }
            printf("%lld %lld\n", tempx, tempy);
            if(tempx >= a || tempy >= b)
                printf("INF\n");
            else
                printf("%lld\n", ans);
        }
    }
    return 0;
}