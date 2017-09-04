//
// Created by 孙启龙 on 2017/8/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

int num[maxn], n;
int maxx;

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &num[i]);

        maxx = -1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                int num1 = num[i];
                int num2 = num[j];
                int ans = 0;
                while(num1 > 0 || num2 > 0)
                {
                    if((num1 & 1) != (num2 & 1))
                        ans++;
                    num1 >>= 1;
                    num2 >>= 1;
                }
                maxx = max(maxx, ans);
            }
        }
        printf("%d\n", maxx);
    }
    return 0;
}