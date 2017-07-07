//
// Created by 孙启龙 on 16/10/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 15

using namespace std;

struct L{
    int x, y, f, step;
};
int n, m, t;
char map[2][maxn][maxn];
int vis[2][maxn][maxn];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int flag;

void dfs()
{
    memset(vis, 0, sizeof(vis));
    flag = 0;
    L now, next;
    now.x = 0, now.y = 0, now.step = 0, now.f = 0;
    queue<L>Q;
    Q.push(now);
    vis[0][0][0] = 1;
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if(map[now.f][now.x][now.y] == 'P' && now.step <= t)
        {
            flag = 1;
            return;
        }
        if(map[now.f][now.x][now.y] == 'P')
            return;
        for(int i = 0; i < 4; i++)
        {
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];
            next.f = now.f;
            int xx = next.x, yy = next.y, ff = next.f;
            if(xx < 0 || xx >= n)
                continue;
            if(yy < 0 || yy >= m)
                continue;
            if(map[ff][xx][yy] == '*')
                continue;
            if(map[ff][xx][yy] == '#' && map[ff ^ 1][xx][yy] == '*')
                continue;
            if(map[ff][xx][yy] == '#' && map[ff ^ 1][xx][yy] == '#')
                continue;
            if(!vis[ff][xx][yy] && map[ff][xx][yy] == '#' && !vis[ff ^ 1][xx][yy])
            {
                vis[ff][xx][yy] = 1;
                next.f ^= 1;
                vis[ff ^ 1][xx][yy] = 1;
                next.step = now.step + 1;
                Q.push(next);
            }
            if(!vis[ff][xx][yy] && map[ff][xx][yy] != '#')
            {
                vis[ff][xx][yy] = 1;
                next.step = now.step + 1;
                Q.push(next);
            }
        }
    }
}

int main (void)
{
    int c;
    scanf("%d", &c);
    while(c--)
    {
        scanf("%d%d%d%*c", &n, &m, &t);
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
                scanf("%s", map[i][j]);
            getchar();
        }
        dfs();
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}