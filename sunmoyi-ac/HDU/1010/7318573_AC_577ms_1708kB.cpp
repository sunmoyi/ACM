//
// Created by 孙启龙 on 16/10/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int sx, sy, ex, ey;
int n, m;
char map[10][10];
int flag, step;
int dir[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};

int abs(int a)
{
    if(a > 0)
        return a;
    else
        return -a;
}

void dfs(int x, int y, int t)
{
    if(flag == 1)
        return ;
    if(t < abs(ex - x) + abs(ey - y) || (t - abs(ex - x) - abs(ey - y)) % 2)
        return;
    else if(t == 0)
    {
        if(x == ex && y == ey)
        {
            flag = 1;
            return;
        }
        else
            return ;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx > 0 && nx <= n &&  ny > 0 && ny <= m && (map[nx][ny] == '.' || map[nx][ny] == 'D'))
        {
            map[nx][ny] = 'X';
            dfs(nx, ny, t - 1);
            map[nx][ny] = '.';
        }
    }
    return ;
}

int main (void)
{
    char str[10];
    int t;
    while(scanf("%d %d %d", &n, &m, &t) != EOF)
    {
        if(n == 0 && m == 0 && t == 0)
            break;
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", str);
            for(int j = 1; j <= m; j++)
            {
                map[i][j] = str[j - 1];
                if(map[i][j] == 'S')
                    sx = i, sy = j;
                if(map[i][j] == 'D')
                    ex = i, ey = j;
            }
        }
        flag = 0;
        dfs(sx, sy, t);
        if(flag == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}