//
// Created by 孙启龙 on 2017/5/26.
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
    node(int x = 0, int y = 0, int step = 0): x(x), y(y), step(step){}
};

bool check(node now)
{
    int x = now.x, y = now.y;
    if(x >= 1 && x <= m && y >= 1 && y <= n && map[x][y] != '*')
        return true;
    return false;
}

void bfs(int sx, int sy)
{
    queue<node>Q;
    if(sx == ex && sy == ey)
    {
        printf("yes\n");
        return;
    }
    turn[sx][sy] = 1;
    node now, next;
    Q.push(node(sx, sy, -1));
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            next = now;
            next.x += dir[i][0];
            next.y += dir[i][1];
            next.step++;
            if(next.step > limit)
            {
                printf("no\n");
                return;
            }
            while(check(next))
            {
                if(!turn[next.x][next.y])
                {
                    Q.push(next);
                    turn[next.x][next.y] = true;
                    if(next.x == ex && next.y == ey && next.step <= limit)
                    {
                        printf("yes\n");
                        return;
                    }
                }
                next.x += dir[i][0];
                next.y += dir[i][1];
            }
        }
    }
    printf("no\n");
    return;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(map, 0, sizeof(map));
        memset(turn, 0, sizeof(turn));
        scanf("%d %d", &m, &n);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                scanf(" %c", &map[i][j]);
        scanf("%d %d %d %d %d", &limit, &sy, &sx, &ey, &ex);
        bfs(sx, sy);
    }
    return 0;
}