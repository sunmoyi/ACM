//
// Created by 孙启龙 on 2016/10/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define abs(x) (x > 0 ? x : -(x))
using namespace std;

const int dir[4][2]={ {1,0},{-1,0},{0,1},{0,-1} };
char str[810][810];
int used[2][810][810];
int gx,gy,mx,my,n,m,step;

struct node
{
    int x,y;
}ncur,z[2];

queue<node>q[2];

void init()
{
    int i,j,cnt;
    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++)
        scanf("%s",str[i]);
    cnt=0;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
        {
            if (str[i][j]=='G')
            {
                gx=i; gy=j;
            }
            if (str[i][j]=='M')
            {
                mx=i; my=j;
            }
            if (str[i][j]=='Z')
            {
                z[cnt].x=i;
                z[cnt++].y=j;
            }
        }
}

int judge(node b)
{
    if (b.x<0 || b.y<0 || b.x>=n || b.y>=m) return 0;
    if (str[b.x][b.y]=='X') return 0;
    if ((abs(b.x-z[0].x)+abs(b.y-z[0].y))<=2*step) return 0;
    if ((abs(b.x-z[1].x)+abs(b.y-z[1].y))<=2*step) return 0;
    return 1;
}

int bfs(int w)
{
    node cur,next;
    int i,sum;

    sum=q[w].size();
    while (sum--)
    {
        cur=q[w].front();
        q[w].pop();
        if (judge(cur)==0) continue;
        for (i=0;i<4;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            if (judge(next)==0) continue;
            if (used[w][next.x][next.y]==0)
            {
                if (used[w^1][next.x][next.y]==1) return 1;
                used[w][next.x][next.y]=1;
                q[w].push(next);
            }
        }
    }
    return 0;
}

int solve()
{
    while (!q[0].empty()) q[0].pop();
    while (!q[1].empty()) q[1].pop();

    ncur.x=mx;
    ncur.y=my;
    q[0].push(ncur);
    ncur.x=gx;
    ncur.y=gy;
    q[1].push(ncur);
    memset(used,0,sizeof(used));
    used[0][mx][my]=used[1][gx][gy]=1;
    step=0;

    while ((!q[0].empty()) || (!q[1].empty()))
    {
        step++;
        if (bfs(0)==1) return step;
        if (bfs(0)==1) return step;
        if (bfs(0)==1) return step;
        if (bfs(1)==1) return step;
    }
    return -1;

}
int main()
{
    int Case;
    scanf("%d",&Case);
    while (Case--)
    {
        init();
        printf("%d\n",solve());
    }
    return 0;
}