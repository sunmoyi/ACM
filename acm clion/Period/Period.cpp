//
// Created by 孙启龙 on 2017/3/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

char P[maxn];
int nextt[maxn];
int n;

void make_next()
{
    int q, k;
    int m = strlen(P);
    nextt[0] = 0;
    for (q = 1, k = 0; q < m; ++q)
    {
        while (k > 0 && P[q] != P[k])
            k = nextt[k - 1];
        if (P[q] == P[k])
        {
            k++;
        }
        nextt[q] = k;
    }
}

int main (void)
{
    int Case = 0;
    while(scanf("%d", &n) != EOF && n)
    {
        scanf("%s", P);
        make_next();
        printf("Test case #%d\n", ++Case);
        for(int i = 1; i < n; i++)
        {
            //printf("-------%d %d\n", i, nextt[i]);
            if(nextt[i] > 0 && (i + 1) % (i + 1 - nextt[i]) == 0)
                printf("%d %d\n", i + 1, (i + 1) / (i + 1 - nextt[i]));
        }
        printf("\n");
    }
    return 0;
}