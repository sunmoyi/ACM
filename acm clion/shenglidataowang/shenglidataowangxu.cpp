//
// Created by 孙启龙 on 2017/5/26.
//

#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int n, m, t;

bool vis[21][21][1 << 10];
int sx, sy;
char mp[25][25];
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
struct node {
    int x, y, t, state;
    node(int x = 0, int y = 0, int t = 0, int state = 0) : x(x), y(y), t(t), state(state) {}
};

int bfs(int x, int y)
{
    memset(vis, false, sizeof(vis));

    queue<node> q;
    q.push(node(x, y, 0, 0));
    vis[x][y][0] = true;

    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        if(cur.t >= t-1)
            break;
        for(int i = 0; i < 4; i ++)
        {
            int xx = cur.x + dx[i];
            int yy = cur.y + dy[i];
            int tt = cur.t + 1;
            int sta = cur.state;

            if(xx < 0 || xx >= n || yy < 0 || yy >= m || mp[xx][yy] == '*' || vis[xx][yy][sta])
                continue;

            if(isupper(mp[xx][yy]) && !(sta & (1 << (mp[xx][yy] - 'A'))) )
                continue;

            if(islower(mp[xx][yy]))
                sta |= (1 << (mp[xx][yy] - 'a'));

            if(mp[xx][yy] == '^')
                return tt;

            if(!vis[xx][yy][sta])
            {
                vis[xx][yy][sta] = true;
                q.push(node(xx, yy, tt, sta));
            }
        }
    }
    return -1;
}

int main()
{
    while(scanf("%d %d %d", &n, &m, &t) != EOF)
    {
        for(int i = 0; i < n; i ++ )
            scanf("%s", mp[i]);

        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j ++)
            {
                if(mp[i][j] == '@')
                {
                    sx = i;
                    sy = j;
                    break;
                }
            }
        }

        printf("%d\n", bfs(sx, sy));

    }
    return 0;
}