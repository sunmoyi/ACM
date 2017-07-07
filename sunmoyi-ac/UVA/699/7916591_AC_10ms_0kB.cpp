//
// Created by 孙启龙 on 2017/1/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200

using namespace std;

int sum[maxn];

void build(int p)
{
    int v;
    scanf("%d", &v);
    if(v == -1)
        return;
    sum[p] += v;
    build(p - 1);
    build(p + 1);
}

bool init()
{
    int v;
    scanf("%d", &v);
    if(v == -1)
        return false;
    memset(sum, 0, sizeof(sum));
    int pos = maxn / 2;
    sum[pos] = v;
    build(pos - 1);
    build(pos + 1);
    return true;
}

int main (void)
{
    int kase = 0;
    while(init())
    {
        int p = 0;
        while(sum[p] == 0)
            p++;

        printf("Case %d:\n", ++kase);
        printf("%d", sum[p++]);
        while(sum[p])
            printf(" %d", sum[p++]);
        printf("\n\n");
    }
    return 0;
}