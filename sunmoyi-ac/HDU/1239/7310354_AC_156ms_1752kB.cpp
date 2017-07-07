//
// Created by 孙启龙 on 16/10/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int prime[5000], k, m, a, b, w, h;
int num[10011];

int main (void)
{
    memset(num, 0, sizeof(num));
    num[0]  = num[1] = 1;
    k = 0;
    for(int i = 2; i <= 10000; i++)
    {
        if(num[i] == 0)
        {
            for(int t = 2 * i; t <= 10000; t += i)
                num[t] = 1;
            prime[k] = i;
            k++;
        }
    }

    while(scanf("%d %d %d", &m, &a, &b) != EOF && (m != 0 || a != 0 || b != 0))
    {
        double rate = a * 1.0/ b;
        int maxx = 0;
        for(int i = k - 1; i >= 0; i--)
        {
            for(int l = i; l >= 0; l--)
            {
                if(prime[i] * prime[l] > m || (prime[l] * 1.0 / prime[i]) < rate)
                    continue;
                if(prime[i] * prime[l] > maxx)
                {
                    maxx = prime[i] * prime[l];
                    w = prime[l];
                    h = prime[i];
                }
            }
        }
        printf("%d %d\n", w, h);
    }
    return 0;
}