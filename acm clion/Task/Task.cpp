//
// Created by 孙启龙 on 2017/4/17.
//

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100000+10;
int level[100+10];
int n,m,sum;
long long ans;

struct P
{
    int xi,yi;
}machine[maxn],task[maxn];


bool cmp(P a,P b)
{
    if(a.xi==b.xi)
        return a.yi>b.yi;
    return a.xi>b.xi;
}

void read_data()
{
    for(int i=1;i<=n;i++)
        scanf("%d%d",&machine[i].xi,&machine[i].yi);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&task[i].xi,&task[i].yi);
    sort(task+1,task+1+m,cmp);
    sort(machine+1,machine+1+n,cmp);
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        ans=sum=0;
        read_data();
        memset(level,0,sizeof(level));
        for(int i=1,j=1;i<=m;i++)
        {
            while(j<=n && machine[j].xi >= task[i].xi)
            {
                level[machine[j].yi]++;
                j++;
            }
            for(int k=task[i].yi;k<=100;k++)
            {
                if(level[k])
                {
                    level[k]--;
                    ans=ans+500*task[i].xi+2*task[i].yi;
                    sum++;
                    break;
                }
            }
        }
        printf("%d %lld\n",sum,ans);
    }
    return 0;
}