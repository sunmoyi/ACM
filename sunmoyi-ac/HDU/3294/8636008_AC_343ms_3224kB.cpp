//
// Created by 孙启龙 on 2017/4/2.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 4e5+100;
int len1,len2,p[maxn];
char s[maxn],str[maxn];

void init()
{
    str[0] = '$';
    str[1] = '#';
    for(int i=0;i<len1;i++)
    {
        str[i*2+2] = s[i];
        str[i*2+3] = '#';
    }
    len2 = len1*2 + 2;
    str[len2] = '*';
}

void manacher()
{
    int id = 0,mx = 0;
    for(int i=0;i<len2;i++)
    {
        if(mx>i)p[i] = min(p[id*2-i],mx-i);
        else p[i] = 1;
        for(;str[i-p[i]]==str[i+p[i]];p[i]++);
        if(p[i]+i>mx)
        {
            mx = p[i] + i;
            id = i;
        }
    }
}



int main()
{  
    cin.tie(0);
    char c[5];
    while(~scanf("%s%s",c,s))
    {
        int cnt = c[0] - 'a';
        len1 = strlen(s);
        init();
        manacher();
        int ans = 0,l,r;
        for(int i=0;i<len2;i++)
        {
            if(p[i]>ans)
            {
                ans = p[i];
                l = (i-p[i])/2;
                r = (i+p[i])/2-2;
            }
        }
        if(ans==2)cout<<"No solution!"<<endl;
        else
        {
            cout<<l<<" "<<r<<endl;
            for(int i=l;i<=r;i++)
            {
                printf("%c",(s[i]-'a'-cnt+26)%26+'a');
            }
            cout<<endl;
        }
    }


    return 0;
}  