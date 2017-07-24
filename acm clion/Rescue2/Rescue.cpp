//
// Created by 孙启龙 on 2017/5/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 210

using namespace std;

char map[maxn][maxn];
int a[1000000], step, sum, n, m;
int vis[maxn][maxn];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


void DFS(int x, int y)
{
    int i, mx, my;
    if (map[x][y] == 'r')
        a[sum++] = step;
    else if (map[x][y] != '#')
    {
        for (i = 0; i < 4; i++)
        {
            mx = x + dir[i][0];
            my = y + dir[i][1];
            if (map[mx][my] != '#' && mx >= 1 && mx <= n&&my >= 1 && my <= m && !vis[mx][my])
            {
                if (map[x][y] == 'x')
                    step++;
                step++;
                vis[mx][my] = 1;

                DFS(mx, my);

                vis[mx][my] = 0;
                step--;
                if (map[x][y] == 'x')
                    step--;
            }
        }
    }
}

int main()
{
    int i, j, x, y, min;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        sum = 0;
        step = 0;
        min = maxn;
        for (i = 1; i <= n; i++)
        {
            getchar();
            for (j = 1; j <= m; j++)
            {
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'a')
                {
                    x = i;
                    y = j;
                }
            }
        }
        vis[x][y] = 1;
        DFS(x, y);
        if (sum == 0)
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        else
        {
            for (i = 0; i < sum; i++)
                if (a[i] < min)
                    min = a[i];
            printf("%d\n", min);
        }
    }
    return 0;
}