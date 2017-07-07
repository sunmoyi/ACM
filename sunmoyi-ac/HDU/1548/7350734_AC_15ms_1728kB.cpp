//
// Created by 孙启龙 on 2016/10/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int N, A, B;
int a[205];
bool map[205], flag;

struct node{
    int x, step;
}n1, n2, m;

int bfs()
{
    n1.x = A, n1.step = 0;
    queue<node>Q;
    Q.push(n1);
    while(!Q.empty())
    {
        m = Q.front();
        Q.pop();
        if(m.x == B)
        {
            flag = true;
            return m.step;
        }
        n1.x = m.x - a[m.x];
        n2.x = m.x + a[m.x];
        if(n1.x > 0 && n1.x <= B && !map[n1.x])
        {
            n1.step = m.step + 1;
            map[n1.x] = true;
            Q.push(n1);
        }
        if(n2.x > 0 && n2.x <= B && !map[n2.x])
        {
            n2.step = m.step + 1;
            map[n2.x] = true;
            Q.push(n2);
        }
    }
    return -1;
}

int main (void)
{
    while(scanf("%d", &N) != EOF && N)
    {
        scanf("%d %d", &A, &B);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &a[i]);
            map[i] = false;
        }
        flag = false;
        int a = bfs();
        printf("%d\n", a);
    }
    return 0;
}