//
// Created by 孙启龙 on 2017/1/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int sum;
int num[10000010];
int n, temp;

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        sum = 0;
        bool flag = false;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            sum += num[i];
            if(num[i] != 0)
                flag = true;
        }
        if(!flag)
            printf("NO\n");
        else
        {
            printf("YES\n");
            if(sum != 0)
            {
                printf("1\n");
                printf("%d %d\n", 1, n);
            }
            else
            {
                printf("2\n");
                int ans = 0, a = 1;
                while(ans == 0)
                    ans += num[a++];
                printf("1 %d\n", a - 1);
                printf("%d %d\n", a, n);
            }
        }
    }
    return 0;
}