//
// Created by 孙启龙 on 16/10/26.
//
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<queue>
#define maxn 362890

using namespace std;

int fac[] = {1,1,2,6,24,120,720,5040,40320,362880};
bool vis[maxn];
string path[maxn];

int cantor(int s[])
{
    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
        int num = 0;
        for(int j = i + 1; j < 9; j++)
            if(s[j] < s[i])
                num++;
        sum += (num * fac[9 - i - 1]);
    }
    return sum + 1;
}

struct node{
    int s[9];
    int loc;
    int status;
    string path;
};

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char indexs[5] = "durl";
int aim = 46234; // 1234567890对应的康拓展开值；

void bfs()
{
    memset(vis, false, sizeof(vis));
    node cur, next;
    for(int i = 0; i < 8; i++)
        cur.s[i] = i + 1;
    cur.s[8] = 0;
    cur.loc = 8;
    cur.status = aim;
    cur.path = "";
    queue<node>Q;
    Q.push(cur);
    path[aim] = "";
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        int x = cur.loc / 3;
        int y = cur.loc % 3;
        for(int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx < 0 || tx > 2 || ty < 0 || ty > 2)
                continue;
            next=cur;
            next.loc=tx*3+ty;
            next.s[cur.loc]=next.s[next.loc];
            next.s[next.loc]=0;
            next.status=cantor(next.s);
            if(!vis[next.status])
            {
                vis[next.status]=true;
                next.path=indexs[i]+next.path;
                Q.push(next);
                path[next.status]=next.path;
            }
        }
    }
    return;
}

int main (void)
{
    char ch;
    node cur;
    bfs();
    while(cin >> ch)
    {
        if(ch == 'x')
        {
            cur.s[0] = 0;
            cur.loc = 0;
        }
        else
            cur.s[0] = ch - '0';

        for(int i = 1; i < 9; i++)
        {
            cin >> ch;
            if(ch == 'x')
            {
                cur.s[i] = 0;
                cur.loc = i;
            }
            else
                cur.s[i] = ch - '0';
        }
        cur.status = cantor(cur.s);
        if(vis[cur.status])
            cout << path[cur.status] << endl;
        else
            cout << "unsolvable" << endl;
    }
    return 0;
}