//
// Created by 孙启龙 on 2017/1/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

bool isprimer[1000010];
int n;

void prime()
{
    memset(isprimer, true, sizeof(isprimer));
    isprimer[1] = false;
    for(int i = 2; i < 1000010; i++)
    {
        if(isprimer[i])
        {
            for(int j = i + i; j <= 1000000; j += i)
                isprimer[j] = false;
        }
    }
}

bool check(int x)
{
    for(int i = 2; i <= sqrt(x * 1.0); i++)
    {
        if(x % i == 0)
        {
            int temp = x / i;
            if(isprimer[i] && isprimer[temp])
                return true;
        }
    }
    return false;
}

int main (void)
{
    prime();
    while(scanf("%d", &n) != EOF)
    {
        if(check(n))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}