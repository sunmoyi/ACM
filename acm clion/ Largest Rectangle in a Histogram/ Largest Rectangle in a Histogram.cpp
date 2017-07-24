//
// Created by 孙启龙 on 2017/4/23.
//

#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

struct Node
{
    long long val;
    long long len;
};

stack<Node> s;

int main()
{
    long long temp,Max,n,i,m;
    Node q;
    while(scanf("%I64d",&n)!=EOF)
    {
        if(n==0) break;
        Max=0;
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&q.val);
            q.len=1;
            temp=0;
            if(s.empty())
            {
                s.push(q);
            }
            else if(q.val<=(s.top()).val)
            {
                while(!s.empty()&&q.val<=(s.top().val))
                {
                    (s.top()).len+=temp;
                    m=(s.top()).val*(s.top()).len;
                    if(m>Max) Max=m;
                    temp=(s.top()).len;
                    s.pop();
                }
                q.len+=temp;
                s.push(q);
            }
            else
                s.push(q);
        }
        temp=0;
        while(!s.empty())
        {
            (s.top()).len+=temp;
            m=(s.top()).val*(s.top()).len;
            if(m>Max) Max=m;
            temp=(s.top()).len;
            s.pop();
        }
        cout<<Max<<endl;
    }
}