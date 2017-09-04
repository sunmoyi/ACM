//
// Created by 孙启龙 on 2017/8/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

char map[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dirr[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
int n, m;

bool dfs1(int x, int y)
{
    vis[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(xx < 1 || xx > n || yy < 1 || yy > m)
            return false;
        if(vis[xx][yy])
            continue;
        if(map[xx][yy] == '1')
            continue;
        if(!dfs1(xx, yy))
            return false;
    }
    return true;
}

void dfs2(int x, int y)
{
    vis[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int xx = dir[i][0] + x;
        int yy = dir[i][1] + y;
        if(xx < 1 || xx > n || yy < 1 || yy > m)
            continue;
        if(vis[xx][yy])
            continue;
        if(map[xx][yy] != '1')
            continue;
        dfs2(xx, yy);
    }
}

int main(void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        bool flag = false;
        for(int i = 1; i <= n; i++)
        {
            getchar();
            for (int j = 1; j <= m; j++)
            {
                scanf("%c", &map[i][j]);
                if(map[i][j] == '1')
                    flag = true;
            }
        }
        if(!flag)
        {
            printf("-1\n");
            continue;
        }

        memset(vis, false, sizeof(vis));
        int ans1 = 0, ans2 = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(!vis[i][j] && map[i][j] == '1')
                    dfs2(i, j), ans1++;
            }
        }
        if(ans1 >= 2)
        {
            printf("-1\n");
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
               if(map[i][j] == '0' && !vis[i][j] && dfs1(i, j))
                   ans2++;
            }
        }
        if(ans2 == 0)
            printf("1\n");
        else if (ans2 == 1)
            printf("0\n");
        else
            printf("-1\n");
    }
    return 0;
}