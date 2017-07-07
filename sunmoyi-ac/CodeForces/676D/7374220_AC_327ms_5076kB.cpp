//
// Created by 孙启龙 on 2016/10/30.
//

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn = 1005;
char Map[maxn][maxn];
struct node
{
    int flag,x,y,step;
};
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m,end_x,end_y;
bool mark[maxn][maxn][4];

void go(int a,int b,int c,int d,bool* ok)
{
    ok[0]=a,ok[1]=b,ok[2]=c,ok[3]=d;
}

bool ok[4],ok1[4];
void fun(node cur,bool A[])
{
    //右 下 左 上 
    int x=cur.x,y=cur.y;
    if(Map[x][y]=='+') go(1,1,1,1,A);
    else if(Map[x][y]=='-') go(1,0,1,0,A);
    else if(Map[x][y]=='|') go(0,1,0,1,A);
    else if(Map[x][y]=='^') go(0,0,0,1,A);
    else if(Map[x][y]=='>') go(1,0,0,0,A);
    else if(Map[x][y]=='<') go(0,0,1,0,A);
    else if(Map[x][y]=='v') go(0,1,0,0,A);
    else if(Map[x][y]=='L') go(1,1,0,1,A);
    else if(Map[x][y]=='R') go(0,1,1,1,A);
    else if(Map[x][y]=='U') go(1,1,1,0,A);
    else if(Map[x][y]=='D') go(1,0,1,1,A);
    else if(Map[x][y]=='*') go(0,0,0,0,A);
}

void bfs(node cur)
{
    queue<node>q;
    mark[cur.x][cur.y][0]=true;
    q.push(cur);
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        fun(cur,ok);
        for(int i=0;i<4;++i)
            if(ok[i])
            {
                node next=cur;
                next.x+=dir[(i+next.flag)%4][0];
                next.y+=dir[(i+next.flag)%4][1];
                next.step++;
                if(next.x<0||next.y<0||next.x>=n||next.y>=m) continue;
                fun(next,ok1);
                if(!ok1[(i+2)%4]) continue;
                if(mark[next.x][next.y][next.flag]) continue;
                mark[next.x][next.y][next.flag]=true;
                if(next.x==end_x&&next.y==end_y)
                {
                    printf("%d\n",next.step);
                    return ;
                }
                q.push(next);
            }
        node next=cur;
        next.flag++;
        next.step++;
        next.flag%=4;
        if(mark[next.x][next.y][next.flag]) continue;
        mark[next.x][next.y][next.flag]=true;
        q.push(next);
    }
    printf("-1\n");
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%s",Map[i]);
    node cur;
    scanf("%d%d",&cur.x,&cur.y);
    cur.x--,cur.y--;
    scanf("%d%d",&end_x,&end_y);
    end_y--,end_x--;
    if(cur.x==end_x&&cur.y==end_y)
    {
        printf("0\n");
        return 0;
    }
    cur.flag=0;
    cur.step=0;
    bfs(cur);
    return 0;
}