#include <iostream>
#include <queue>
#include<cstring>
using namespace std ;
typedef struct L{
    int x,y,f ;
    int step ;
}L ;
int n,m,t ;
char map[2][11][11] ;
int vis[2][11][11] ;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}} ;// 四个移动方向
int flag ;

void bfs()
{
    memset(vis,0,sizeof(vis)) ;
    flag=0 ;
    L now,next ;
    queue <L> q ;//新建队列
    now.x=now.y=now.f=now.step=0 ;
    q.push(now) ;
    vis[0][0][0]=1 ;
    while(!q.empty())
    {
        now=q.front() ;
        q.pop() ;
        if(map[now.f][now.x][now.y]=='P' && now.step<=t)//如果搜寻到 目标值且步数少于等于最大值
        {
            flag=1 ;
            return ;//标记 返还
        }
        if(map[now.f][now.x][now.y]=='P')//如果找到但是不是最大值  直接返回 无要求解（bfs默认为最小）
        {
            return ;
        }
        for(int i=0;i<4;i++)
        {
            next.x=now.x+dir[i][0] ;
            next.y=now.y+dir[i][1] ;
            next.f=now.f ;
            int xx=next.x ;
            int yy=next.y ;
            int ff=next.f ;//变换之后的三维坐标
            if(xx<0 || xx>=n)//判断是否越界
                continue ;
            if(yy<0 || yy>=m)
                continue ;
            if(map[ff][xx][yy]=='*')//判断是否是星号
                continue ;
            if(map[ff][xx][yy]=='#' && map[ff^1][xx][yy]=='*')//如果是电梯 那么他转换后是否是星号
                continue ;
            if(map[ff][xx][yy]=='#' && map[ff^1][xx][yy]=='#')//同样是电梯的也不行
                continue ;    
            if(!vis[ff][xx][yy] && map[ff][xx][yy]=='#' && vis[ff^1][xx][yy]==0)
            {
                vis[ff][xx][yy]=1 ;
                next.f^=1 ;//如果是电梯 转换到另外一层
                vis[next.f][xx][yy]=1 ;//标记
                next.step=now.step+1 ;//不失加一
                q.push(next) ;//递归
            }
            if(!vis[ff][xx][yy] && map[ff][xx][yy]!='#')
            {
                vis[ff][xx][yy]=1 ;//标记
                next.step=now.step+1 ;//步数加一
                q.push(next) ;//递归
            }
        }
    }
}
int main(void)
{
    int c ;
    scanf("%d",&c) ;
    while(c--)
    {
        scanf("%d%d%d%*c",&n,&m,&t) ;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
                scanf("%s",map[i][j]) ;
            getchar() ;
        }
        bfs() ;
        if(flag)
            puts("YES") ;
        else
            puts("NO") ;
    }
    return 0 ;
}