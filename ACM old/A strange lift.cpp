//
// Created by 孙启龙 on 16/10/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 210

using namespace std;

int N, A, B;
int a[maxn];
bool map[maxn];

struct node{
    int x, step;
};

void bfs(int s)
{
    node now, next1, next2;
    now.x = s, now.step = 0;
    queue<node>Q;
    Q.push(now);
    map[now.x] = true;
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if(now.x == B)
        {
            printf("%d\n", now.step);
            return;
        }
        next1.x = now.x - a[now.x], next1.step = now.step + 1;
        next2.x = now.x + a[now.x], next2.step = now.step + 1;
        if(next1.x > 0 && next1.x <= B && !map[next1.x])
        {
            map[next1.x] = true;
            Q.push(next1);
        }
        if(next2.x > 0 && next2.x <= B && !map[next2.x])
        {
            map[next2.x] = true;
            Q.push(next2);
        }
    }
    printf("-1\n");
    return ;
}

int main (void)
{
    while(scanf("%d", &N) && N)
    {
        scanf("%d %d", &A, &B);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &a[i]);
            map[i] = false;
        }
        bfs(A);
    }
}