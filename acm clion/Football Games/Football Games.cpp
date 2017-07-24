//
// Created by 孙启龙 on 2017/7/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

int a[maxn];

bool cmp(int a, int b)
{
    return a > b;
}
int main (void)
{
    int t;
    while(scanf("%d", &t) != EOF)
    {
        while(t--)
        {
            int n;
            scanf("%d", &n);
            for(int i = 1; i <= n; i++)
                scanf("%d", &a[i]);
            int flag = 1, sum = 0, he = 2 * (n - 1);
            sort(a + 1, a + 1 + n, cmp);
            for(int i = 1; i <= n; i++)
            {
                sum += (he - a[i]);
                if(sum < 0)
                {
                    flag = 0;
                    break;
                }
                he -= 2;
            }
            if(sum == 0 && flag)
                printf("T\n");
            else
                printf("F\n");
        }
    }
    return 0;
}