//
// Created by 孙启龙 on 2017/4/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        priority_queue<long long ,vector<long long >, greater<long long> >Queue;

        for(int i=1;i<=n;i++)
        {
            long long  temp;
            scanf("%lld",&temp);
            Queue.push(temp);
        }

        long long  mincost=0;
        while(Queue.size()>1)
        {
            long long  a=Queue.top();
            Queue.pop();
            long long  b=Queue.top();
            Queue.pop();

            Queue.push(a+b);
            mincost+=a+b;
        }

        printf("%lld\n",mincost);

    }
    return 0;
}