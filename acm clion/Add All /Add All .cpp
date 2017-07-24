//
// Created by 孙启龙 on 2017/2/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<functional>
#define maxn 10000

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> >q;
int n;
long long temp;

int main (void)
{
    while(scanf("%d", &n) != EOF && n)
    {
        while(!q.empty())
                q.pop();
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &temp);
                q.push(temp);
        }
        long long ans = 0;
        long long sum = 0;
        while(q.size() >= 2)
        {
            long long a = q.top();
            q.pop();
            long long b = q.top();
            q.pop();
            sum = a + b;
            q.push(sum);
            ans += sum;
        }
        printf("%lld\n", ans);
    }
    return 0;
}