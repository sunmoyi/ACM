//
// Created by 孙启龙 on 16/10/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 110

using namespace std;

struct node{
    int x, y,  step;
    friend bool operator < (node a, node b)
    {
        return a.step > b.step;
    }
};
int map[maxn][maxn], flag[maxn][maxn], cnt[maxn][maxn];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, tim;

int check(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
        return 1;
    if(map[x][y] == -1)
        return 1;
    return 0;
}

int dfs()
{
    int i;
    priority_queue<node>Q;
    node a, next;
    a.x = 0, a.y = 0, a.step = 0;
    map[0][0] = -1;
    Q.push(a);
    while(!Q.empty())
    {
        a = Q.top();
        Q.pop();
        if(a.x == n - 1 && a.y == m - 1)
            return a.step;
        for(int i = 0; i < 4; i++)
        {
            next = a;
            next.x += dir[i][0];
            next.y += dir[i][1];
            if(check(next.x, next.y))
                continue;
            next.step = a.step + map[next.x][next.y] + 1;
            map[next.x][next.y] = -1;
            flag[next.x][next.y] = i + 1;
            Q.push(next);
        }
    }
    return 0;
}

void print(int x, int y)
{
    int n_x,n_y;
    if(!flag[x][y])
        return;
    n_x = x - dir[flag[x][y] - 1][0];
    n_y = y - dir[flag[x][y] - 1][1];
    print(n_x,n_y);
    printf("%ds:(%d,%d)->(%d,%d)\n",tim++,n_x,n_y,x,y);
    while(cnt[x][y]--)
    {
        printf("%ds:FIGHT AT (%d,%d)\n",tim++,x,y);
    }
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(map,0,sizeof(map));
        memset(flag,0,sizeof(flag));
        memset(cnt,0,sizeof(cnt));
        char s[105];
        for(int i = 0; i<n; i++)
        {
            scanf("%s",s);
            for(int j = 0; s[j]; j++)
            {
                if(s[j] == '.')
                    map[i][j] = 0;
                else if(s[j] == 'X')
                    map[i][j] = -1;
                else
                    map[i][j] = cnt[i][j] = s[j]-'0';
            }
        }
        int ans = 0;
        ans = dfs();
        if(ans)
        {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
            tim = 1;
            print(n-1,m-1);
        }
        else
            printf("God please help our poor hero.\n");
        printf("FINISH\n");
    }
    return 0;
}