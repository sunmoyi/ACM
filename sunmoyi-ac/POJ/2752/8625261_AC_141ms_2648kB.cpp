//
// Created by 孙启龙 on 2017/4/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

char P[maxn];
int nextt[maxn];
int ans[maxn];

void MakeNext()
{
    int q, k;
    int m = strlen(P);
    nextt[0] = 0;
    for(q = 1, k = 0; q < m; q++)
    {
        while(k > 0 && P[q] != P[k])
            k = nextt[k - 1];
        if(P[q] == P[k])
            k++;
        nextt[q] = k;
    }
}

int main (void)
{
    while(scanf("%s", P) != EOF)
    {
        MakeNext();
        int len = (int)strlen(P);
        int k = 0;
        for(int i = len; i != 0; )
        {
            ans[k++] = nextt[i - 1];
            i = nextt[i - 1];
        }

        for(int i = k - 2; i >= 0; i--)
            printf("%d ", ans[i]);
        printf("%d\n", len);
    }
    return 0 ;
}