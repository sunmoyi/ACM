//
// Created by 孙启龙 on 2017/3/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define maxn 60

using namespace std;

int n, d[maxn], res[maxn], pos[1000010], len, vis[maxn];

bool dfs(int cnt)
{
    if(cnt == len)
    {
        for(int i = 1; i <= n - 1; i++)
            if(!vis[i])
                return false;
        return true;
    }
    for(int i = 1; i <= cnt - 1; i++)
    {
        for(int j = 1; j <= n - 1; j++)
        {
            if(!vis[j])
            {
                int temp = res[i] + d[j];
                if(temp >= d[n] || temp <= res[cnt - 1])
                    continue;
                res[cnt] = temp;
                queue<int>q;
                for(int k = 1; k <= cnt; k++)
                {
                    temp = res[cnt] - res[k];
                    if(pos[temp] && !vis[pos[temp]])
                    {
                        vis[pos[temp]] = 1;
                        q.push(pos[temp]);
                    }
                }
                temp = d[n] - res[cnt];
                if(pos[temp] && !vis[pos[temp]])
                {
                    vis[pos[temp]] = 1;
                    q.push(pos[temp]);
                }
                if(dfs(cnt + 1))
                    return true;
                while(!q.empty())
                {
                    vis[q.front()] = 0;
                    q.pop();
                }
            }
        }
    }
    return false;
}

int main (void)
{
    int Case = 1;
    while(scanf("%d", &n) == 1 && n)
    {
        memset(vis, 0, sizeof(vis));
        memset(pos, 0, sizeof(pos));
        for(int i = 1; i <= n; i++)
            scanf("%d", &d[i]);
        sort(d + 1, d + n + 1);
        n = unique(d + 1, d + n + 1) - d - 1;
        for(int i = 1; i <= n; i++)
            pos[d[i]] = i;
        len = sqrt(2 * n) - 1;
        res[1] = 0;
        while(!dfs(2))
            len++;
        res[len] = d[n];
        printf("Case %d:\n", Case++);
        printf("%d\n", len);
        for(int i = 1; i <= len; i++)
            printf("%d ", res[i]);
        printf("\n");
    }
    return 0;
}