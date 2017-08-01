//
// Created by 孙启龙 on 2017/7/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

int n, m;
int map[maxn][maxn];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int serachnum = 0;

void dfs(int x, int y)
{
    map[x][y] = 0;
    for(int i = 0; i < 4; i++)
    {
        int nowx = x + dir[i][0];
        int nowy = y + dir[i][1];
        if(nowx < 1 || nowx > n || nowy < 1 || nowy > n)
            continue;
        if(map[nowx][nowy] == serachnum)
            dfs(nowx, nowy);
    }
}

int main (void)
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);

    serachnum = map[n][m];
    dfs(n, m);

    for(int i = 1; i <= n; i++)
    {
        int pos = n - 1;
        for(int j = n; j >= 1; j--)
        {
            pos = min(pos, j - 1);
            if(pos < 1)
                break;
            while(map[j][i] == 0)
            {
                swap(map[j][i], map[pos][i]);
                pos--;
                if(pos < 1)
                    break;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    return 0;
}