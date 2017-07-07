//
// Created by 孙启龙 on 2016/10/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int n, m, k, life;
int to[5][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};
int map[105][105];
bool vis[105][105][1005];

struct preied{
    char c;
    int t, v;
}s[105][105];

struct node{
    int x, y, step;
};

int check(int x, int y)
{
    if(x < 0 || x > n || y < 0 || y > m)
        return 1;
    return 0;
}

void bfs()
{
    node a, next;
    queue<node>Q;
    int i, j, flag, dis, temp;
    a.x = a.y = a.step = 0;
    Q.push(a);
    vis[0][0][0] = true;
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        if(a.step > life)
            break;
        if(a.x == n && a.y == m)
        {
            printf("%d\n", a.step);
            return;
        }
        for(int i = 0; i < 5; i++)
        {
            next = a;
            next.x += to[i][0];
            next.y += to[i][1];
            next.step++;
            if(check(next.x, next.y))
                continue;
            if(!vis[next.x][next.y][next.step] && !s[next.x][next.y].t && next.step <= life)
            {
                flag = 1;

                //north
                for(int j = next.x - 1; j >= 0; j--)
                {
                    if(s[j][next.y].t && s[j][next.y].c == 'S')
                    {
                        dis = next.x - j;
                        if(dis % s[j][next.y].v)
                            break;
                        temp = next.step - dis / s[j][next.y].v;
                        if(temp < 0)
                            break;
                        if(temp % s[j][next.y].t == 0)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(s[j][next.y].t)
                        break;
                }
                if(!flag)
                    continue;

                for(j = next.x + 1; j <= n; j++)
                {
                    if(s[j][next.y].t && s[j][next.y].c == 'N')
                    {
                        dis = j - next.x;
                        if(dis%s[j][next.y].v)
                            break;
                        temp = next.step - dis/s[j][next.y].v;
                        if(temp < 0) break;
                        if(temp % s[j][next.y].t==0)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(s[j][next.y].t)
                        break;
                }
                if(!flag)
                    continue;
                for(j = next.y - 1; j >= 0; j--)
                {
                    if(s[next.x][j].t && s[next.x][j].c == 'E')
                    {
                        dis = next.y-j;
                        if(dis % s[next.x][j].v) break;
                        temp = next.step-dis/s[next.x][j].v;
                        if(temp < 0)
                            break;
                        if(temp % s[next.x][j].t==0)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(s[next.x][j].t)
                        break;
                }
                if(!flag)
                    continue;
                for(j = next.y+1; j <= m; j++)
                {
                    if(s[next.x][j].t && s[next.x][j].c == 'W')
                    {
                        dis = j-next.y;
                        if(dis % s[next.x][j].v)
                            break;
                        temp = next.step-dis/s[next.x][j].v;
                        if(temp < 0)
                            break;
                        if(temp % s[next.x][j].t==0)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(s[next.x][j].t)
                        break;
                }
                if(!flag)
                    continue;
                vis[next.x][next.y][next.step] = true;
                Q.push(next);
            }
        }
    }
    printf("Bad luck!\n");
}

int main (void)
{
    int x, y, t, v;
    char str[3];
    while(scanf("%d %d %d %d", &n, &m, &k, &life) != EOF)
    {
        memset(s, 0, sizeof(s));
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < k; i++)
        {
            scanf("%s%d%d%d%d", str, &t, &v, &x, &y);
            s[x][y].v = v;
            s[x][y].t = t;
            s[x][y].c = str[0];
        }
        bfs();
    }
    return 0;
}