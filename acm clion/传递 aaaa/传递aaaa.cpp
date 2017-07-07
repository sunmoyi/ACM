//
// Created by 孙启龙 on 2016/11/7.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

char p[2500];
vector<int>G1[2500];
vector<int>G2[2500];
int vis[2500];
int level[2500];
queue<int>Q;

int bfs(int root, vector<int> G[])
{
    Q.push(root);
    level[root]=1;
    vis[root]=1;
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for(int i = 0; i < G[now].size(); i++)
        {
            if(vis[G[now][i]] == 0)
            {
                vis[G[now][i]] = 1;
                level[G[now][i]] = level[now] + 1;
                if(level[G[now][i]] >= 3)
                {
                    return 0;
                }
                Q.push(G[now][i]);
            }
        }
    }
    return 1;
}

int main(void)
{
    int Cas;
    scanf("%d", &Cas);
    while(Cas--)
    {
        for(int i = 0;i < 2500; i++)
        {
            G1[i].clear();
            G2[i].clear();
        }
        int n;
        scanf("%d", &n);
        for(int i = 1;i <= n; i++)
        {
            scanf("%s", p);
            for(int j = 0;j < n;j++)
            {
                if(p[j] == 'P')
                {
                    G1[i].push_back(j + 1);
                }
                if(p[j] == 'Q')
                {
                    G2[i].push_back(j + 1);
                }
            }
        }

        int flag1 = 1, flag2 = 1;
        for(int i = 1;i <= n; i++)
        {
            memset(level, 0, sizeof(level));
            memset(vis, 0, sizeof(vis));
            if(!bfs(i, G1))
            {
                flag1 = 0;
                break;
            }
        }
        if(!flag1)
        {
            printf("N\n");
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            memset(level, 0, sizeof(level));
            memset(vis, 0, sizeof(vis));
            if(!bfs(i, G2))
            {
                flag2 = 0;
                break;
            }
        }
        if(!flag2)
        {
            printf("N\n");
            continue;
        }

        printf("T\n");
    }
    return 0;
}