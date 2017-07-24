//
// Created by 孙启龙 on 2017/4/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 210

using namespace std;

char map[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int sx, sy, num1, num2;
int n, m;

void bfs(void)
{
    queue<pair<pair<int, int>, int> >Q;
    pair<pair<int, int>, int>now, next;
    Q.push(make_pair(make_pair(sx, sy), 0));
    vis[sx][sy] = true;
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            next.first.first = now.first.first + dir[i][0];
            next.first.second = now.first.second + dir[i][1];
            next.second = now.second + 1;
            if(next.first.first <= 0 || next.first.first > n)
                continue;
            if(next.first.second <= 0 || next.first.second > m)
                continue;
            if(vis[next.first.first][next.first.second])
                continue;
            if(map[next.first.first][next.first.second] == '#')
                continue;
            if(map[next.first.first][next.first.second] == '@')
            {   num1 = min(num1, next.second); continue;}
            if(map[next.first.first][next.first.second] == '$')
            {   num2 = min(num2, next.second); continue;}
            vis[next.first.first][next.first.second] = true;
            Q.push(next);
        }
    }
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            getchar();
            for(int j = 1; j <= m; j++)
            {
                scanf("%c", &map[i][j]);
                if(map[i][j] == '%')
                    sx = i, sy = j;
            }
        }

        memset(vis, false, sizeof(vis));
        num1 = num2 = 0x3f3f3f3f;
        bfs();

        if(num1 < num2)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}