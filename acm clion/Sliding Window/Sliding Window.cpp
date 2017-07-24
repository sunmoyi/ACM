//
// Created by 孙启龙 on 2017/4/25.
//

#include<cstdio>
#include<cstring>
#define maxn 1000010

using namespace std;

struct Elem{
    int val;
    int pos;
};

Elem maxque[maxn];
Elem minque[maxn];
int maxhead, minhead, maxtail, mintail;
int maxans[maxn];
int minans[maxn];
int cur;

int main (void)
{
    int n, w, num;
    scanf("%d%d", &n, &w);
    minhead = mintail = 0;
    maxhead = maxtail = 0;
    cur = 0;
    for (int i = 0; i < w; ++i)
    {
        scanf("%d", &num);

        while (minhead < mintail && minque[mintail - 1].val >= num)
            --mintail;
        minque[mintail].val = num;
        minque[mintail].pos = i;
        ++mintail;

        while (maxhead < maxtail && maxque[maxtail - 1].val <= num)
            --maxtail;
        maxque[maxtail].val = num;
        maxque[maxtail].pos = i;
        ++maxtail;
    }
    for (int i = w; i < n; ++i)
    {
        minans[cur] = minque[minhead].val;
        maxans[cur] = maxque[maxhead].val;
        ++cur;

        scanf("%d", &num);

        while (minhead < mintail && i - minque[minhead].pos >= w)
            ++minhead;
        while (minhead < mintail && minque[mintail - 1].val >= num)
            --mintail;
        minque[mintail].val = num;
        minque[mintail].pos = i;
        ++mintail;

        while (maxhead < maxtail && i - maxque[maxhead].pos >= w)
            ++maxhead;
        while (maxhead < maxtail && maxque[maxtail - 1].val <= num)
            --maxtail;
        maxque[maxtail].val = num;
        maxque[maxtail].pos = i;
        ++maxtail;
    }
    minans[cur] = minque[minhead].val;
    maxans[cur] = maxque[maxhead].val;
    ++cur;

    for (int i = 0; i < cur; ++i)
    {
        if (i > 0)
            putchar(' ');
        printf("%d", minans[i]);
    }
    printf("\n");
    for (int i = 0; i < cur; ++i)
    {
        if (i > 0)
            putchar(' ');
        printf("%d", maxans[i]);
    }
    printf("\n");

    return 0;
}