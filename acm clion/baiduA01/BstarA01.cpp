//
// Created by 孙启龙 on 2017/8/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <cmath>

using namespace std;

int n, p;

int main (void)
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &p);
        p--;
        int sqrtp = sqrt(p * 1.0);
        int ans = 0;
        if(p == sqrtp * sqrtp)
        {
            for(int i = 1; i <= sqrtp; i++)
                if(p % i == 0)
                    ans++;

            printf("%d\n", ans * 2 - 1);
        }
        else
        {
            for(int i = 1; i <= sqrtp; i++)
                if(p % i == 0)
                    ans++;
            printf("%d\n", ans * 2);
        }
    }
    return 0;
}