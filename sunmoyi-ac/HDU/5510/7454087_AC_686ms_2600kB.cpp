/*
题意：让求下标最大的i使得Si前面的串有不是其子串的
思路：暴力kmp
KMP 577MS
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;

char str[505][2005];
int Next[5005],vis[5005];

void Getfail(char *p)
{
    int m = strlen(p);
    int i = 0, j = -1;
    Next[0] = -1;
    while(i < m)
    {
        if(j == -1 || p[i] == p[j])
            Next[++i] = ++j;
        else
            j = Next[j];
    }
}
int KMP(char *p,char *s)
{
    Getfail(p);
    int m = strlen(p),n = strlen(s);
    int i = 0,j = 0,ans = 0;
    while(i < n)
    {
        if(j == -1)
            i++,j++;
        if(s[i] == p[j])
        {
            if(j == m-1)
                return 1;
            else
                i++,j++;
        }
        else
            j = Next[j];
    }
    return 0;
}
int main()
{
    int t,n;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%s",str[i]);
        printf("Case #%d: ",ca);
        memset(vis,0,sizeof(vis));
        int pos = -1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= i-1;j++)
            {
                if(vis[j])
                    continue;
                if(!KMP(str[j],str[i]))
                    pos = i;
                else
                    vis[j] = 1;
            }
        }
        printf("%d\n",pos);
    }
}
