//
// Created by 孙启龙 on 2017/3/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 10010

using namespace std;

struct P{
    int st, en, w;
    friend bool operator < (const P&a, const P&b)
    {
        return a.en > b.en;
    }
}p[maxn];
int n;

int cmp(P a, P b)
{
    return a.st < b.st;
}

bool judge(int x)
{
    priority_queue<P>Q;
    int t = 1, i = 0;
    while(1)
    {
        while(i < n && t >= p[i].st)
            Q.push(p[i++]);
        int re = x;
        while(re != 0 && !Q.empty())
        {
            P u = Q.top();
            Q.pop();
            int temp = min(re, u.w);
            re -= temp;
            u.w -= temp;
            if(u.w != 0)
                Q.push(u);
        }
        t++;
        if(!Q.empty() && Q.top().en <= t)
            return false;
        if(Q.empty() && i == n)
            return true;
    }
}

int main (void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int l = 0, r = maxn;
        for(int i = 0; i < n; i++)
            scanf("%d %d %d", &p[i].st, &p[i].en, &p[i].w);
        sort(p, p + n, cmp);
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(judge(mid))
                r = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}