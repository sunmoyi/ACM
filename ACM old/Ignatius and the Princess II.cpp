//
// Created by 孙启龙 on 2016/10/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10010

using namespace std;

int num[maxn];
bool vis[maxn], flag;
int n, m;
int sum;

void dfs(int cur)
{

    if(flag)
        return;

    if(cur == n + 1)
    {
        sum++;
        if(sum == m)
        {
            for(int i = 1; i < n; i++)
                printf("%d ", num[i]);
            printf("%d\n", num[n]);
            flag = true;
            return;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            num[cur] = i;
            dfs(cur + 1);
            vis[i] = false;
        }
    }
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        flag = false;
        memset(vis, 0, sizeof(vis));
        sum = 0;
        dfs(1);
    }
    return 0;
}