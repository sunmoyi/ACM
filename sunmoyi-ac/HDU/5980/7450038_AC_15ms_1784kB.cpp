//
// Created by 孙启龙 on 2016/11/7.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110000

using namespace std;

long long num[maxn];
int sum;
int ans;

int main (void)
{
    while(scanf("%d", &sum) != EOF)
    {
        ans = 0;
        for(int i = 1; i <= sum; i++)
        {
            scanf("%lld", &num[i]);
        }
        for(int i = 1; i <= sum; i++)
        {
            while(num[i] > 0)
            {
                if(num[i] % 256 == 97)
                    ans++;
                num[i] = num[i] >> 8;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}