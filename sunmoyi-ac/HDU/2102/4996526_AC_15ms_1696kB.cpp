#include <iostream>
#include <queue>
using namespace std ;
typedef struct L{
    int x,y,f ;
    int step ;
}L ;
int n,m,t ;
char map[2][11][11] ;
int vis[2][11][11] ;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}} ;
int flag ;
void bfs()
{
    memset(vis,0,sizeof(vis)) ;
    flag=0 ;
    L now,next ;
    queue <L> q ;
    now.x=now.y=now.f=now.step=0 ;
    q.push(now) ;
    vis[0][0][0]=1 ;
    while(!q.empty())
    {
        now=q.front() ;
        if(map[now.f][now.x][now.y]=='P' && now.step<=t)
        {
            flag=1 ;
            return ;
        }
        if(map[now.f][now.x][now.y]=='P')
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
            int ff=next.f ;
            if(xx<0 || xx>=n)
                continue ;
            if(yy<0 || yy>=m)
                continue ;
            if(map[ff][xx][yy]=='*')
                continue ;
            if(map[ff][xx][yy]=='#' && map[ff^1][xx][yy]=='*')
                continue ;
            if(map[ff][xx][yy]=='#' && map[ff^1][xx][yy]=='#')
                continue ;    
            if(!vis[ff][xx][yy] && map[ff][xx][yy]=='#' && vis[ff^1][xx][yy]==0)
            {
                vis[ff][xx][yy]=1 ;
                next.f^=1 ;
                vis[next.f][xx][yy]=1 ;
                next.step=now.step+1 ;
                q.push(next) ;
            }
            if(!vis[ff][xx][yy] && map[ff][xx][yy]!='#')
            {
                vis[ff][xx][yy]=1 ;
                next.step=now.step+1 ;
                q.push(next) ;
            }
        }
        q.pop() ;
    }
}
int main()
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