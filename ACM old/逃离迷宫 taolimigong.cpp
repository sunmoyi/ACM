//
// Created by 孙启龙 on 16/10/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 110

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
char map[maxn][maxn];
int turn[maxn][maxn];
int ex, ey, sx, sy;
int n, m, limit;

struct node{
    int x, y, step;
};

int check(int x, int y)
{
    if(x >= 1 && x <= m && y >= 1 && y <= n
	   && map[x][y] != '*')
        return 1;
    return 0;
}

void init()
{
    memset(turn, 0, sizeof(turn));
    memset(map, 0, sizeof(map));
}

void bfs(int sx, int sy)
{
    queue<node>Q;
    if(sx == ex && sy == ey)
    {
        printf("yes\n");
        return ;
    }
    turn[sx][sy] = 1;
    node now, next;
    now.x = sx, now.y = sy;
    now.step = -1;
    Q.push(now);
    while(!Q.empty())
    {
        next = Q.front();
        Q.pop();
        int x = next.x;
        int y = next.y;
        for(int i = 0; i < 4; i++)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            while(check(xx, yy))
            {
                if(!turn[xx][yy])
                {
                    now.x = xx;
                    now.y = yy;
                    now.step = next.step + 1;
                    Q.push(now);
                    turn[xx][yy] = 1;
                    if(xx == ex && yy == ey &&
					   now.step <= limit)
                    {
                        printf("yes\n");
                        return;
                    }
                }
                xx += dir[i][0];
                yy += dir[i][1];
            }
        }
    }
    printf("no\n");
    return ;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d %d", &m, &n);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                scanf(" %c", &map[i][j]);
        scanf("%d %d %d %d %d", &limit, &sy, &sx, &ey, &ex);
        bfs(sx, sy);
    }
    return 0;
}
