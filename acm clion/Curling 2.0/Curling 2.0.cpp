//
// Created by 孙启龙 on 2017/4/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int N, M, G[25][25];

int sx, sy;

struct node{
    int que[12][2], front, tail;
    int step, x, y;
    bool miss(int x, int y)
    {
        for(int i = front + 1; i <= tail; i++)
            if(que[i][0] == x && que[i][1] == y)
                return true;
        return false;
    }
}info, pos;

int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int bfs()
{
    queue<node>Q;
    info.x = sx, info.y = sy;
    info.front = 0, info.tail = 0;
    info.step = 0;
    Q.push(info);
    while(!Q.empty())
    {
        pos = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int xx = pos.x + dir[i][0];
            int yy = pos.y + dir[i][1];
            if(G[xx][yy] == 3)
                return pos.step + 1;
            if(!(G[xx][yy] == 0 || pos.miss(xx, yy)))
                continue;
            for(;G[xx][yy] != -1; xx += dir[i][0], yy += dir[i][1])
            {
                if(G[xx][yy] == 1)
                {
                    if(!pos.miss(xx, yy))
                        break;
                }
                else if (G[xx][yy] == 3)
                    return pos.step + 1;
            }
            if(G[xx][yy] == 1 && pos.step + 1 < 10)
            {
                info = pos;
                ++info.step;
                ++info.tail;
                info.x = xx - dir[i][0];
                info.y = yy - dir[i][1];
                info.que[info.tail][0] = xx;
                info.que[info.tail][1] = yy;
                Q.push(info);
            }
        }
    }
    return -1;
}

int main (void)
{
    while(scanf("%d %d", &M, &N) != EOF && (N + M))
    {
        for(int i = 0; i < 25; i++)
            for(int j = 0; j < 25; j++)
                G[i][j] = -1;

        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                scanf("%d", &G[i][j]);
                if(G[i][j] == 2)
                    sx = i, sy = j, G[i][j] = 0;
            }
        }
        printf("%d\n", bfs());
    }
    return 0;
}