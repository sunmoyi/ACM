//
// Created by 孙启龙 on 2017/1/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct node{
    int x, y, step, now;
    node (int x = 0, int y = 0, int step = 0, int now = 0):
            x(x), y(y), step(step), now(now){}
};

int T;
int k, n, m;
int map[30][30];
int t[30][30];

int bfs()
{
    int tx, ty;
    queue<node>Q;
    Q.push(node(1, 1, 0, 0));
    node temp;
    memset(t, 0x3f3f3f3f, sizeof(t));
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        if(temp.x == n && temp.y == m)
            return temp.step;
        for(int i = 0; i <= 3; i++)
        {
            tx = temp.x + dir[i][0];
            ty = temp.y + dir[i][1];
            int p = (map[tx][ty] == 1 ? temp.now + 1 : 0);
            if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && p < t[tx][ty])
            {
                t[tx][ty] = p;
                if(map[tx][ty] == 1 && temp.now >= k)
                    continue;
                Q.push(node(tx, ty, temp.step + 1, p));
            }
        }
    }
    return -1;
}

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        scanf("%d", &k);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &map[i][j]);
        printf("%d\n", bfs());
    }
    return 0;
}