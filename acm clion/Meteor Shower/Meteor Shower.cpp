//
// Created by 孙启龙 on 2017/4/26.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <bitset>
#include <list>
#include <sstream>
#include <set>
#include <functional>
using namespace std;

#define MAX 400
typedef long long ll;
int n;

struct node{
    int x;
    int y;
    int t;
}s,current;

queue<node>q;//寻找最短时间时层层推进
int map[MAX][MAX];//存储时间
int dir[5][2] = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};//坐标的拓展

int bfs()
{
    if(map[0][0] == 0)  return -1;
    if(map[0][0] == -1) return 0;
    s.x = s.y = s.t = 0;
    q.push(s);
    while (!q.empty())
    {
        current = q.front();
        q.pop();
        for (int i = 0; i < 5; i += 1)
        {
            s.x = current.x+dir[i][0];
            s.y = current.y+dir[i][1];
            s.t = current.t+1;
            if(s.x < 0||s.x > MAX||s.y < 0||s.y > MAX)
                continue;
            if(map[s.x][s.y] == -1)
                return s.t;
            if(s.t >= map[s.x][s.y])
                continue;
            map[s.x][s.y] = s.t;
            q.push(s);
        }
    }
    return -1;
}

void in()
{
    memset(map,-1,sizeof(map));
    scanf("%d",&n);
    while(n--){
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        for (int i = 0; i < 5; i += 1)
        {
            int x1 = x+dir[i][0];
            int y1 = y+dir[i][1];
            if(x1 < 0||x1 >= MAX||y1 < 0||y1 >= MAX)
                continue;
            if(map[x1][y1] == -1)
                map[x1][y1] = t;
            else   map[x1][y1] = min(map[x1][y1],t);
        }
    }
}

int main()
{
    in();
    printf("%d\n",bfs());
    return 0;
}