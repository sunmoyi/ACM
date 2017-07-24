//
// Created by 孙启龙 on 2017/2/9.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, p[200100];
int b[200100], vis[200200];

void dfs(int u)
{
    vis[u] = 1;
    if(!vis[p[u]])
        dfs(p[u]);
}

int main (void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        if(b[i] & 1)
            cnt++;
    }
    int ans = 0;
    if(cnt % 2 == 0)
        ans++;
    cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i);
        }
    }
    if(cnt == 1)
        cnt = 0;
    printf("%d\n", ans + cnt);
    return 0;
}