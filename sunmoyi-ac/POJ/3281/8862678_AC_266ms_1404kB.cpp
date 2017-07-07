//
// Created by 孙启龙 on 2017/4/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 510
#define INF 0x3f3f3f3f

using namespace std;

int g[maxn][maxn];
int path[maxn], flow[maxn], start, endd;
int n;

queue<int>q;
int bfs()
{
    int i,t;
    while(!q.empty())q.pop();//把清空队列
    memset(path,-1,sizeof(path));//每次搜索前都把路径初始化成-1
    path[start]=0;
    flow[start]=INF;//源点可以有无穷的流流进
    q.push(start);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t==endd)break;
        //枚举所有的点，如果点的编号起始点有变化可以改这里
        for(i=0;i<=n;i++)
        {
            if(i!=start&&path[i]==-1&&g[t][i])
            {
                flow[i]=flow[t]<g[t][i]?flow[t]:g[t][i];
                q.push(i);
                path[i]=t;
            }
        }
    }
    if(path[endd]==-1)return -1;//即找不到汇点上去了。找不到增广路径了
    return flow[endd];
}

int Edmonds_Karp()
{
    int max_flow=0;
    int step,now,pre;
    while((step=bfs())!=-1)
    {
        max_flow+=step;
        now=endd;
        while(now!=start)
        {
            pre=path[now];
            g[pre][now]-=step;
            g[now][pre]+=step;
            now=pre;
        }
    }
    return max_flow;
}

int main (void)
{
    int N, F, D;
    while(scanf("%d %d %d", &N, &F, &D) != EOF)
    {
        n = F + D + 2 * N + 1;
        start = 0;
        endd = n;
        for (int i = 1; i <= F; i++)
            g[0][i] = 1;
        for (int i = F + 2 * N + 1; i <= F + 2 * N + D; i++)
            g[i][n] = 1;
        for(int i = 1; i <= N; i++)
            g[F + 2 * i - 1][F + 2 * i] = 1;
        int k1, k2;
        int u;
        for(int i = 1; i <= N; i++)
        {
            scanf("%d %d", &k1, &k2);
            while(k1--)
            {
                scanf("%d", &u);
                g[u][F + 2 * i - 1] = 1;
            }
            while(k2--)
            {
                scanf("%d", &u);
                g[F + 2 * i][F + 2 * N + u] = 1;
            }
        }
        printf("%d\n", Edmonds_Karp());
    }
    return 0;
}