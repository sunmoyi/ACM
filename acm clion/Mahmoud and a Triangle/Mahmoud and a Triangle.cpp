//
// Created by 孙启龙 on 2017/2/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[100010], n;

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        bool flag = false;
        for(int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        sort(num + 1, num + n + 1);
        for(int i = 1; i <= n - 2; i++)
            if(num[i] + num[i + 1] > num[i + 2])
                flag = true;
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}