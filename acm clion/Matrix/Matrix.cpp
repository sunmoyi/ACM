//
// Created by 孙启龙 on 2017/4/22.
//

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int T,n,m,bit[1005][1005];
char s[10];

int sum(int a,int b)
{
    int s = 0;
    for(int i=a;i>0;i-=i&-i)
        for(int j=b;j>0;j-=j&-j)
            s+=bit[i][j];
    return s;
}

void add(int a,int b)
{
    for(int i=a;i<=n;i+=i&-i)
    {
        for(int j=b;j<=n;j+=j&-j)
        {
            bit[i][j]++;
        }
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(bit,0,sizeof(bit));
        while(m--)
        {
            scanf("%s",s);
            if(s[0]=='C')
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                add(x2+1,y2+1);
                add(x1,y1);
                add(x1,y2+1);
                add(x2+1,y1);
            }
            else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",sum(x,y)%2);
            }
        }
        if(T)
            printf("\n");
    }
    return 0;
}