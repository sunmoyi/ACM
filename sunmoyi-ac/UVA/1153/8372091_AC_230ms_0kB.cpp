//
// Created by 孙启龙 on 2017/3/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 800010

using namespace std;

struct node{
    int l, r;
}a[maxn];
int T, n;

bool cmp(node&a, node&b)
{
    return a.r < b.r;
}

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &a[i].l, &a[i].r);
        sort(a, a + n, cmp);
        priority_queue<int>q;
        int ans = 0, timee = 0;
        for(int i = 0; i < n; i++)
        {
            q.push(a[i].l);
            int t = q.top();
            timee += a[i].l;
            ans++;
            if(timee > a[i].r)
            {
                timee -= t;
                q.pop();
                ans--;
            }
        }
        printf("%d\n", ans);
        if(T)
            printf("\n");
    }
    return 0;
}