//
// Created by 孙启龙 on 2017/7/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000000

using namespace std;

long long num[maxn];
long long n, m;
long long summ;
long long nowsum;
int start, endd;

int main (void)
{

   scanf("%lld %lld", &n, &m);

        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &num[i]);
            summ += num[i];
        }
        if(summ < m)
        {
            printf("Angry\n");
            return 0;
        }

        summ = 0;start = 1, endd = 1;
        while(summ < m)
        {
            summ += num[endd];
            endd++;
        }
        int ans = endd - start;
        while(summ >= m)
        {
            summ -= num[start];
            start++;
            while(summ < m)
            {
                summ += num[endd];
                endd++;
                if(endd == n + 2)
                    break;
            }
            ans = min(ans, endd - start);
        }
        printf("%d\n", ans);

    return 0;
}