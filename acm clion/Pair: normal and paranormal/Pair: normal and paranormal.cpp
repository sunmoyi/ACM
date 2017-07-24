//
// Created by 孙启龙 on 2017/4/30.
//
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int ans[50005];
char s[50005];
int num[50005];

int main()
{

    stack<int>q;
    int n;
    cin >> n;
    cin >> s;
    int cnt = 0;
    for(int i = 0; s[i]; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            num[i] = ++cnt;
        if(q.empty())
        {
            q.push(i);
        }
        else
        {
            int pos = q.top();
            if(s[pos] <= 'z' && s[pos] >= 'a' )
            {
                if(s[i] <= 'Z'&& s[i] >= 'A')
                {
                    if(s[i]+32!=s[pos])
                    {
                        q.push(i);
                    }
                    else
                    {
                        ans[i]=num[pos];
                        q.pop();
                    }
                }
                else
                    q.push(i);
            }
            else
            {
                if(s[i]<='z'&&s[i]>='a')
                {
                    if(s[i]-32!=s[pos])
                    {
                        q.push(i);
                    }
                    else
                    {
                        ans[pos]=num[i];
                        q.pop();
                    }
                }
                else
                    q.push(i);
            }
        }
    }
    if(!q.empty())
    {
        printf("Impossible\n");
    }
    else
    {
        int yes=0;
        for(int i=0;i<n*2;i++)
            if(ans[i]!=0)
            {
                if(yes)
                    printf(" ");
                yes=1;
                printf("%d",ans[i]);
            }
    }
    return 0;
}