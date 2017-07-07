//
// Created by 孙启龙 on 2017/3/11.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int f(int n)
{
    return n == 1? 1: f(n / 2) + 1;
}

int main (void)
{
    int n;
    while(scanf("%d", &n) == 1)
        printf("%d\n", f(n));
    return 0;
}