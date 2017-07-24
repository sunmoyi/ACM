//
// Created by 孙启龙 on 2017/5/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 400010

using namespace std;

char str[maxn];
int nextt[maxn];
int len, ans[maxn];

void GetNext()
{
    memset(nextt, 0, sizeof(nextt));
    len = (int)strlen(str);
    nextt[0] = -1;
    int i = 0, j = -1;
    while(i < len)
    {
        if(j == -1 || str[i] == str[j])
        {
            i++;
            j++;
            nextt[i] = j;
        }
        else
            j = nextt[j];
    }
}

int main (void)
{
    while(scanf("%s", str) != EOF)
    {
        GetNext();
        int j = nextt[len];
        int cnt = 0;
        while(j > 0)
        {
            ans[cnt++] = j;
            j = nextt[j];
        }
        for(int i = cnt - 1; i >= 0; i--)
        {
            printf("%d ", ans[i]);
        }
        printf("%d\n", len);
    }
    return 0;
}