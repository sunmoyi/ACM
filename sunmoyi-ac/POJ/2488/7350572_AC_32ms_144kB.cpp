//
// Created by 孙启龙 on 2016/10/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;
int dir[8][2] = { { -1, -2 }, { 1, -2 }, { -2, -1 }, { 2, -1 }, { -2, 1 }, { 2, 1 }, { -1, 2 }, { 1, 2 } };
int map[30 * 30][2];
int vis[30][30];
int flag;

void print()
{
    for(int i = 1; i <= n * m; i++)
        printf("%c%d", map[i][1] + 'A' - 1, map[i][0]);
    printf("\n\n");
}

void dfs(int cur)
{
    if(flag == 1)
        return;
    if(cur == n * m + 1)
    {
        flag = 1;
        print();
    }
    else
    {
        for(int i = 0; i < 8; i++)
        {
            int dx = map[cur - 1][0] + dir[i][0];
            int dy = map[cur - 1][1] + dir[i][1];
            if(dx < 1 || dx > n || dy < 1 || dy > m)
                continue;

            int mark = 1;
            for(int j = 1; j < cur; j++)
            {
                if(dx == map[j][0] && dy == map[j][1])
                {
                    mark = 0;
                    break;
                }
            }
            if(mark == 0)
                continue;

           // if(vis[dx][dy])
             //   continue;
          // vis[dx][dy] = 1;
            map[cur][0] = dx;
            map[cur][1] = dy;
            dfs(cur + 1);
           // vis[dx][dy] = 0;
            if(flag == 1)
                return;
        }
    }
}

int main (void)
{
    int ss;
    while(scanf("%d", &ss) != EOF)
    {
        for(int i = 1; i <= ss; i++)
        {
            //memset(vis, 0, sizeof(vis));
            flag = 0;
            scanf("%d %d", &n, &m);
            printf("Scenario #%d:\n", i);
            map[1][0] = 1;
            map[1][1] = 1;
            //vis[1][1] = 1;
            dfs(2);
            if(flag == 0)
                printf("impossible\n\n");
        }
    }
    return 0;
}