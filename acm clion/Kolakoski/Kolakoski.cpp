//
// Created by 孙启龙 on 2017/10/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000010

using namespace std;

int a[maxn], x, o, p;

void init()
{
    a[1] = x = 1, a[2] = a[3] = 2, o = p = 3;
    while(p < maxn)
    {
        for(int i = 1; i <= a[o]; i++)
            a[++p] = x;
        x = 3 - x;
        o++;
    }
}

int main (void)
{
    init();
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}