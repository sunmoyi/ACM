//
// Created by 孙启龙 on 2017/4/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

char T[maxn];
int nextt[maxn];
bool vis[maxn];

void make_next()
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
        }
        else
            j = nextt[j];
    }
}

int main (void)
{
    scanf("%s", T);
    int len = strlen(T);
    make_next();

    memset(vis, false, sizeof(vis));
    for(int i = 1; i < len; i++)
        vis[nextt[i]] = true;

    int now = nextt[len];
    bool flag = false;
    while(now > 0)
    {
        if(vis[now])
        {
            flag = true;
            for(int i = 0; i < now; i++)
                printf("%c", T[i]);
            return 0;
        }
        now = nextt[now];
    }
    if(!flag)
        printf("Just a legend\n");
    return 0;
}