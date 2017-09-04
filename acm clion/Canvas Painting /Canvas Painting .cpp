//
// Created by 孙启龙 on 2017/8/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> >Q;

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        while(!Q.empty())
            Q.pop();
        for(int i = 1; i <= n; i++)
        {
            long long x;
            scanf("%lld", &x);
            Q.push(x);
        }

        long long ans = 0;
        while(Q.size() > 1)
        {
            long long a = Q.top(); Q.pop();
            long long b = Q.top(); Q.pop();
            ans += a + b;
            Q.push(a + b);
        }

        printf("%lld\n", ans);
    }
    return 0;
}