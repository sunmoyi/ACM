//
// Created by 孙启龙 on 2016/11/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500005

using namespace std;

int num[maxn];

void swap(int a, int b)
{
    int temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}

void init()
{
    for(int i = 1; i < maxn; i++)
        num[i] = i;
}

bool isok()
{
    for(int i = 0; i < maxn; i++)
        if(num[i] != i)
            return false;
    return true;
}

int main (void)
{
    int n, i, a, b;
    while(scanf("%d", &n) != EOF && n)
    {
        init();
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            swap(a, b);
        }
        if(isok())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}