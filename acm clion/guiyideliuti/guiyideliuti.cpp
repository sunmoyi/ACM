//
// Created by 孙启龙 on 2017/5/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 22

using namespace std;

struct node {
    int x, y;
    int step;
    friend bool operator < (node n1, node n2) {
        return n1.step > n2.step;
    }
};
int stair[maxn][maxn];
int map[maxn][maxn];
int n, m;
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int sx, sy, ex, ey;

int judge(int x, int y)
{
    if (x<0 || x >= n || y<0 || y >= m)
        return 1;
    if (map[x][y] == 1)
        return 1;
    if (map[x][y] == 2)
        return 2;
    return 0;
}

int judge2(int step, int x2, int y2, int k)
{
    if ((step + stair[x2][y2]) % 2 != 0 && (k == 0 || k == 2))
        return 1;
    if ((step + stair[x2][y2]) % 2 == 0 && (k == 1 || k == 3))
        return 1;
    return 0;
}

int bfs()
{
    priority_queue<node>q;
    node cur, next;
    int i;
    int temp;
    int tx, ty;

    cur.x = sx;
    cur.y = sy;
    cur.step = 0;
    map[cur.x][cur.y] = 1;

    q.push(cur);
    while (!q.empty())
    {
        cur = q.top();
        q.pop();
        if (cur.x == ex && cur.y == ey)
            return cur.step;
        for (i = 0; i<4; i++)
        {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];

            temp = judge(next.x, next.y);
            if (temp == 1)
                continue;
            if (!temp)
            {
                next.step = cur.step + 1;
                map[next.x][next.y] = 1;
                q.push(next);
            }
            else
            {
                tx = next.x + dir[i][0];
                ty = next.y + dir[i][1];
                if (judge(tx, ty) == 1)
                    continue;

                if (judge2(cur.step, next.x, next.y, i))
                {
                    next.x = tx;
                    next.y = ty;
                    next.step = cur.step + 1;
                }
                else
                {
                    next.x = tx;
                    next.y = ty;
                    next.step = cur.step + 2;
                }
                q.push(next);
            }
        }
    }
    return -1;
}

int main (void)
{
    int ans;
    char str[25];

    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%s", str);
            for(int l = 0; str[l]; l++)
            {
                if (str[l] == 'S')
                    sx = i, sy = l, map[i][l] = 0;
                else if (str[l] == 'T')
                    ex = i, ey = l, map[i][l] = 0;
                else if (str[l] == '|')
                    stair[i][l] = 1, map[i][l] = 2;
                else if (str[l] == '-')
                    stair[i][l] = 0, map[i][l] = 2;
                else if (str[l] == '*')
                    map[i][l] = 1;
                else if (str[l] == '.')
                    map[i][l] = 0;
            }
        }
        ans = bfs();
        printf("%d\n", ans);
    }
    return 0;
}