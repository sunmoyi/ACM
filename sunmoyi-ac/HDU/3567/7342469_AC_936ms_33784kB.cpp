#include <iostream>  
#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
#include <queue>  
#include <stack>  
#include <string>  
using namespace std;  
  
struct node  
{  
    int x,y;  
    char map[5][5];  
    node() {}  
    node(char *s)  
    {  
        int i,j;  
        int xx = 0,yy = 0;  
        for(i = 0; i<strlen(s); i++)  
        {  
            map[xx][yy] = s[i];  
            if(s[i] == 'X')  
            {  
                x = xx;  
                y = yy;  
            }  
            yy++;  
            if(yy == 3)  
            {  
                xx++;  
                yy = 0;  
            }  
        }  
    }  
};  
  
node s;  
char str[20];  
int num[20],hashh[10];  
bool vis[500000];  
int pre[10][500000],ans[10][500000];  
int to[4][2] = {1,0,0,-1,0,1,-1,0};  
char way[10] = "dlru";  
  
int solve(node a)//康拓  
{  
    int i,j,k,cnt,ans = 0;  
    int b[20];  
    for(i = 0; i<3; i++)  
    {  
        for(j = 0; j<3; j++)  
        {  
            b[3*i+j] = a.map[i][j];  
            cnt = 0;  
            for(k = 3*i+j-1; k>=0; k--)  
            {  
                if(b[k]>b[3*i+j])  
                    cnt++;  
            }  
            ans+=hashh[3*i+j]*cnt;  
        }  
    }  
    return ans;  
}  
  
void bfs(int p)  
{  
    memset(pre[p],-1,sizeof(pre[p]));  
    memset(vis,false,sizeof(vis));  
    node a,next;  
    queue<node> Q;  
    Q.push(s);  
    vis[solve(s)] = true;  
    while(!Q.empty())  
    {  
        a = Q.front();  
        Q.pop();  
        int sa = solve(a);  
        for(int i = 0; i<4; i++)  
        {  
            next = a;  
            next.x+=to[i][0];  
            next.y+=to[i][1];  
            if(next.x<0 || next.x>2 || next.y<0 || next.y>2)  
                continue;  
            next.map[a.x][a.y] = next.map[next.x][next.y];  
            next.map[next.x][next.y] = 'X';  
            int sb = solve(next);  
            if(vis[sb])  
                continue;  
            vis[sb] = true;  
            pre[p][sb] = sa;  
            ans[p][sb] = way[i];  
            Q.push(next);  
        }  
    }  
}  
  
int main()  
{  
    int t,i,j,k,cas = 1;  
    hashh[0] = 1;  
    for(i = 1; i<10; i++)  
        hashh[i] = hashh[i-1]*i;  
  
    s = node("X12345678");  
    bfs(0);  
    s = node("1X2345678");  
    bfs(1);  
    s = node("12X345678");  
    bfs(2);  
    s = node("123X45678");  
    bfs(3);  
    s = node("1234X5678");  
    bfs(4);  
    s = node("12345X678");  
    bfs(5);  
    s = node("123456X78");  
    bfs(6);  
    s = node("1234567X8");  
    bfs(7);  
    s = node("12345678X");  
    bfs(8);  
  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%s",str);  
        int p;  
        for(i = 0,j = 0; i<9; i++)//保存位置，因为前面预处理的都是位置  
        {  
            if(str[i]=='X') p = i;  
            else  
                num[str[i]-'0'] = j++;  
        }  
        scanf("%s",str);  
        for(i = 0; i<9; i++)//求出目标状态每个数在原状态的位置  
        {  
            if(str[i]=='X')  
                continue;  
            str[i] = num[str[i]-'0']+'1';  
        }  
        s = node(str);//由目标态逆推到初始态  
        int sum = solve(s);  
        string ss="";  
        while(sum!=-1)  
        {  
            ss+=ans[p][sum];  
            sum = pre[p][sum];  
        }  
        printf("Case %d: %d\n",cas++,ss.size()-1);  
        for(i = ss.size()-2; i>=0; i--)//由于方案是逆推，输出也要逆推  
            printf("%c",ss[i]);  
        printf("\n");  
    }  
  
    return 0;  
}  