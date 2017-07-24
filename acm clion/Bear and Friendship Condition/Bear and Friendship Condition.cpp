//
// Created by 孙启龙 on 2017/3/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 150100

using namespace std;

int a[maxn], b[maxn], vis[maxn];
vector<int>vc[maxn];
long long t;

void dfs(int x)
{
    t++;
    vis[x] = 1;
    for(int j = 0; j < vc[x].size(); j++)
    {
        if(vis[vc[x][j]] == 0)
            dfs(vc[x][j]);
    }
}

int main (void)
{
    int n, m;
    int x, y;
    scanf("%d %d", &n, &m);
    memset(vis, 0, sizeof(vis));
    memset(b, 0, sizeof(b));
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        vc[x].push_back(y);
        vc[y].push_back(x);
        b[x] = 1;
        b[y] = 1;
    }
    long long sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0 && b[i])
        {
            t = 0;
            dfs(i);
            sum += t * (t - 1);
        }
    }
    if(2 * m == sum)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}