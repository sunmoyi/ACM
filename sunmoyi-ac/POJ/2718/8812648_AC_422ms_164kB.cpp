//
// Created by 孙启龙 on 2017/4/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 15
#define abs(x) ((x) > 0? (x): (-(x)))

using namespace std;

int a[maxn], vis[maxn], n, ans, aa, bb;

void solve(int aa)
{
    int len = 0, flag = 1, b[15];
    bb = 0;
    for(int i = 0; i < n; i++)
        if(!vis[i])
            b[len++] = a[i];
    for(int i = 0; i < len; i++)
    {
        if(i == 0 && b[i] == 0)
            flag = 0;
        bb = bb * 10 + b[i];
    }
    if(flag)
        ans = min(ans, abs(aa - bb));
    while(next_permutation(b, b + len))
    {
        bb = 0;
        flag = 1;
        for(int i = 0; i < len; i++)
        {
            if(i == 0 && b[i] == 0)
                flag = 0;
            bb = bb * 10 + b[i];
        }
        if(flag)
            ans = min(ans, abs(aa - bb));
    }
    return ;
}

void dfs(int k, int res)
{
    if(k == n / 2)
    {
        solve(res);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            if(a[i] == 0 && k == 0)
                continue;
            vis[i] = 1;
            dfs(k + 1, res * 10 + a[i]);
            vis[i] = 0;
        }
    }
}

int main (void)
{
    int kase;
    scanf("%d", &kase);
    getchar();
    while(kase--)
    {
        n = 0;
        char ch;
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        while((ch = getchar()) != '\n')
        {
            if(ch == ' ')
                continue;
            else
                a[n++] = ch - '0';
        }
        if(n == 2 && a[0] == 0)
        {
            printf("%d\n", a[1] - a[0]);
            continue;
        }
        ans = 1 << 30;
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
