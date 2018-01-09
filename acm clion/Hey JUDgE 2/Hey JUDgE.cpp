//
// Created by 孙启龙 on 2017/8/18.
//

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 11
char s[maxn];
int T,num[maxn];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(num,0,sizeof(num));
        scanf("%s",s);
        int gg=0;
        for(int i=0;i<7;i++)num[s[i]-'A'+1]++;
        for(int i=1;i<=5;i++)
            if(!num[i])gg=1;
        if(gg)
        {
            for(int i=0;i<7;i++)
                for(int j=i+1;j<7;j++)
                {
                    int a=s[i]-'A'+1,b=s[j]-'A'+1,flag=1;
                    num[a]--,num[b]--,num[a+b]++;
                    for(int k=1;k<=5;k++)
                        if(!num[k])flag=0;
                    if(flag)gg=0;
                    num[a]++,num[b]++,num[a+b]--;
                }
            if(gg)
            {
                for(int i=0;i<7;i++)
                    for(int j=i+1;j<7;j++)
                        for(int ii=0;ii<7;ii++)
                            for(int jj=ii+1;jj<7;jj++)
                                if(i!=ii&&i!=jj&&j!=ii&&j!=jj)
                                {
                                    int a=s[i]-'A'+1,b=s[j]-'A'+1,c=s[ii]-'A'+1,d=s[jj]-'A'+1,flag=1;
                                    num[a]--,num[b]--,num[a+b]++;
                                    num[c]--,num[d]--,num[c+d]++;
                                    for(int k=1;k<=5;k++)
                                        if(!num[k])flag=0;
                                    if(flag)gg=0;
                                    num[a]++,num[b]++,num[a+b]--;
                                    num[c]++,num[d]++,num[c+d]--;
                                }
            }
        }
        printf("%s\n",gg?"NO":"YES");
    }
    return 0;
}