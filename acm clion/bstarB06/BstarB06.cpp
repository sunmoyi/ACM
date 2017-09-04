//
// Created by 孙启龙 on 2017/8/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 100010

using namespace std;

struct node{
    long long l, r;

}qu[maxn];
long long n, m;

bool cmp(node &a, node &b)
{
    if(a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
}

int main (void)
{
    while(scanf("%I64d %I64d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%I64d %I64d", &qu[i].l, &qu[i].r);
        sort(qu, qu + n, cmp);

        queue<long long>Q;
        long long ans = 0, cost = 0, get = qu[0].r - qu[0].l + 1;
        long long used = 0, endd = 0;
        long long startpos = qu[0].l, endpos = qu[0].r;
        while(cost + used <= m && endd < n)
        {
            ans += get;
            used += cost;
            endpos = max(qu[endd].r, endpos);
            Q.push(endd++);
            cost = qu[endd].l - endpos - 1;
            if(cost < 0)
                cost = 0;
            get = qu[endd].r - endpos;
            if(get < 0)
                get = 0;
        }

        long long temp = ans;
        ans = max(ans, ans + (m - used));
        while(endd < n)
        {
            endpos = qu[endd].r;
            temp += get;
            used += cost;
            Q.push(endd++);
            cost = qu[endd].l - endpos - 1;
            if(cost < 0)
                cost = 0;
            get = qu[endd].r - endpos;
            if(get < 0)
                get = 0;
            while(used > m)
            {
                long long front = Q.front();
                Q.pop();
                long long del = qu[front + 1].l - qu[front].l;
                if(del < 0)
                    del = 0;
                long long recost = qu[front + 1].l - qu[front].r - 1;
                if(recost  < 0)
                    recost = 0;
                temp -= del;
                used -= recost;
            }
            ans = max(ans, temp);
            ans = max(ans, temp + (m - used));
        }
        ans = max(ans, temp + (m - used));
        printf("%I64d\n", ans);
    }
    return 0;
}