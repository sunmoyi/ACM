//
// Created by 孙启龙 on 2017/4/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 100010

using namespace std;

struct node{
    long long pos;
    long long len;
    bool friend operator < (const node&a, const node&b)
    {
        if(a.pos != b.pos)
            return a.pos > b.pos;
        else
            return a.len > b.len;
    }
}stone[maxn], now;
priority_queue<node>que;
int n, T;

int main (void)
{
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            bool odd = true;
            long long ans = 0;
            while(!que.empty())
                que.pop();
            scanf("%d", &n);
            for(int i = 1; i <= n; i++)
            {
                scanf("%lld %lld", &stone[i].pos, &stone[i].len);
                que.push(stone[i]);
            }

            while(!que.empty())
            {
                if(odd)
                {
                    now = que.top();
                    que.pop();
                    now.pos += now.len;
                    ans = max(ans, now.pos);
                    que.push(now);
                    odd = !odd;
                } else{
                    odd = !odd;
                    now = que.top();
                    ans = max(ans, now.pos);
                    que.pop();
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}