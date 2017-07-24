//
// Created by 孙启龙 on 2017/5/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

long long gcd(long long a,long long b)
{
    return (b == 0)? a: gcd(b, a % b);
}

int main(void)
{
    long long x,y;
    while(scanf("%lld%lld",&x,&y) != EOF)
    {
        long long l = gcd(x,y);
        if(x*x < 4*y*l)
            printf("No Solution\n");
        else
        {
            long long ans = (x+sqrt(x*x-4*y*l))/2;
            long long cnt = x - ans;
            if(cnt+ans == x && cnt * ans / gcd(cnt,ans) == y)
                printf("%lld %lld\n",cnt,ans);
            else
                printf("No Solution\n");
        }
    }
    return 0;
}