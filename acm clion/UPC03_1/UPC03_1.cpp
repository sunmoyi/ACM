//
// Created by 孙启龙 on 2017/7/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, k;
int s[105][105], sum[105][105][3];
int vis[105][105][3];
int a[4][2] = {{-1, 0},{0, -1}, {1, 0}, {0, 1}};
int ans = 0x3f3f3f3f;
int xx, yy, stepp, costt;
struct node {
    int x, y, step, sum1;
};

inline bool check(int x, int y)
{
    if (x > n || x < 1 || y > n || y < 1)
        return false;
    return true;
}

void dfs(int x, int y, int step, int cost)
{
    printf("%d %d %d %d\n", x, y, step, cost);
    for(int i = 0; i < 4; i++)
    {
        xx = x + a[i][0];
        yy = y + a[i][1];
        if(!check(xx, yy))
            continue;
        costt = cost + k;
        stepp = step + 1;
        if(stepp == 3)
            stepp = 0, costt += s[xx][yy];
        if(vis[xx][yy][stepp])
            continue;
        if(costt > ans)
            continue;
        if(xx == n && yy == 1)
        {
            ans = stepp;
            continue;
        }
        vis[xx][yy][stepp] = true;
        dfs(xx, yy, stepp, costt);
        vis[xx][yy][stepp] = false;
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &s[i][j]);
    memset(vis, false, sizeof(false));
    dfs(1, n, 0, 0);
    printf("%d\n", ans);
    return 0;
}