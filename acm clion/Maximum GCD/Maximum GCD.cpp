//
// Created by 孙启龙 on 2017/4/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000

using namespace std;

long long num[maxn], T, temp;
char tempp;

long long gcd(long long a, long long b)
{
    return b == 0? a: gcd(b, a % b);
}

int main (void)
{
    while(scanf("%lld", &T) != EOF)
    {
        while(T--)
        {
            int sum = 1;
            while(1)
            {
                scanf("%lld", &num[sum++]);
                if(scanf("%c", &tempp) == EOF || tempp == '\n')
                    break;
            }
            long long ans = 1;
            for(int i = 1; i < sum; i++)
                for(int j = i + 1; j < sum; j++)
                {
                    long long a = max(num[i], num[j]);
                    long long b = min(num[i], num[j]);
                    ans = max(ans, gcd(a, b));
                }
            printf("%lld\n", ans);
        }
    }
}