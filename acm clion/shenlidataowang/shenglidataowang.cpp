//
// Created by 孙启龙 on 2017/5/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 55
#define abs(a) ((a) > 0? (a):(-(a)))
using namespace std;

int map[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int a, b, c, t, ans;
struct node{
    int x, y, z, step;
    node(int x = 0, int y = 0, int z = 0, int step = 0): x(x), y(y), z(z), step(step){}
};

bool check(node d)
{
    if (d.x < 0 || d.y < 0 || d.z < 0 ||
            d.x >= a || d.y >= b || d.z >= c ||
            map[d.x][d.y][d.z] || vis[d.x][d.y][d.z])
        return false;
    return true;
}

int bfs(int x, int y, int z)
{
    queue<node>Q;
    node now, next;
    vis[x][y][z] = 1;
    Q.push(node(x, y, z, 0));
    while(!Q.empty())
    {
        now = Q.front();
        //printf("%d %d %d %d\n", now.x, now.y, now.z, now.step);
        Q.pop();
        if(now.x == a - 1 && now.y == b - 1 && now.z == c - 1)
        {
            if(now.step <= t)
                return now.step;
            else
                return -1;
        }
        for(int i = 0; i < 6; i++)
        {
            next = now;
            next.x += dir[i][0];
            next.y += dir[i][1];
            next.z += dir[i][2];
            next.step++;
            if(check(next))
            {
                vis[next.x][next.y][next.z] = 1;
                if(abs(next.x - a + 1) + abs(next.y - b + 1) + abs(next.z - c + 1) + next.step > t)
                    continue;
                Q.push(next);
            }
        }
    }
    return -1;
}

int main (void)
{
    int cnt;
    while(scanf("%d", &cnt) != EOF)
    {
        while(cnt--)
        {
            memset(vis, 0, sizeof(vis));
            memset(map, 0, sizeof(map));

            scanf("%d %d %d %d", &a, &b, &c, &t);
            for(int i = 0; i < a; i++)
                for(int j = 0; j < b; j++)
                    for(int k = 0; k < c; k++)
                        scanf("%d", &map[i][j][k]);

            ans = bfs(0, 0, 0);
            printf("%d\n", ans);
        }
    }
    return 0;
}