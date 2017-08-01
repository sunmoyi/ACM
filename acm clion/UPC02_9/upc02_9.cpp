//
// Created by 孙启龙 on 2017/7/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int n, m[100][100], dis[30][30][30][30][5][5];
bool vis[30][30][30][30][5][5];
int dir[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct node {
    int x1, y1, x2, y2, d1, d2;
    node(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int d1 = 0, int d2 = 0):
            x1(x1), y1(y1), d1(d1), x2(x2), y2(y2), d2(d2) {}
};

bool check(int x, int y)
{
    if ((x < 1) || (x > n) || (y < 1) || (y > n))
        return false;
    return true;
}

void bfs()
{
    queue<node> q;
    q.push(node(n, 1, n, 1, 1, 2));
    vis[n][1][n][1][1][2] = true;
    while (!q.empty())
    {
        node p = q.front();
        q.pop();
        int step = dis[p.x1][p.y1][p.x2][p.y2][p.d1][p.d2];
        int nowx1 = p.x1 + dir[p.d1][0];
        int nowy1 = p.y1 + dir[p.d1][1];
        int nowx2 = p.x2 + dir[p.d2][0];
        int nowy2 = p.y2 + dir[p.d2][1];
        if ((p.x1 == 1) && (p.y1 == n))
            nowx1 = 1, nowy1 = n;
        if ((p.x2 == 1) && (p.y2 == n))
            nowx2 = 1, nowy2 = n;
        if ((check(nowx1, nowy1) == false) || (m[nowx1][nowy1] == false))
            nowx1 = p.x1, nowy1 = p.y1;
        if ((check(nowx2, nowy2) == false) || (m[nowx2][nowy2] == false))
            nowx2 = p.x2, nowy2 = p.y2;
        if (dis[nowx1][nowy1][nowx2][nowy2][p.d1][p.d2] > step + 1)
        {
            dis[nowx1][nowy1][nowx2][nowy2][p.d1][p.d2] = step + 1;
            if (vis[nowx1][nowy1][nowx2][nowy2][p.d1][p.d2] == false)
                q.push(node(nowx1, nowy1, nowx2, nowy2, p.d1, p.d2));
            vis[nowx1][nowy1][nowx2][nowy2][p.d1][p.d2] = true;
        }




        int td1 = p.d1 + 1;
        int td2 = p.d2 + 1;
        if (td1 > 4)
            td1 = 1;
        if (td2 > 4)
            td2 = 1;
        if (dis[p.x1][p.y1][p.x2][p.y2][td1][td2] > step + 1)
        {
            dis[p.x1][p.y1][p.x2][p.y2][td1][td2] = step + 1;
            if (vis[p.x1][p.y1][p.x2][p.y2][td1][td2] == false)
                q.push(node(p.x1, p.y1, p.x2, p.y2, td1, td2));
            vis[p.x1][p.y1][p.x2][p.y2][td1][td2] = true;
        }




        td1 = p.d1 - 1;
        td2 = p.d2 - 1;
        if (td1 < 1)
            td1 = 4;
        if (td2 < 1)
            td2 = 4;
        if (dis[p.x1][p.y1][p.x2][p.y2][td1][td2] > step + 1)
        {
            dis[p.x1][p.y1][p.x2][p.y2][td1][td2] = step + 1;
            if (vis[p.x1][p.y1][p.x2][p.y2][td1][td2] == false)
                q.push(node(p.x1, p.y1, p.x2, p.y2, td1, td2));
            vis[p.x1][p.y1][p.x2][p.y2][td1][td2] = true;
        }
        vis[p.x1][p.y1][p.x2][p.y2][p.d1][p.d2] = false;
    }
}

int main()
{
    char c;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        getchar();
        for (int j = 1; j <= n; j++)
        {
            scanf("%c", &c);
            if (c == 'E')
                m[i][j] = true;
            else if (c == 'H')
                m[i][j] = false;
        }
    }

    memset(vis, false, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[n][1][n][1][1][2] = 0;

    bfs();

    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            ans = min(ans, dis[1][n][1][n][i][j]);
    printf("%d\n", ans);
}