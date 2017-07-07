//
// Created by 孙启龙 on 2017/4/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

char P[maxn];
int T, len, nextt[maxn];

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
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", P);
        len = (int)strlen(P);
        make_next();

        //for (int i = 0; i < len; i++)
        //	printf("%d %d\n", i, nextt[i]);
        int rata = (len) - (nextt[len - 1]);
        if(len % rata == 0 && (len / rata) >= 2)
            printf("0\n");
        else
            printf("%d\n", rata - len % rata);
    }
    return 0;
}