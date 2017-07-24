//
// Created by 孙启龙 on 2017/5/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 10

using namespace std;

struct node{
    int x, y, step, count;
    node(int x = 0, int y = 0, int step = 0, int count = 0): x(x), y(y), step(step), count(count){}
};
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int map[maxn][maxn];
int n, m, sx, sy;

inline bool judge(int x, int y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= m && map[x][y] != 0)
        return true;
    return false;
}

void bfs()
{
    queue<node>Q;
    node now, nextt;
    Q.push(node(sx, sy, 0, 6));
    map[sx][sy] = 0;
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            nextt = now;
            nextt.x += dir[i][0];
            nextt.y += dir[i][1];
            if(judge(nextt.x, nextt.y))
            {
                if(map[nextt.x][nextt.y] == 1 && nextt.count > 1)
                {
                    nextt.count--;
                    nextt.step++;
                    Q.push(nextt);
                }
                if(map[nextt.x][nextt.y] == 4 && nextt.count > 1)
                {
                    nextt.step++;
                    nextt.count = 6;
                    Q.push(nextt);
                    map[nextt.x][nextt.y] = 0;
                }
                if(map[nextt.x][nextt.y] == 3 && nextt.count > 1)
                {
                    printf("%d\n", nextt.step + 1);
                    return;
                }
            }
        }
    }
    printf("-1\n");
    return;
}

int main (void)
{
    int Case;
    scanf("%d", &Case);
    while(Case--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &map[i][j]);
                if(map[i][j] == 2)
                    sx = i, sy = j;
            }
        }
        bfs();
    }
    return 0;
}