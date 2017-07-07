#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, G[25][25];

int sx, sy;

struct Node {
    char que[12][2], front, tail; // 用来记录被碰掉的点的坐标 
    char step, x, y;
    bool Miss(int x, int y) { // 扫描当前点是否在这条路径中已经消失
        for (int i = front+1; i <= tail; ++i) {
            if (que[i][0] == x && que[i][1] == y) return true;
        }
        return false;
    }
}info, pos;

int front, tail, dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int bfs() {
    queue<Node>q;
    info.x = sx, info.y = sy;
    info.front = info.tail = 0; // 清空这个对列，因为这个球还没有发生碰撞
    info.step = 0;
    q.push(info);
    while (!q.empty()) {
        pos = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = pos.x + dir[i][0], yy = pos.y + dir[i][1];
            if (G[xx][yy] == 3) return pos.step + 1;
            if (!(G[xx][yy] == 0 || pos.Miss(xx, yy))) continue;
            for (; G[xx][yy] != -1; xx += dir[i][0], yy += dir[i][1]) {
                // 模拟整个行走的过程，不执行任何语句
                if (G[xx][yy] == 1) {
                    if (!pos.Miss(xx, yy)) break;
                } else if (G[xx][yy] == 3) {
                    return pos.step + 1;
                }
            }
            if (G[xx][yy] == 1 && pos.step + 1 < 10) {
                info = pos; // 一个完整的备份
                ++info.step;
                ++info.tail;
                info.x = xx - dir[i][0], info.y = yy - dir[i][1];
                   info.que[info.tail][0] = xx;
                   info.que[info.tail][1] = yy; // 添加当前点为消失点
                   q.push(info);
            }
        }
    }
    return -1;
}

int main() {
    while (scanf("%d %d", &M, &N), N|M) {
        memset(G, 0xff, sizeof (G));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                scanf("%d", &G[i][j]);
                if (G[i][j] == 2) {
                    sx = i, sy = j;
                    G[i][j] = 0;
                }
            }
        }
        printf("%d\n",  bfs());
    }
    return 0;    
}