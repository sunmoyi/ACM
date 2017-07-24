//
// Created by 孙启龙 on 2017/3/31.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

char T[maxn], P[maxn];
int nextt[maxn];

void make_next(const char P[], int next[])
{
    int q, k;
    int m = strlen(P);
    next[0] = 0;
    for (q = 1, k = 0; q < m; ++q)
    {
        while (k > 0 && P[q] != P[k])
            k = next[k - 1];
        if (P[q] == P[k])
        {
            k++;
        }
        nextt[q] = k;
    }
}

int  KMP(const char T[], const char P[], int next[])
{
    make_next(P, nextt);
    int len1 = strlen(T), len2 = strlen(P), count = 0;
    for(int i = 0, q = 0; i < len1; i++)
    {
        while(q > 0 && P[q] != T[i])
            q = nextt[q - 1];
        if(P[q] == T[i])
            q++;
        if(q == len2)
        {
            count++;
            q = 0;
        }
    }
    return count;
}

int main (void)
{
    while(scanf("%s", T) != EOF && T[0] != '#')
    {
        scanf("%s", P);
        memset(nextt, 0, sizeof(nextt));
        printf("%d\n", KMP(T, P, nextt));
    }
    return 0;
}