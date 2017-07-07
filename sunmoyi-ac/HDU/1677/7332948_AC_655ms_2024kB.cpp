//
// Created by 孙启龙 on 16/10/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20010
#define INF 1000000

using namespace std;

struct node{
    int w, h;
}node[maxn], dp[maxn];

bool cmp(struct node a, struct node b)
{
    if(a.w != b.w)
        return a.w > b.w;
    return a.h < b.h;
}

int main (void)
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &node[i].w, &node[i].h);
            dp[i].w = dp[i].h = INF;
        }
        sort(node, node + n, cmp);

        for(int i = 0; i < n; i++)
        {
            int j = 0;
            while(dp[j].w <= node[i].w || dp[j].h <= node[i].h)
                j++;
            dp[j].w = node[i].w;
            dp[j].h = node[i].h;
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
            if(dp[i].h != INF)
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}