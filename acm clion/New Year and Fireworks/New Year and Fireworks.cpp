//
// Created by 孙启龙 on 2017/1/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool vis[310][310][8][6][32], mp[310][310];
int f[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}}, a[32], n;

void dfs(int x, int y, int fa, int cur, int nl)
{
    if(vis[x][y][fa][cur][nl] || nl > n)
        return;
    vis[x][y][fa][cur][nl] = 1;
    mp[x][y] = 1;
    if(cur)
        dfs(x + f[fa][0], y + f[fa][1], fa, cur - 1, nl);
    else
    {
        dfs(x, y, (fa + 1) % 8, a[nl + 1], nl + 1);
        dfs(x, y, (fa - 1 + 8) % 8, a[nl + 1], nl + 1);
    }
}

int main (void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = 0;
    dfs(150, 150, 0, a[1] - 1, 1);
    for(int i = 0; i <= 300; i++)
        for(int j = 0; j <= 300; j++)
            if(mp[i][j])
                ans++;
    printf("%d\n", ans);
}