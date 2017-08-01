//
// Created by 孙启龙 on 2017/7/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000

using namespace std;

long long a, b;
int k;
long long a1, b1, x, y;
bool flag = false;

int main (void)
{
    int t = 0;
    scanf("%lld %lld %d", &a, &b, &k);
    if(a == b)
        printf("0\n"), flag = true;
    else
    {
        while(k--)
        {
            scanf("%lld %lld %lld %lld", &a1, &x, &b1, &y);
            a += (a1) * (x);
            if(a < 0)
                a = 0;
            b += (b1) * (y);
            if(b < 0)
                b = 0;
            t++;
            if(a == b)
            {
                printf("%d\n", t);
                flag = true;
                break;
            }
        }
    }
    if(!flag)
        printf("-1\n");
    return 0;
}