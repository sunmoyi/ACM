//
// Created by 孙启龙 on 2017/3/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <queue>

#define maxn 100010

using namespace std;

struct node{
    int val, pos;
    bool operator < (const node & rhs)const {
        return val < rhs.val || (val == rhs.val && pos > rhs.pos);
    }
}D[maxn];

priority_queue<node>q;

int n, d;

void solve()
{
    while(q.size())
        q.pop();
    int i;
    for(i = 0; i <= d; i++)
        q.push(D[i]);
    int Need = n - d, pre = -1;
    while(Need)
    {

        while(q.top().pos < pre)
            q.pop();
        const node &u = q.top();
        if(u.pos == n - Need)
        {
            for(i = u.pos; i < n; i++)
                printf("%d", D[i].val);
            break;
        }
        pre = u.pos;
        printf("%d", u.val);
        Need--;
        q.pop();
        q.push(D[i++]);
    }
    printf("\n");
}

int main (void)
{
    while(scanf("%d %d", &n, &d) != EOF && n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%1d", &D[i].val);
            D[i].pos = i;
        }
        solve();
    }
    return 0;
}