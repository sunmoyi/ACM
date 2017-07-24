//
// Created by 孙启龙 on 2017/5/19.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300010

using namespace std;

int len;
char s1[maxn], s2[maxn], ans[maxn];

bool cmp1(char a, char b)
{
    return a < b;
}

bool cmp2(char a, char b)
{
    return a > b;
}

int main (void)
{
    scanf("%s %s", s1, s2);
    len = (int)strlen(s1);
    sort(s1, s1 + len, cmp1);
    sort(s2, s2 + len, cmp2);

    int i = 0;
    char *pl[2] = {s1, s2};
    for(;(i < len) && (*pl[0] < *pl[1]); i++)
        ans[i] = *(pl[i & 1]++);

    int j = len - 1;
    char *pr[2] = { s1 + (len + 1) / 2 - 1, s2 + (len) / 2 - 1 };
    for (; i < len; ++i, --j)
        ans[j] = *(pr[i & 1]--);

    ans[len] = '\0';
    printf("%s\n", ans);
    return 0;
}