//
// Created by 孙启龙 on 2017/7/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 25

using namespace std;

bool vis[maxn];
int n, m;
int ans[maxn];

void dfs(int pos, int num)
{
    if(pos == m + 1)
    {
        for(int i = 1; i <= m; i++)
            printf("%3d", ans[i]);
        printf("\n");
        return;
    }

    for(int i = num; i <= n; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            ans[pos] = i;
            dfs(pos + 1, i + 1);
            vis[i] = false;
        }
    }
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(vis, false, sizeof(vis));
        dfs(1, 1);
    }
    return 0;
}