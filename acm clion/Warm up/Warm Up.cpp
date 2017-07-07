//
// Created by 孙启龙 on 2016/11/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010

using namespace std;

int n, num1[maxn], num2[maxn];

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &num1[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &num2[i]);
        sort(num1 + 1, num1 + n + 1);
        sort(num2 + 1, num2 + n + 1);
        for(int i = 1; i <= n; i++)
            num1[i] -= num1[1];
        for(int i = 1; i <= n; i++)
            num2[i] -= num2[1];

        bool flag = true;
        for(int i = 1; i <= n; i++)
            if(num1[i] != num2[i])
                flag = false;
        if(flag)
            printf("possible\n");
        else
            printf("impossible\n");
    }
    return 0;
}