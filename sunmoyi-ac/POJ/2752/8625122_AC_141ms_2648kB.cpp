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
    int i = 0, j = -1;
    nextt[0] = -1;
    int len = strlen(P);
    while (i < len)
    {
        if (j == -1 ||P[i] == P[j])
        {
            ++i;
            ++j;
            nextt[i] = j;
        }
        else
            j = nextt[j];
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
            ans[k++] = nextt[i];
            i = nextt[i];

        }

        for(int i = k - 2; i >= 0; i--)
            printf("%d ", ans[i]);
        printf("%d\n", len);
    }
    return 0;
}