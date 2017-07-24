//
// Created by 孙启龙 on 2017/4/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 510

using namespace std;

int T;
int n, t;
int num1[maxn];
int num2[maxn];

bool cmp(int a, int b)
{
    return a > b;
}

int main (void)
{
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%d %d", &n, &t);
            for(int i = 1; i <= n; i++)
            {
                scanf("%d", &num1[i]);
                num1[i] -= t;
            }
            for(int i = 1; i <= n; i++)
                scanf("%d", &num2[i]);

            long long ans = 0;
            sort(num1 + 1, num1 + n + 1);
            sort(num2 + 1, num2 + n + 1, cmp);
            for(int i = 1; i <=n; i++)
            {
                if(num1[i] + num2[i] > 0)
                    ans += num1[i] + num2[i];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}