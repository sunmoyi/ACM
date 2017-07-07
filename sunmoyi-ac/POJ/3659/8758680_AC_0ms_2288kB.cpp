//
// Created by 孙启龙 on 2017/4/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define  maxn 100010
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int to;
    int next;
}e[1000010];
int tot;
int head[maxn];
int dp[maxn][3];
int n;
int v[maxn];

void add(int s, int u)
{
    e[tot].to = u;
    e[tot].next = head[s];
    head[s] = tot++;
}

// dp[r][0] = min(dp[i][0],dp[i][1],dp[i][2])自身建
// dp[r][1] = min(dp[i][0],dp[i][1]) + min(dp[k][0] - dp[k][1])子节点建
// dp[r][2] = min(dp[i][0],dp[i][1]) 父节点建
void dfs(int r)
{
    v[r] = 1;
    int i, k;
    int flag = 1, ff = 1, minn = INF, t;
    dp[r][0] = 1;
    for(i = head[r]; i; i = e[i].next)
    {
        k = e[i].to;
        if(!v[k])
        {
            flag = 0;
            dfs(k);
            dp[r][0] += min(dp[k][0], min(dp[k][1], dp[k][2]));
            if(dp[k][1] >= dp[k][0])
            {
                ff = 0;
                dp[r][1] += dp[k][0];
            }
            else
            {
                dp[r][1] += dp[k][1];
                if(dp[k][0] < minn)
                {
                    minn = dp[k][0];
                    t = dp[k][1];
                }
            }
            dp[r][2] += min(dp[k][0], dp[k][1]);
        }
    }
    if(ff)
        dp[r][1] += minn - t;
    if(flag)
    {
        dp[r][0] = 1;
        dp[r][1] = INF;
        dp[r][2] = 0;
    }
}

int main (void)
{
    int a, b;
    while(scanf("%d", &n) != EOF)
    {
        tot = 1;
        memset(v, 0, sizeof(v));
        memset(dp, 0, sizeof(dp));
        memset(head, 0, sizeof(head));
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            add(a, b);
            add(b, a);
        }
        if(n == 1)
        {
            printf("1\n");
            continue;
        }
        dfs(1);
        printf("%d\n", min(dp[1][0], dp[1][1]));
    }
    return 0;
}