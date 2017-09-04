//
// Created by 孙启龙 on 2017/8/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

bool flag;
int n, T, num;

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        flag = false;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num);
            int ans = num % (n * (n - 1));
            if(ans >= 1 && ans < n)
                continue;
            flag = true;
        }
        if(flag)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}