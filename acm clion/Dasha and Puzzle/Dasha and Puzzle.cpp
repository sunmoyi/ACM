//
// Created by 孙启龙 on 2017/2/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1010

using  namespace std;

int dira[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dui[10] = {2, 3, 0 ,1};
int d[maxn];
long long ans[maxn][2];
int n;
vector<int>edge[maxn];

void dfs(int now, int from, long long x, long long y, long long len, int formdir)
{
    int dir = 0;
    ans[now][0] = x;
    ans[now][1] = y;
    for(int i = 0; i < edge[now].size(); i++)
    {
        int v = edge[now][i];
        if(v == from)
            continue;
        if(formdir != -1 && dir == dui[formdir])
            dir++;
        dfs(v, now, x + dira[dir][0] * len, y + dira[dir][1] * len, len >> 1, dir);
        dir++;
    }
}

int main (void)
{
    scanf("%d", &n);

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if (d[i] > 4)
        {
            printf("NO\n");
            return 0;
        }
    }
    dfs(1, -1, 0, 0, 1LL << 58, -1);
    printf("YES\n");
    for(int i = 1; i <= n; i++)
        printf("%I64d %I64d\n", ans[i][0], ans[i][1]);
    return 0;
}