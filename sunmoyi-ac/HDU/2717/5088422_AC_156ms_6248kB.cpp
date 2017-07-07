#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int vis[1000000];
int flag, start, endd;
struct k{
    int x;
    int countt;
};

int bfs()
{
    memset(vis, 0, sizeof(vis));
    queue <k>q;
    k now, next;
    now.countt = 0;
    now.x = start;
    q.push(now);
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (now.x == endd)
            return now.countt;
        if (now.x < 0 || now.x > 1000000)
            continue;
        if (vis[now.x] == 1)
            continue;
        vis[start] = 1;
        vis[now.x] = 1;
        next.x = now.x - 1;
        next.countt = now.countt + 1;
        q.push(next);
        next.x = now.x + 1;
        next.countt = now.countt + 1;
        q.push(next);
        next.x = now.x * 2;
        next.countt = now.countt + 1;
        q.push(next);
    }
}

int main(void)
{
    while (scanf("%d %d", &start, &endd) != EOF)
    {
        int cnt;
        cnt = bfs();
        printf("%d\n", cnt);
    }
    return 0;
}