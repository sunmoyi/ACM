//
// Created by 孙启龙 on 2016/10/27.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int map[25][5];
int vis[25];
int ans[25];
int cas = 1;
int n,m;

void dfs(int m,int len,int c)
{
    int i,j;
    vis[m] = 1;
    ans[len] = m;
    for(i = 0; i<3; i++)
    {
        int t = map[m][i];
        if(t == c && len == 19)
        {
            printf("%d:  ",cas++);
            for(j = 0; j<20; j++)
                printf("%d ",ans[j]);
            printf("%d\n",c);
        }
        if(!vis[t])
            dfs(t,len+1,c);
    }
    vis[m] = 0;
}

int main()
{
    int i;
    for(i = 1; i<=20; i++)
        scanf("%d%d%d",&map[i][0],&map[i][1],&map[i][2]);
    while(~scanf("%d",&m),m)
    {
        memset(vis,0,sizeof(vis));
        dfs(m,0,m);
    }

    return 0;
}