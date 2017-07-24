//
// Created by 孙启龙 on 2017/5/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 100010

using namespace std;

struct node{
    int pos, nextpos;
    node(int pos = 0, int nextpos = 0):pos(pos), nextpos(nextpos){}
};
vector<node>G[maxn];
bool inqueue[maxn];
long long mindist[maxn];
int n, m;

void spfa()
{
    queue<int>Q;
    memset(inqueue, false, sizeof(inqueue));
    for(int i = 1; i <= n; i++)
        Q.push(i), inqueue[i] = true;
    while(!Q.empty())
    {
        int now = Q.front(), next;
        Q.pop();
        inqueue[now] = false;
        for(int i = 0; i < G[now].size(); i++)
        {
            next = G[now][i].pos;
            if(mindist[next] > mindist[now] + mindist[G[now][i].nextpos])
            {
                mindist[next] = mindist[now] + mindist[G[now][i].nextpos];
                if(!inqueue[next])
                {
                    inqueue[next] = true;
                    Q.push(next);
                }
            }
        }
    }
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &mindist[i]), G[i].clear();
        for(int i = 1; i <= m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            G[a].push_back(node(c, b));
            G[b].push_back(node(c, a));
        }

        spfa();

        for(int i = 1; i < n; i++)
            printf("%lld ", mindist[i]);
        printf("%lld\n", mindist[n]);
    }
    return 0;
}