//
// Created by 孙启龙 on 16/10/24.
//
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define maxn 10

using namespace std;

struct node{
    int x, y, step, count;
}p, q;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int map[maxn][maxn];
int n, m, sx, sy;

int judge(int x, int y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= m && map[x][y] != 0)
        return 1;
    return 0;
}

void bfs()
{
    queue<node>Q;
    p.x = sx;
    p.y = sy;
    p.step = 0;
    p.count = 6;
    Q.push(p);
    map[sx][sy] = 0;
    while(!Q.empty())
    {
        p = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            q = p;
            q.x += dir[i][0];
            q.y += dir[i][1];
            if(judge(q.x, q.y))
            {
                if(map[q.x][q.y] ==1)
                {
                    q.count--;
                    if(q.count >= 1)
                    {
                        q.step++;
                        Q.push(q);
                    }
                }
                if(map[q.x][q.y] == 4)
                {
                    q.count--;
                    if(q.count >= 1)
                    {
                        q.step++;
                        q.count = 6;
                        Q.push(q);
                    }
                    map[q.x][q.y] = 0;
                }
                if(map[q.x][q.y] == 3 && q.count > 1)
                {
                    q.step++;
                    printf("%d\n", q.step);
                    return;
                }
            }
        }
    }
    printf("-1\n");
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &map[i][j]);
                if(map[i][j] == 2)
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        bfs();
    }
    return 0;
}