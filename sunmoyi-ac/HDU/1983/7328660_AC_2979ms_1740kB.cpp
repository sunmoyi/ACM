//
// Created by 孙启龙 on 16/10/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 15

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int sx, sy, n, m, t;
char str[maxn][maxn];
int hashh[11][11][2];

struct node{
    int x, y, step, key;
};

int bfs()
{
    queue<node>Q;
    node now, next;
    memset(hashh, 0, sizeof(hashh));

    now.x = sx, now.y = sy, now.step = 0, now.key = 0;
    hashh[sx][sy][0] = 1;
    Q.push(now);

    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if(now.step >= t)
            return -1;

        for(int i = 0; i < 4; i++)
        {
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            if (next.x<0 || next.y<0 || next.x>=n || next.y>=m)
                continue;
            if (str[next.x][next.y]=='#')
                continue;
            next.step=now.step+1;
            next.key=now.key;
            if (str[next.x][next.y]=='J')
                next.key=1;
            if (hashh[next.x][next.y][next.key]==1)
                continue;
            hashh[next.x][next.y][next.key]=1;
            Q.push(next);
            if (str[next.x][next.y]=='E' && next.key==1)
                return 1;
        }
    }
    return -1;
}

int dfs(int k)
{
    if(k == 0)
        return bfs();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(str[i][j] == 'J' || str[i][j] == '.')
            {
                char temp = str[i][j];
                str[i][j] = '#';
                if(dfs(k - 1) == -1)
                    return -1;
                str[i][j] = temp;
            }
        }
    }
    return 1;
}

int main (void)
{
    int Case, i, j;
    scanf("%d", &Case);
    while(Case--)
    {
        scanf("%d%d%d",&n,&m,&t);
        for (i=0; i<n; i++)
        {
            scanf("%s",str[i]);
            for (j=0; j<m; j++)
                if(str[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                    break;
                }
        }

        if(bfs() == -1)
        {
            printf("0\n");
            continue;
        }
        bool flag = false;
        for(int i = 1; i <= 3; i++)
        {
            if(dfs(i) == -1)
            {
                flag = true;
                printf("%d\n", i);
                break;
            }
        }
        if(!flag)
            printf("4\n");
    }
    return 0;
}