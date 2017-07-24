//
// Created by 孙启龙 on 2017/4/9.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

int nextt[maxn];
char S[maxn], T[maxn];
bool vis[maxn];

void GetNext(const char *T)
{
    int i = 0, j = -1;
    nextt[0] = -1;
    int len = strlen(T);
    while(i < len)
    {
        if(j == -1 || T[i] == T[j])
        {
            i++;
            j++;
            nextt[i] = j;
            if(i != len)
                vis[nextt[i]] = 1;
        }
        else
            j = nextt[j];
    }
}

int main (void)
{
    scanf("%s", T);
    int len = strlen(T);
    memset(vis, 0, sizeof(vis));
    GetNext(T);

    int now = nextt[len];
    bool flag = false;
    while(now > 0)
    {
        if(vis[now])
        {
            flag = true;
            for(int i = 0; i < now; i++)
                printf("%c", T[i]);
            printf("\n");
            break;
        }
        now = nextt[now];
    }
    if(!flag)
    {
        printf("Just a legend\n");
    }
    return 0;
}