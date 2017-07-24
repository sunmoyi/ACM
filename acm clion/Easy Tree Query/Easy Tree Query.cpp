//
// Created by 孙启龙 on 2017/5/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
bool map[10000][10000];
int ans = 0;

void dfs(int x, int y, int len)
{
    if(len == 0)
    {
        if(!map[x][y])
        {
            map[x][y] = true;
            ans++;
        }
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        dfs(nx, ny, len - 1);
    }
}

int main (void)
{
    for(int i = 1; i <= 5; i++)
    {
        ans = 0;
        memset(map, false, sizeof(map));
        dfs(100, 100, i);
        printf("%d %d\n", i, ans);
    }
    return 0;
}