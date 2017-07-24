//
// Created by 孙启龙 on 2017/5/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 10

using namespace std;

struct node{
    int x, y;
    int bx, by;
    int num;
    bool friend operator < (const node&a, const node&b){
        return a.num > b.num;
    }
}star;
int map[maxn][maxn];
bool mark[maxn][maxn][maxn][maxn];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, ans;

void input()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 4)
            {
                star.x = i;
                star.y = j;
                map[i][j] = 0;
            }
            if (map[i][j] == 2)
            {
                star.bx = i;
                star.by = j;
                map[i][j] = 0;
            }
        }
    }
}

bool check(node now)
{
    int xx = now.x, yy = now.y;
    if (xx < 0 || xx >= n || yy < 0 || yy >= m)
        return true;
    if (map[xx][yy] == 1)
        return true;
    xx = now.bx, yy = now.by;
    if (xx < 0 || xx >= n || yy < 0 || yy >= m)
        return true;
    if (map[xx][yy] == 1)
        return true;
    return false;
}

int bfs()
{
    node now, next;
    priority_queue<node>Q;

    Q.push(star);
    mark[star.x][star.y][star.bx][star.by] = true;

    while(!Q.empty())
    {
        now = Q.top();
        Q.pop();

        if(map[now.bx][now.by] == 3)
            return now.num;

        for(int i = 0; i < 4; i++)
        {
            next = now;
            next.x += dir[i][0];
            next.y += dir[i][1];

            if(check(next))
                continue;

            if(next.x == next.bx && next.y == next.by)
            {
                next.bx += dir[i][0];
                next.by += dir[i][1];
                if(check(next))
                    continue;
                next.num++;
            }

            if(mark[next.x][next.y][next.bx][next.by])
                continue;

            mark[next.x][next.y][next.bx][next.by] = true;
            Q.push(next);
        }
    }
    return -1;
}

int main (void)
{
    int T, ans;
    scanf("%d", &T);
    while(T--)
    {
        memset(mark, 0, sizeof(mark));
        scanf("%d %d", &n, &m);

        input();

        star.num = 0;

        ans = bfs();
        printf("%d\n", ans);
    }
    return 0;
}