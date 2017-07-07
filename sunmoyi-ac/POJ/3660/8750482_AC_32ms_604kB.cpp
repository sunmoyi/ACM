//
// Created by 孙启龙 on 2017/4/12.
//

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define INF 0xfffffff
#define N 1100
using namespace std;

int n,m;
int maps[N][N];

void Floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(maps[i][k]==1&&maps[k][j]==1)
                    maps[i][j]=1;
}

int main()
{
    int i,j,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                maps[i][j]=0;

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            maps[a][b]=1;
        }

        Floyd();

        int ans=0;
        for(i=1;i<=n;i++)
        {
            int k=0;
            for(j=1;j<=n;j++)
            {
                if(i==j)continue;

                if(maps[i][j]==1||maps[j][i]==1)
                    k++;
            }
            if(k==n-1)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}