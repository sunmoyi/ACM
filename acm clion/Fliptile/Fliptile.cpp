//
// Created by 孙启龙 on 2017/4/25.
//
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int map[20][20];
int hit[20][20],ahit[20][20];
int ans,r,c;
const int inf=1<<30;

void on(int x,int y)
{
    hit[x][y]^=1;
    map[x][y]^=1;
    map[x-1][y]^=1;
    map[x+1][y]^=1;
    map[x][y+1]^=1;
    map[x][y-1]^=1;
}

void solve(int k,int cnt)
{
    if(cnt >= ans)
        return;
    int i;
    if(k==r)
    {
        for(i=1;i<=c;i++)
            if(map[r][i]!=0)
                break;
        if(i<=c)
            return;
        ans=cnt;
        memcpy(ahit,hit,sizeof(hit));
        return;
    }
    for(int i=1;i<=c;i++)
        if(map[k][i])
            on(k+1,i),cnt++;
    solve(k+1,cnt);
    for(int i=1;i<=c;i++)
        if(hit[k+1][i])
            on(k+1,i);
}

void dfs(int k,int cnt)
{
    if(cnt >= ans)
        return;
    else if(k == c+1)
    {
        solve(1,cnt);
        return;
    }
    else
    {
        dfs(k+1,cnt);
        on(1,k);
        dfs(k+1,cnt+1);
        on(1,k);
    }
}

int main()
{
    while(scanf("%d%d",&r,&c)!=EOF)
    {
        ans=inf;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                scanf("%d",&map[i][j]);
                hit[i][j]=0;
            }
        }
        dfs(1,0);
        if(ans==inf)
            printf("IMPOSSIBLE\n");
        else
        {
            for(int i=1;i<=r;i++)
            {
                for(int j=1;j<=c;j++)
                {
                    if(j!=1)
                        printf(" ");
                    printf("%d",ahit[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}